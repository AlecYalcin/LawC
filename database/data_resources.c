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
        printf("\n>>> Adicionando informacao... <<<\n");
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
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
            if (strcmp(res_aux->name, filter) == 0 && res_aux->status != 0) {
                fclose(fp);

                printf("\n>>> Recurso encontrado! <<<\n");
                return res_aux;
            }
        }

        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
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
            if (strcmp(res_aux->name, filter) == 0 && res_aux->status != 0) {
                // Após encontrar, alterar a localização do ponteiro
                fseek(fp, -1*sizeof(Resource), SEEK_CUR);
                // Tendo reposicionado o ponteiro, atualizar.
                fwrite(new_resource, sizeof(Resource), 1, fp);
                
                printf("\n>>> Recurso alterado! <<<\n");
                break;
            }
        }
 
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }

    free(res_aux);
    free(new_resource);
}

// Excluir (Delete) de Arquivos
void r_delete_archive(char *ar_name, Resource* resource) {
    FILE *fp;
    Resource* res_aux = (Resource*) malloc(sizeof(Resource));

    fp = fopen(ar_name, "r+b");

    if (!(fp == NULL)) {

        while(!feof(fp)) {
            // Lendo o Arquivo
            fread(res_aux, sizeof(Resource), 1, fp);
            // Comparando as Strings
            if (strcmp(res_aux->name, resource->name) == 0 && res_aux->status != 0) {
                resource->status = 0;
                // Após encontrar, alterar a localização do ponteiro
                fseek(fp, -1L*sizeof(Resource), SEEK_CUR);
                // Tendo reposicionado o ponteiro, atualizar.
                fwrite(resource, sizeof(Resource), 1, fp);

                printf("\n>>> Recurso excluído! <<<\n");
                break;
            }
        }
 
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }

    free(resource);
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
            if (res_aux->status !=0 ) {
                printf("\n>>> ------------------------------ <<<\n");
                printf("> Recurso.................: %s\n", res_aux->name);
                printf("> Descricao...............: %s\n", res_aux->desc);
                printf("> Disponivel Em...........: %s\n", res_aux->available_at);
            }
        }

        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }

    free(res_aux);
}