#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
// Created Modules
#include "../modules/employers.h"

// Atualização (Create) de Arquivos
void e_create_archive(char *ar_name, Employer *al) { 
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

// Leitura (Read) de Arquivos
Employer* e_read_archive(char *ar_name, char *filter) {
    FILE *fp;
    Employer* emp_aux = (Employer*) malloc(sizeof(Employer));

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {

        while(!feof(fp)) {
            // Lendo o Arquivo
            fread(emp_aux, sizeof(Employer), 1, fp);
            // Comparando as Strings
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

// Alteração (Update) de Arquivos
void e_update_archive(char *ar_name, char *filter, Employer* new_funcionario) {
    FILE *fp;
    Employer* emp_aux = (Employer*) malloc(sizeof(Employer));

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {

        while(!feof(fp)) {
            // Lendo o Arquivo
            fread(emp_aux, sizeof(Employer), 1, fp);
            // Comparando as Strings
            if (!(strcmp(emp_aux->cpf, filter))) {
                printf("\n      -> Apontador Antes: %p", fp);
                // Após encontrar, alterar a localização do ponteiro
                long pos = -1L;
                fseek(fp, pos * sizeof(Employer), SEEK_CUR);
                printf("\n      -> Apontador Depois: %p", fp);
                // Tendo reposicionado o ponteiro, atualizar.
                printf("\nCPF: %s", new_funcionario->cpf);
                fwrite(new_funcionario, sizeof(Employer), 1, fp);
                
                printf("\n>>> Funcionário alterado!\n");
                break;
            }
        }
 
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo!\n");
    }

    free(emp_aux);
    free(new_funcionario);
}
