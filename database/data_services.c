#include <stdio.h> 
#include <stdlib.h>
// Created Modules
#include "../modules/services.h"

// Criação/Reset de Arquivos
void create_archive(char* ar_name) {
    FILE *fp;

    fp = fopen(ar_name, "wb");
    
    if (!(fp == NULL)) {
        printf("\n>>> Criou o arquivo, nome do arquivo: '%s'.\n", ar_name);
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação\n");
    }
}

// Leitura (Read) de Arquivos
void read_archive(char *ar_name, Service *al) {
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
void update_archive(char *ar_name, Service *al) { 
    FILE *fp;

    fp = fopen(ar_name, "ab");

    if (!(fp == NULL)) {
        fwrite(al, sizeof(Service), 1, fp);
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo!\n");
    }
}