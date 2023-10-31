#include <stdio.h> 
#include <stdlib.h>
// Created Modules
#include "../modules/clients.h"

// Leitura (Read) de Arquivos
void sc_read_archive(char *ar_name, Cliente *al) {
    FILE *fp;

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {
        fread(al, sizeof(Cliente), 1, fp);
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo!\n");
    }
}

// Atualização (Update) de Arquivos
void sc_update_archive(char *ar_name, Cliente *al) { 
    FILE *fp;

    fp = fopen(ar_name, "ab");

    if (!(fp == NULL)) {
        fwrite(al, sizeof(Cliente), 1, fp);
        printf("\n>>> Adicionando informacao...\n");
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo!\n");
    }
}