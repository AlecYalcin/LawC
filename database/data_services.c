#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
// Created Modules
#include "../modules/services.h"

// Atualização (Create) de Arquivos
void s_create_archive(char *ar_name, Service *service) { 
    FILE *fp;

    fp = fopen(ar_name, "ab");

    if (!(fp == NULL)) {
        fwrite(service, sizeof(Service), 1, fp);
        printf("\n\n>>> Adicionando informacao... <<<\n\n");
        fclose(fp);
    } else {
        printf("\n\n>>> Erro na criação do arquivo! <<<\n\n");
    }
}

// Leitura (Read) de Arquivos
Service* s_read_archive(char *ar_name, char *filter) {
    FILE *fp;
    Service* ser_aux = (Service*) malloc(sizeof(Service));

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {

        while(!feof(fp)) {
            // Lendo o Arquivo
            fread(ser_aux, sizeof(Service), 1, fp);
            // Comparando as Strings
            if (!(strcmp(ser_aux->name, filter))) {
                return ser_aux;
                fclose(fp);
            }
        }

        fclose(fp);
    } else {
        printf("\n\n>>> Erro na criação do arquivo! <<<\n\n");
    }

    free(ser_aux);
    return NULL;
}

// Alteração (Update) de Arquivos
void s_update_archive(char *ar_name, char *filter, Service* new_service) {
    FILE *fp;
    Service* ser_aux = (Service*) malloc(sizeof(Service));

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {

        while(!feof(fp)) {
            // Lendo o Arquivo
            fread(ser_aux, sizeof(Service), 1, fp);
            // Comparando as Strings
            if (!(strcmp(ser_aux->name, filter))) {
                printf("\n      -> Apontador Antes: %p", fp);
                // Após encontrar, alterar a localização do ponteiro
                long pos = -1L;
                fseek(fp, pos * sizeof(Service), SEEK_CUR);
                printf("\n      -> Apontador Depois: %p", fp);
                // Tendo reposicionado o ponteiro, atualizar.
                printf("\nNome: %s", new_service->name);
                fwrite(new_service, sizeof(Service), 1, fp);
                
                printf("\n\n>>> Servico alterado! <<<\n\n");
                break;
            }
        }
 
        fclose(fp);
    } else {
        printf("\n\n>>> Erro na criação do arquivo! <<<\n\n");
    }

    free(ser_aux);
    free(new_service);
}

// Excluir (Delete) de Arquivos
void s_delete_archive(char *ar_name, char *filter) {
    FILE *fp;
    Service* ser_aux = (Service*) malloc(sizeof(Service));

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {

        while(!feof(fp)) {
            // Lendo o Arquivo
            fread(ser_aux, sizeof(Service), 1, fp);
            // Comparando as Strings
            if (!(strcmp(ser_aux->name, filter))) {
                // Após encontrar, alterar a localização do ponteiro
                long pos = -1L;
                fseek(fp, pos * sizeof(Service), SEEK_CUR);
                // Tendo reposicionado o ponteiro, atualizar.
                fwrite(ser_aux, sizeof(Service), 1, fp);
                break;
            }
        }
 
        fclose(fp);
    } else {
        printf("\n\n>>> Erro na criação do arquivo! <<<\n\n");
    }

    free(ser_aux);
}

// Listagem (List) de Arquivos
void s_list_archive(char *ar_name) {
    FILE *fp; int loop = 0;
    Service* ser_aux = (Service*) malloc(sizeof(Service));

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {
        while(fread(ser_aux, sizeof(Service), 1, fp)) {
            // Lendo o Arquivo
            printf("\n\n>>> ------------------------------ <<<");
            printf("\n> Servico.................: %s", ser_aux->name);
            printf("\n> Valor...................: %.2f", ser_aux->value);
            printf("\n> Descricao...............: %s", ser_aux->desc);
        }

        fclose(fp);
    } else {
        printf("\n\n>>> Erro na criação do arquivo! <<<\n\n");
    }

    free(ser_aux);
}