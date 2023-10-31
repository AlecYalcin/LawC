#include <stdio.h> 
#include <stdlib.h>
// Created Modules
#include "../modules/services.h"

// Leitura (Read) de Arquivos
void s_read_archive(char *ar_name, Service *al) {
    FILE *fp;

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {
        fread(al, sizeof(Service), 1, fp);
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo!\n");
    }
}

// Atualização (Update) de Arquivos
void s_update_archive(char *ar_name, Service *al) { 
    FILE *fp;

    fp = fopen(ar_name, "ab");

    if (!(fp == NULL)) {
        fwrite(al, sizeof(Service), 1, fp);
        printf("\n>>> Adicionando informacao...\n");
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo!\n");
    }
}