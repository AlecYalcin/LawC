#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
// Created Modules
#include "../modules/schedule.h"
#include "../database/data_utils.h"

// Atualização (Create) de Arquivos
void sc_create_archive(char *ar_name, Schedule *schedule) {
    FILE *fp;

    fp = fopen(ar_name, "ab");

    if (!(fp == NULL)) {
        fwrite(schedule, sizeof(Schedule), 1, fp);
        printf("\n>>> Adicionando informacao... <<<\n");
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }
}

// Leitura (Read) de Arquivos
Schedule* sc_read_archive(char *ar_name, char *filter) {
    FILE *fp;
    Schedule* sche_aux = (Schedule*) malloc(sizeof(Schedule));

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {

        while(!feof(fp)) {
            // Lendo o Arquivo
            fread(sche_aux, sizeof(Schedule), 1, fp);
            // Comparando as Strings
            if (strcmp(sche_aux->name, filter) == 0 && sche_aux->status != 0) {
                fclose(fp);

                printf("\n>>> Agendamento encontrado! <<<\n");
                return sche_aux;
            }
        }

        printf("\n>>> Agendamento não encontrado. \n");
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }

    free(sche_aux);
    return NULL;
}