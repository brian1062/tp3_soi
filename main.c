#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "library/utils.h"

int main(int argc, char const *argv[])
{   
    //creo marcas para saber que argumento ingreso
    int isS=0; //marca pasa saber si paso argumento -s lab2 ej 1
    int isA=0; //marca pasa saber si paso argumento -a lab2 ej 2
    int isJ=0; //marca pasa saber si paso argumento -j
    int isD=0; //marca pasa saber si paso argumento -d

    for(int i=1;i<argc;i++){
        if(strcmp(argv[i],"-s")==0){
            isS++;
        }
        if(strcmp(argv[i],"-a")==0){
            isA++;
        }
        if(strcmp(argv[i],"-j")==0){
            isJ++;
        }
        if(strcmp(argv[i],"-d")==0){
            isD++;
        }
    }
    if(isS>=1){
        lab2_punto1(isJ);
        isS--;
    }
    if(isA>=1){
        lab2_punto2(isJ);
        isA--;
    }
    if(isJ>=1){isJ--;}
    if(isD>=1){
        void* fsys= dlopen("libfsys.so",RTLD_LAZY);
        void (*fileSysInf)();
        if(fsys==NULL){
            fprintf(stderr,"%s",dlerror());
            exit(EXIT_FAILURE);
        }
        //basado en el ejemplo del man dlopen
        *(void **) (&fileSysInf) = dlsym(fsys, "fileSysInf");
        (*fileSysInf)();
        dlclose(fsys);
    }

    return 0;
}
