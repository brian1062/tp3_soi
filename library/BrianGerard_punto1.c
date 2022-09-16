/*#include "../library/utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../library/cJSON.h"*/
//#include "BrianGerard_punto1.h"
#include "utils.h"

void lab2_punto1(int isJ)
//int main(void)
{
        FILE *file, *file2;
        int tamanio;
        char nombre[16];
        //datos mem
        int memTot,memFree,memAv,swpCach;

        char modeloCpu[36], buffer[64];
        int hilos, cores;
        char *token,caracter;

        file = fopen("/proc/meminfo", "r");
        // mejorado
        while (fscanf(file, "%s %d %*s", nombre, &tamanio))
        {
                if (!strcmp(nombre, "MemTotal:"))
                {memTot=tamanio;}
                else if (!strcmp(nombre, "MemFree:"))
                {memFree=tamanio;}
                else if (!strcmp(nombre, "MemAvailable:"))
                {memAv=tamanio;}
                else if (!strcmp(nombre, "SwapCached:"))
                {
                        swpCach=tamanio;
                        break;
                }
        }
        fclose(file);
        
        file2 = fopen("/proc/cpuinfo", "r");
        while (!feof(file2))
        {
                fgets(buffer, 64, file2);
                if (strstr(buffer, "model name") != NULL)
                {                                    // si hay concordancia
                        token = strtok(buffer, ":"); // se fija si hay un :
                        while (token != NULL)
                        {
                                if (strstr(token, "model name") == NULL)
                                {                                 // model name : algo
                                        strcpy(modeloCpu, token); // guardo los datos de la cpu en modeloCpu
                                }
                                token = strtok(NULL, ":");
                        }
                }
                if (strstr(buffer, "siblings") != NULL)
                { // para los hilos se hace lo mismo
                        token = strtok(buffer, ":");
                        while (token != NULL)
                        {
                                if (atoi(token) < 20)
                                {
                                        hilos = atoi(token); // paso los hilos a int
                                }
                                token = strtok(NULL, ":");
                        }
                }
                if (strstr(buffer, "cpu cores") != NULL)
                {
                        token = strtok(buffer, ":");
                        while (token != NULL)
                        {
                                if (atoi(token) < 20)
                                {
                                        cores = atoi(token);
                                }
                                token = strtok(NULL, ":");
                        }
                        break;
                }
                while ((caracter = fgetc(file2)) != '\n')
                {
                }
        }
        fclose(file2);
        //int isJ=0;
        if (isJ == 0)
        {
                printf("Informacion de la RAM: \n");

                    printf("MemTotal:      %d MegaBytes\n", memTot / 1024);
                    printf("MemFree:       %d MegaBytes\n", memFree / 1024);
                    printf("MemAvailable:  %d MegaBytes\n", memAv / 1024);
                    printf("SwapCached:    %d MegaBytes\n", swpCach / 1024);

                printf("\nInformacion de la CPU: \n");
                    printf("Cpu model: %s", modeloCpu);
                    printf("Threads: %d\n", hilos);
                    printf("Cpu cores: %d\n", cores);
        }else if(isJ>=1){
            //cJSON *name = NULL;
            cJSON *memInfo=NULL;
            cJSON *cpuInfo=NULL;
            cJSON *act1=NULL;
            cJSON *lab2_act1 = cJSON_CreateObject();


            cJSON_AddItemToObject(lab2_act1, "Laboratorio_2_actividad_1", act1 = cJSON_CreateObject());

            cJSON_AddItemToObject(act1,"memInfo",memInfo =cJSON_CreateObject());

            cJSON_AddNumberToObject(memInfo,"MemTotal",memTot / 1024);
            cJSON_AddNumberToObject(memInfo,"MemFree",memFree / 1024);
            cJSON_AddNumberToObject(memInfo,"MemAvailable",memAv / 1024);
            cJSON_AddNumberToObject(memInfo,"SwapCached",swpCach / 1024);

            cJSON_AddItemToObject(act1,"cpuInfo",cpuInfo =cJSON_CreateObject());

            cJSON_AddStringToObject(cpuInfo,"Cpu_model" ,modeloCpu);
            cJSON_AddNumberToObject(cpuInfo,"Threads",hilos);
            cJSON_AddNumberToObject(cpuInfo,"Cpu_cores",cores);

            char *c=NULL;
            c = cJSON_Print(lab2_act1);
            printf("%s",c);
            cJSON_Delete(lab2_act1);
        }
}
