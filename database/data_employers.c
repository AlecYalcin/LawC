#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
// Created Modules
#include "../modules/employers.h"

// Leitura (Read) de Arquivos
Employer* e_read_archive(char *ar_name, char *filter) {
    FILE *fp;
    Employer* emp_aux = (Employer*) malloc(sizeof(Employer));

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {

        while(!feof(fp)) {
            printf("\n !> Filtro: %s", filter);
            fread(emp_aux, sizeof(Employer), 1, fp);

            printf("\n\n >>> Emp_aux: %s, CPF: %s", emp_aux->cpf, filter);
            printf("\n      -> Comparação: %s", filter);

            if (!(strcmp(emp_aux->cpf, filter))) {
                return emp_aux;
                fclose(fp);
            }
        }

        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo!\n");
    }

    free(emp_aux);
    return NULL;
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