#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
// Created Modules
#include "../modules/resources.h"

// Leitura (Read) de Arquivos
Resource* r_read_archive(Resource *recurso, char *ar_name, char *filter) {
    FILE *fp;

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {
        while(!feof(fp)) {
            fread(recurso, sizeof(Resource), 1, fp);
            if (!(strcmp(recurso->name, filter))) {
                fclose(fp);
                return recurso;
            }
        }

        fclose(fp);
        return recurso;
    } else {
        printf("\n>>> Erro na criação do arquivo!\n");
    }
}

// Atualização (Update) de Arquivos
void r_update_archive(char *ar_name, Resource *recurso) { 
    FILE *fp;

    fp = fopen(ar_name, "ab");

    if (!(fp == NULL)) {
        fwrite(recurso, sizeof(Resource), 1, fp);
        printf("\n>>> Adicionando informacao...\n");
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo!\n");
    }
}