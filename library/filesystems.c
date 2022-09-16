#include <stdio.h>
#include <dlfcn.h>
#include <unistd.h>
#include "../library/cJSON.h"

void fileSysInf(){
    char t1[10],t2[15];
    cJSON *inicio=cJSON_CreateObject();
    cJSON *fSys;
    cJSON_AddItemToObject(inicio,"filesystems",fSys=cJSON_CreateObject());
    FILE *file;
    file = fopen("/proc/filesystems","r");
    while (fscanf(file,"%s %s", t1, t2)!=EOF) {
        cJSON_AddStringToObject(fSys, t1,t2);
    }
    fclose(file);

    char *c=NULL;
    c = cJSON_Print(inicio);
    printf("%s",c);
    cJSON_Delete(inicio);
    return;
}