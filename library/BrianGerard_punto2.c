#include "utils.h"

void lab2_punto2(int isJ)
//int main(void)
{
    
    int initialSize=1;
    int usedSize=0;
    char letra;
    FILE *file;
    file = fopen("/proc/version","r");
    char *dinamicalArray = NULL;
    dinamicalArray = (char*) malloc(sizeof(char)*initialSize);
    
    //Compruebo q el archivo se puedo abrir
    if (file==NULL){printf("Error al abrir /proc/version");}
    //Extraigo del file su informacion
    else{
        while((letra=fgetc(file))!=EOF){
            if(usedSize==initialSize){
                initialSize+=2;
                dinamicalArray=realloc(dinamicalArray,sizeof(char)*initialSize);
            }
            dinamicalArray[usedSize]=letra;
            usedSize++;
        }
    }
    //Imprimo caracteres pasados a mayusculas
    for(int i=0;dinamicalArray[i] != '\0';i++){
        dinamicalArray[i] = toupper(dinamicalArray[i]);
    }
    if (isJ==0){
        for (int i = 0; dinamicalArray[i] != '\0'; ++i) {
            printf("%c",dinamicalArray[i]);
        }
    }else if(isJ>=1){
        cJSON *lab2_act2 = cJSON_CreateObject();
        cJSON *act2=NULL;

        cJSON_AddItemToObject(lab2_act2, "Laboratorio_2_actividad_2", act2 = cJSON_CreateArray());

        cJSON_AddItemToArray(act2, cJSON_CreateString(&dinamicalArray[0]));
        char *c=NULL;
        c = cJSON_Print(lab2_act2);
        printf("%s",c);
        cJSON_Delete(lab2_act2);
    }


    //cierro el archivo y libero memoria
    fclose(file);
    free(dinamicalArray);
}