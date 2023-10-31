#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
// Created Modules
#include "../modules/employers.h"

// Leitura (Read) de Arquivos
Employer* e_read_archive(Employer *funcionario, char *ar_name, char *filter) {
    FILE *fp;

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {
        while(!feof(fp)) {
            fread(funcionario, sizeof(Employer), 1, fp);
            if (!(strcmp(funcionario->cpf, filter))) {
                fclose(fp);
                return funcionario;
            }
        }
        printf("\n>>> Funcionario nao encontrado. \n");

        fclose(fp);
        return funcionario;
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