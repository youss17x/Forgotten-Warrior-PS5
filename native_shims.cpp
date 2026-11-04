#include <cstdio>
#include <cstdlib>
#include <unistd.h>
extern "C" int sceSystemServiceLoadExec(const char*,char**);
extern "C" void catchReturnFromMain(int status){
 fprintf(stderr,"Native title closing through system service: %d\n",status);fflush(nullptr);
 sceSystemServiceLoadExec("exit",nullptr);
 for(;;)usleep(100000);
}
extern "C" [[noreturn]] void __assert(const char*function,const char*file,int line,const char*condition){
 fprintf(stderr,"Assertion failed: %s (%s:%d %s)\n",condition,file,line,function);abort();
}
