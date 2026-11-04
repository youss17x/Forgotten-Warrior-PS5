from pathlib import Path
import subprocess,sys,shutil,json,os
from concurrent.futures import ThreadPoolExecutor
base=Path(__file__).resolve().parent;tools=Path(os.environ.get('FW_TOOLS','tools')).resolve();llvm=Path(os.environ['LLVM_BIN']);sdk=Path(os.environ['PS5_PAYLOAD_SDK']);hb=Path(os.environ['PS5_HBROOT']);vendor=base/'vendor/ps5-native-tool/tooling/native'
(base/'host').mkdir(exist_ok=True);(base/'obj').mkdir(exist_ok=True)
def run(cmd):
 r=subprocess.run([str(x)for x in cmd],stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True)
 if r.stdout.strip():print(r.stdout,flush=True)
 if r.returncode:raise RuntimeError('Command failed: '+str(cmd[0]))
def host_tools():
 z=tools/'zlib-1.3.1';zobjects=[]
 for name in 'adler32 crc32 deflate inflate infback inffast inftrees trees zutil compress uncompr'.split():
  out=base/'host'/(name+'.o');zobjects.append(out)
  if not out.exists():run([llvm/'clang.exe','-O2','-I'+str(z),'-c',z/(name+'.c'),'-o',out])
 exe=base/'host/ps5-native-tool.exe'
 if not exe.exists():
  objs=[]
  for name in ['native_app_builder','self_container','elf_object','sce_module_writer']:
   out=base/'host'/(name+'.o');objs.append(out)
   run([llvm/'clang++.exe','-std=c++20','-O2','-I'+str(z),'-c',vendor/(name+'.cpp'),'-o',out])
  run([llvm/'clang++.exe','-static','-o',exe]+objs+zobjects)
 return exe
tool=host_tools()
if '--host-only' in sys.argv:sys.exit(0)
src=base/'src'
common=[llvm/'clang-23.exe','--no-default-config','-target','x86_64-sie-ps5','-std=c++17','-O2','-DFW_PS5=1','-DFW_NATIVE_TITLE=1','-fexceptions','-fcxx-exceptions','-fno-stack-protector','-fno-plt','-femulated-tls','-fvisibility-nodllstorageclass=default','-ffunction-sections','-fdata-sections','-isysroot',sdk,'-nostdinc++','-isystem',sdk/'target/include/c++/v1','-isystem',sdk/'target/include','-idirafter',hb/'include','-I'+str(hb/'include/SDL2')]
common+=['-DSTBI_NO_THREAD_LOCALS','-DNDEBUG']
objects=[]
for source in [vendor/'app_crt.cpp',src/'main.cpp',base/'vendor/ps5_compat.cpp',base/'native_shims.cpp']:
 out=base/'obj'/(source.stem+'.o');objects.append(out);run(common+['-c',source,'-o',out])
wrap='sceKeyboardInit sceKeyboardOpen sceKeyboardReadState sceKeyboardClose sceImeDialogGetStatus malloc free calloc realloc posix_memalign'.split()
pie=base/'llvm-pie.elf'
cmd=[llvm/'ld.lld.exe','-m','elf_x86_64','-pie','-T',vendor/'ps5-pie.ld','--eh-frame-hdr','-z','max-page-size=0x4000','--hash-style=gnu','--gc-sections','--version-script',vendor/'app-symbols.map','-e','_start','-o',pie]+objects+['--wrap='+n for n in wrap]+['-L'+str(hb/'lib'),'-L'+str(sdk/'target/lib'),'--start-group','-lSDL2','-lsamplerate','-lexpat','-liconv','-lc++','-lc++abi','-lunwind','--end-group','--as-needed']+list((sdk/'target/lib').glob('*.so'))
run(cmd)
run([tool,'link','--in',pie,'--out',base/'eboot.elf','--stub-dir',sdk/'target/lib','--module-sdk','0x02000009','--companion-sdk','0x08050001','--file-name','eboot.elf'])
title=base/'FWRG00001';(title/'sce_sys').mkdir(parents=True,exist_ok=True);(title/'sce_module').mkdir(exist_ok=True)
run([tool,'self','--sign','--in',base/'eboot.elf','--out',title/'eboot.bin','--magic','0x1D3D154F'])
shutil.copyfile(base/'icon0.png',title/'sce_sys/icon0.png');shutil.copytree(base/'assets',title/'assets',dirs_exist_ok=True);shutil.copyfile(base/'runtime/libc.prx',title/'sce_module/libc.prx')
param={'titleId':'FWRG00001','conceptId':'09991','contentId':'IV9999-FWRG00001_00-FORGOTTENWARRIOR','contentVersion':'01.001.000','masterVersion':'01.00','applicationCategoryType':0,'contentBadgeType':1,'applicationDrmType':'free','downloadDataSize':256,'localizedParameters':{'defaultLanguage':'en-US','en-US':{'titleName':'Forgotten Warrior Remastered'}},'kernel':{'flexibleMemorySize':268435456}}
(title/'sce_sys/param.json').write_text(json.dumps(param,indent=2)+'\n')
print('Built native title folder '+str(title),flush=True)
