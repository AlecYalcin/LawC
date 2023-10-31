#include <stdio.h> 
#include <stdlib.h>
// Created Modules
#include "../modules/employers.h"

// Leitura (Read) de Arquivos
void e_read_archive(char *ar_name, Employer *al) {
    FILE *fp;

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {
        fread(al, sizeof(Employer), 1, fp);
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo!\n");
    }
}

// Atualização (Update) de Arquivos
void e_update_archive(char *ar_name, Employer *al) { 
    FILE *fp;

    fp = fopen(ar_name, "ab");

    if (!(fp == NULL)) {
        fwrite(al, sizeof(Employer), 1, fp);
        printf("\n>>> Adicionando informacao...\n");
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo!\n");
    }
}