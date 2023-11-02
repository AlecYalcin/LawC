#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
// Created Modules
#include "../modules/resources.h"

// Atualização (Create) de Arquivos
void r_create_archive(char *ar_name, Resource *resource) { 
    FILE *fp;

    fp = fopen(ar_name, "ab");

    if (!(fp == NULL)) {
        fwrite(resource, sizeof(Resource), 1, fp);
        printf("\n\n>>> Adicionando informacao... <<<\n\n");
        fclose(fp);
    } else {
        printf("\n\n>>> Erro na criação do arquivo! <<<\n\n");
    }
}

// Leitura (Read) de Arquivos
Resource* r_read_archive(char *ar_name, char *filter) {
    FILE *fp;
    Resource* res_aux = (Resource*) malloc(sizeof(Resource));

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {

        while(!feof(fp)) {
            // Lendo o Arquivo
            fread(res_aux, sizeof(Resource), 1, fp);
            // Comparando as Strings
            if (!(strcmp(res_aux->name, filter))) {
                fclose(fp);
                return res_aux;
            }
        }

        fclose(fp);
    } else {
        printf("\n\n>>> Erro na criação do arquivo! <<<\n\n");
    }

    free(res_aux);
    return NULL;
}

// Alteração (Update) de Arquivos
void r_update_archive(char *ar_name, char *filter, Resource* new_resource) {
    FILE *fp;
    Resource* res_aux = (Resource*) malloc(sizeof(Resource));

    fp = fopen(ar_name, "r+b");

    if (!(fp == NULL)) {

        while(!feof(fp)) {
            // Lendo o Arquivo
            fread(res_aux, sizeof(Resource), 1, fp);
            // Comparando as Strings
            if (!(strcmp(res_aux->name, filter))) {
                // Após encontrar, alterar a localização do ponteiro
                fseek(fp, -1*sizeof(Resource), SEEK_CUR);
                // Tendo reposicionado o ponteiro, atualizar.
                fwrite(new_resource, sizeof(Resource), 1, fp);
                
                printf("\n\n>>> Recurso alterado! <<<\n\n");
                break;
            }
        }
 
        fclose(fp);
    } else {
        printf("\n\n>>> Erro na criação do arquivo! <<<\n\n");
    }

    free(res_aux);
    free(new_resource);
}

// Excluir (Delete) de Arquivos
void r_delete_archive(char *ar_name, char *filter) {
    FILE *fp;
    Resource* res_aux = (Resource*) malloc(sizeof(Resource));

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {

        while(!feof(fp)) {
            // Lendo o Arquivo
            fread(res_aux, sizeof(Resource), 1, fp);
            // Comparando as Strings
            if (!(strcmp(res_aux->name, filter))) {
                // Após encontrar, alterar a localização do ponteiro
                long pos = -1L;
                fseek(fp, pos * sizeof(Resource), SEEK_CUR);
                // Tendo reposicionado o ponteiro, atualizar.
                fwrite(res_aux, sizeof(Resource), 1, fp);
                break;
            }
        }
 
        fclose(fp);
    } else {
        printf("\n\n>>> Erro na criação do arquivo! <<<\n\n");
    }

    free(res_aux);
}

// Listagem (List) de Arquivos
void r_list_archive(char *ar_name) {
    FILE *fp; int loop = 0;
    Resource* res_aux = (Resource*) malloc(sizeof(Resource));

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {
        while(fread(res_aux, sizeof(Resource), 1, fp)) {
            // Lendo o Arquivo
            printf("\n\n>>> ------------------------------ <<<");
            printf("\n> Servico.................: %s", res_aux->name);
            printf("\n> Descricao...............: %s", res_aux->desc);
            printf("\n> Disponivel Em...........: %s", res_aux->available_at);
        }

        fclose(fp);
    } else {
        printf("\n\n>>> Erro na criação do arquivo! <<<\n\n");
    }

    free(res_aux);
}