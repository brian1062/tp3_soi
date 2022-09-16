#include <stdio.h>
#include "../library/cJSON.h"

void fileSysInf(void){
    char t1[10],t2[15];
    cJSON *inicio=cJSON_CreateObject();
    cJSON *Fsys=NULL;
    cJSON_AddItemToObject(inicio,"filesystems",Fsys=cJSON_CreateObject());
    FILE *file;
    file = fopen("/proc/filesystems","r");
    while (fscanf(file,"%s %s", t1, t2)!=EOF) {
        cJSON_AddStringToObject(Fsys, t1,t2);
    }
    fclose(file);

    char *c=NULL;
    c = cJSON_Print(inicio);
    printf("%s",c);
    cJSON_Delete(inicio);
}