# PS5 port contributions and enhancements: Youss Riaal, 2026.
# SPDX-License-Identifier: GPL-3.0-only
# Applies to original contributions only; see COPYRIGHT.md and NOTICE.md.
from pathlib import Path
import subprocess,sys,shutil,json,os,tarfile,urllib.request
from concurrent.futures import ThreadPoolExecutor
base=Path(__file__).resolve().parent;tools=Path(os.environ.get('FW_TOOLS','tools')).resolve();llvm=Path(os.environ['LLVM_BIN']);sdk=Path(os.environ['PS5_PAYLOAD_SDK']);hb=Path(os.environ['PS5_HBROOT']);vendor=base/'vendor/ps5-native-tool/tooling/native'
exe='.exe' if os.name=='nt' else ''
def pick(env,*names):
 if os.environ.get(env):return Path(os.environ[env])
 for n in names:
  if (llvm/(n+exe)).exists():return llvm/(n+exe)
 return llvm/(names[-1]+exe)
cc=pick('FW_CLANG','clang-23','clang-18','clang');lld=pick('FW_LLD','ld.lld-18','ld.lld');hcc=pick('FW_HOST_CC','clang');hcxx=pick('FW_HOST_CXX','clang++')
# Pinned ps5-payload-dev/SDL source, needed only for the headers of the modified video driver.
SDL_COMMIT='160954cf9833f39197431225f73a3cf737b95d5a'
def sdl_source():
 if os.environ.get('PS5_SDL_SRC'):return Path(os.environ['PS5_SDL_SRC'])
 dest=base/'build-cache'/('SDL-'+SDL_COMMIT[:7])
 if not (dest/'src/SDL_internal.h').exists():
  dest.mkdir(parents=True,exist_ok=True);archive=dest.parent/'sdl.tar.gz'
  print('Downloading ps5-payload-dev/SDL '+SDL_COMMIT[:7],flush=True)
  urllib.request.urlretrieve('https://github.com/ps5-payload-dev/SDL/archive/'+SDL_COMMIT+'.tar.gz',archive)
  with tarfile.open(archive) as tf:
   for m in tf.getmembers():
    parts=m.name.split('/',1)
    if len(parts)<2 or not parts[1] or m.issym() or m.islnk() or '..' in parts[1].split('/'):continue
    m.name=parts[1];tf.extract(m,dest)
  archive.unlink()
 return dest
(base/'host').mkdir(exist_ok=True);(base/'obj').mkdir(exist_ok=True)
def run(cmd):
 r=subprocess.run([str(x)for x in cmd],stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True)
 if r.stdout.strip():print(r.stdout,flush=True)
 if r.returncode:raise RuntimeError('Command failed: '+str(cmd[0]))
def host_tools():
 z=tools/'zlib-1.3.1';zobjects=[]
 for name in 'adler32 crc32 deflate inflate infback inffast inftrees trees zutil compress uncompr'.split():
  out=base/'host'/(name+'.o');zobjects.append(out)
  if not out.exists():run([hcc,'-O2','-I'+str(z),'-c',z/(name+'.c'),'-o',out])
 tool_exe=base/('host/ps5-native-tool'+exe)
 if not tool_exe.exists():
  objs=[]
  for name in ['native_app_builder','self_container','elf_object','sce_module_writer']:
   out=base/'host'/(name+'.o');objs.append(out)
   run([hcxx,'-std=c++20','-O2','-I'+str(z),'-c',vendor/(name+'.cpp'),'-o',out])
  run([hcxx]+(['-static'] if os.name=='nt' else [])+['-o',tool_exe]+objs+zobjects)
 return tool_exe
tool=host_tools()
if '--host-only' in sys.argv:sys.exit(0)
src=base/'src'
common=[cc,'--no-default-config','-target','x86_64-sie-ps5','-std=c++17','-O2','-DFW_PS5=1','-DFW_NATIVE_TITLE=1','-fexceptions','-fcxx-exceptions','-fno-stack-protector','-fno-plt','-femulated-tls','-fvisibility-nodllstorageclass=default','-ffunction-sections','-fdata-sections','-isysroot',sdk,'-nostdinc++','-isystem',sdk/'target/include/c++/v1','-isystem',sdk/'target/include','-idirafter',hb/'include','-I'+str(hb/'include/SDL2')]
common+=['-DSTBI_NO_THREAD_LOCALS','-DNDEBUG']
objects=[]
for source in [vendor/'app_crt.cpp',src/'main.cpp',base/'vendor/ps5_compat.cpp',base/'native_shims.cpp']:
 out=base/'obj'/(source.stem+'.o');objects.append(out);run(common+['-c',source,'-o',out])
# Modified SDL PS5 video driver (4K output); overrides the one in libSDL2.a.
sdl=sdl_source();video=base/'obj/SDL_ps5video.o'
run([cc,'--no-default-config','--target=x86_64-sie-ps5','-O2','-fno-stack-protector','-fno-plt','-ffunction-sections','-fdata-sections','-isysroot',sdk,'-isystem',sdk/'target/include','-I'+str(hb/'include/SDL2'),'-I'+str(sdl/'src'),'-c',base/'vendor/sdl-ps5video/SDL_ps5video.c','-o',video])
objects.append(video)
wrap='sceKeyboardInit sceKeyboardOpen sceKeyboardReadState sceKeyboardClose sceImeDialogGetStatus malloc free calloc realloc posix_memalign'.split()
pie=base/'llvm-pie.elf'
cmd=[lld,'-m','elf_x86_64','-pie','-T',vendor/'ps5-pie.ld','--eh-frame-hdr','-z','max-page-size=0x4000','--hash-style=gnu','--gc-sections','--version-script',vendor/'app-symbols.map','-e','_start','-o',pie]+objects+['--wrap='+n for n in wrap]+['-L'+str(hb/'lib'),'-L'+str(sdk/'target/lib'),'--start-group','-lSDL2','-lsamplerate','-lexpat','-liconv','-lc++','-lc++abi','-lunwind','--end-group','--as-needed']+list((sdk/'target/lib').glob('*.so'))
run(cmd)
run([tool,'link','--in',pie,'--out',base/'eboot.elf','--stub-dir',sdk/'target/lib','--module-sdk','0x02000009','--companion-sdk','0x08050001','--file-name','eboot.elf'])
title=base/'FWRG00001';(title/'sce_sys').mkdir(parents=True,exist_ok=True);(title/'sce_module').mkdir(exist_ok=True)
run([tool,'self','--sign','--in',base/'eboot.elf','--out',title/'eboot.bin','--magic','0x1D3D154F'])
shutil.copyfile(base/'sce_sys/icon0.png',title/'sce_sys/icon0.png');shutil.copytree(base/'assets',title/'assets',dirs_exist_ok=True);shutil.copyfile(base/'runtime/libc.prx',title/'sce_module/libc.prx')
param=json.loads((base/'sce_sys/param.json').read_text())
(title/'sce_sys/param.json').write_text(json.dumps(param,indent=2)+'\n')
for doc in ['LICENSE','COPYRIGHT.md','NOTICE.md']:shutil.copyfile(base/doc,title/doc)
shutil.copyfile(base/'README.md',title/'README.txt')
if '--zip' in sys.argv:
 import zipfile
 out=base/('FWRG00001-v'+'.'.join(str(int(x)) for x in param['contentVersion'].split('.'))+'.zip')
 with zipfile.ZipFile(out,'w',zipfile.ZIP_DEFLATED) as z:
  for f in sorted(title.rglob('*')):
   if f.is_file():z.write(f,f.relative_to(base).as_posix())
 print('Packaged '+str(out),flush=True)
print('Built native title folder '+str(title),flush=True)
