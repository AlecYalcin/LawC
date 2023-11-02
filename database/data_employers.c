#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
// Created Modules
#include "../modules/employers.h"

// Atualização (Create) de Arquivos
void e_create_archive(char *ar_name, Employer *employer) { 
    FILE *fp;

    fp = fopen(ar_name, "ab");

    if (!(fp == NULL)) {
        fwrite(employer, sizeof(Employer), 1, fp);
        printf("\n\n>>> Adicionando informacao... <<<\n\n");
        fclose(fp);
    } else {
        printf("\n\n>>> Erro na criação do arquivo! <<<\n\n");
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
                fclose(fp);
                return emp_aux;
            }
        }

        fclose(fp);
    } else {
        printf("\n\n>>> Erro na criação do arquivo! <<<\n\n");
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
                // Após encontrar, alterar a localização do ponteiro
                fseek(fp, -1*sizeof(Employer), SEEK_CUR);
                // Tendo reposicionado o ponteiro, atualizar.
                fwrite(new_funcionario, sizeof(Employer), 1, fp);
                
                printf("\n\n>>> Funcionário alterado! <<<\n\n");
                break;
            }
        }
 
        fclose(fp);
    } else {
        printf("\n\n>>> Erro na criação do arquivo! <<<\n\n");
    }

    free(emp_aux);
    free(new_funcionario);
}

// Excluir (Delete) de Arquivos
void e_delete_archive(char *ar_name, Employer* employer) {
    char* temp_txt = "database/_temp.dat";
    // Criação dupla de arquivos, onde um vai ser a cópia MENOS um
    FILE *fp, *fp_temp;
    Employer* emp_aux = (Employer*) malloc(sizeof(Employer));

    fp      = fopen(ar_name, "rb");
    fp_temp = fopen(temp_txt, "wb");

    if (!(fp == NULL) && !(fp_temp == NULL)) {

        while(!feof(fp)) {
            // Lendo o Arquivo
            fread(emp_aux, sizeof(Employer), 1, fp);
            // Comparando as Strings
            if (strcmp(employer->cpf, emp_aux->cpf) != 0) {
                // Somente colocar o que não for o que se quer excluir
                fwrite(emp_aux, sizeof(Employer), 1, fp_temp);
                break;
            }
        }

        // Fechando os arquivos
        fclose(fp_temp);
        fclose(fp);

        // Excluindo e Renomeando 
        remove("database/_employers.dat");
        rename("database/_temp.dat", ar_name);

        printf("\n>>>Excluido com Sucesso.\n");

    } else {
        printf("\n\n>>> Erro na criação do arquivo! <<<\n\n");
    }

    free(emp_aux);
    free(employer);
}

// Listagem (List) de Arquivos
void e_list_archive(char *ar_name) {
    FILE *fp; int loop = 0;
    Employer* emp_aux = (Employer*) malloc(sizeof(Employer));

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {
        while(fread(emp_aux, sizeof(Employer), 1, fp)) {
            // Lendo o Arquivo
            printf("\n\n>>> ------------------------------ <<<");
            printf("\n> Nome....................: %s", emp_aux->name);
            printf("\n> Idade...................: %s", emp_aux->birth_date);
            printf("\n> CPF.....................: %s", emp_aux->cpf);
            printf("\n> E-mail..................: %s", emp_aux->email);
            printf("\n> Telefone................: %s", emp_aux->tel);
            printf("\n> OAB.....................: %s", emp_aux->OAB);
            printf("\n> Funcao..................: %s", emp_aux->role);
            printf("\n> Descricao...............: %s", emp_aux->desc);
        }

        fclose(fp);
    } else {
        printf("\n\n>>> Erro na criação do arquivo! <<<\n\n");
    }

    free(emp_aux);
}