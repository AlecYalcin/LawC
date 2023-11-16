#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
// Created Modules
#include "../modules/clients.h"
#include "../database/data_utils.h"

// Atualização (Create) de Arquivos
void c_create_archive(char *ar_name, Cliente *cliente) { 
    FILE *fp;

    fp = fopen(ar_name, "ab");

    if (!(fp == NULL)) {
        fwrite(cliente, sizeof(Cliente), 1, fp);
        printf("\n>>> Adicionando informacao... <<<\n");
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
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

                printf("\n>>> Cliente encontrado! <<<\n");
                return cli_aux;
            }
        }

        printf("\n >>> Cliente não encontrado. \n");
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
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
                
                printf("\n>>> Cliente alterado! <<<\n");
                break;
            }
        }
 
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
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

                printf("\n>>> Cliente excluído! <<<\n");
                break;
            }
        }
 
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
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
                printf("\n>>> ------------------------------ <<<\n");
                printf("> Nome.................: %s\n", cli_aux->name);
                printf("> Idade................: %d (%s)\n", return_age(cli_aux->birth_date), cli_aux->birth_date); 
                printf("> CPF..................: %s\n", cli_aux->cpf);
                printf("> Email................: %s\n", cli_aux->email);
                printf("> Telefone.............: %s\n", cli_aux->tel);
            }
        }

        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }

    free(cli_aux);
}