#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
// Created Modules
#include "../modules/clients.h"

// Leitura (Read) de Arquivos
Cliente* c_read_archive(Cliente *cliente, char *ar_name, char *filter) {
    FILE *fp;

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {
        while(!feof(fp)) {
            fread(cliente, sizeof(Cliente), 1, fp);
            if (!(strcmp(cliente->cpf, filter))) {
                fclose(fp);
                return cliente;
            }
        }

        fclose(fp);
        return cliente;
    } else {
        printf("\n>>> Erro na criação do arquivo!\n");
    }
}

// Atualização (Update) de Arquivos
void c_update_archive(char *ar_name, Cliente *al) { 
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