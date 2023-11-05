#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
// Created Modules
#include "../modules/clients.h"

// Atualização (Create) de Arquivos
void c_create_archive(char *ar_name, Cliente *cliente) { 
    FILE *fp;

    fp = fopen(ar_name, "ab");

    if (!(fp == NULL)) {
        fwrite(cliente, sizeof(Cliente), 1, fp);
        printf("\n\n>>> Adicionando informacao... <<<\n\n");
        fclose(fp);
    } else {
        printf("\n\n>>> Erro na criação do arquivo! <<<\n\n");
    }
}

// Leitura (Read) de Arquivos
Cliente* c_read_archive(char *ar_name, char *filter) {
    FILE *fp;
    Cliente* cli_aux = (Cliente*) malloc(sizeof(Cliente));

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {

        while(!feof(fp)) {
            // Lendo o Arquivo
            fread(cli_aux, sizeof(Cliente), 1, fp);
            // Comparando as Strings
            if (strcmp(cli_aux->cpf, filter) == 0 && cli_aux->status != 0) {
                fclose(fp);

                printf("\n\n>>> Cliente encontrado! <<<\n\n");
                return cli_aux;
            }
        }

        printf("\n >>> Cliente não encontrado. \n");
        fclose(fp);
    } else {
        printf("\n\n>>> Erro na criação do arquivo! <<<\n\n");
    }

    free(cli_aux);
    return NULL;
}

// Alteração (Update) de Arquivos
void c_update_archive(char *ar_name, char *filter, Cliente* new_Cliente) {
    FILE *fp;
    Cliente* cli_aux = (Cliente*) malloc(sizeof(Cliente));

    fp = fopen(ar_name, "r+b");

    if (!(fp == NULL)) {

        while(!feof(fp)) {
            // Lendo o Arquivo
            fread(cli_aux, sizeof(Cliente), 1, fp);
            // Comparando as Strings
            if (strcmp(cli_aux->cpf, filter) == 0 && cli_aux->status != 0) {
                // Após encontrar, alterar a localização do ponteiro
                fseek(fp, -1*sizeof(Cliente), SEEK_CUR);
                // Tendo reposicionado o ponteiro, atualizar.
                fwrite(new_Cliente, sizeof(Cliente), 1, fp);
                
                printf("\n\n>>> Cliente alterado! <<<\n\n");
                break;
            }
        }
 
        fclose(fp);
    } else {
        printf("\n\n>>> Erro na criação do arquivo! <<<\n\n");
    }

    free(cli_aux);
    free(new_Cliente);
}

// Excluir (Delete) de Arquivos
void c_delete_archive(char *ar_name, Cliente* cliente) {
    FILE *fp;
    Cliente* cli_aux = (Cliente*) malloc(sizeof(Cliente));

    fp = fopen(ar_name, "r+b");

    if (!(fp == NULL)) {

        while(!feof(fp)) {
            // Lendo o Arquivo
            fread(cli_aux, sizeof(Cliente), 1, fp);
            // Comparando as Strings
            if (strcmp(cli_aux->cpf, cliente->cpf) == 0 && cli_aux->status != 0) {
                cliente->status = 0;
                // Após encontrar, alterar a localização do ponteiro
                fseek(fp, -1*sizeof(Cliente), SEEK_CUR);
                // Tendo reposicionado o ponteiro, atualizar.
                fwrite(cliente, sizeof(Cliente), 1, fp);

                printf("\n\n>>> Cliente excluído! <<<\n\n");
                break;
            }
        }
 
        fclose(fp);
    } else {
        printf("\n\n>>> Erro na criação do arquivo! <<<\n\n");
    }

    free(cliente);
    free(cli_aux);
}

// Listagem (List) de Arquivos
void c_list_archive(char *ar_name) {
    FILE *fp; int loop = 0;
    Cliente* cli_aux = (Cliente*) malloc(sizeof(Cliente));

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {
        while(fread(cli_aux, sizeof(Cliente), 1, fp)) {
            // Lendo o Arquivo

            if (cli_aux->status != 0) {
                printf("\n\n>>> ------------------------------ <<<");
                printf("\n> Nome.................: %s", cli_aux->name);
                printf("\n> Idade................: %s", cli_aux->birth_date);
                printf("\n> CPF..................: %s", cli_aux->cpf);
                printf("\n> Email................: %s", cli_aux->email);
                printf("\n> Telefone.............: %s", cli_aux->tel);
            }
        }

        fclose(fp);
    } else {
        printf("\n\n>>> Erro na criação do arquivo! <<<\n\n");
    }

    free(cli_aux);
}