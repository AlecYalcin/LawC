#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
// Created Modules
#include "../data_utils.h"

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
void r_list_archive(char *ar_name, int fil_choice) {
    FILE *fp; int loop = 0;
    Resource* res_aux = (Resource*) malloc(sizeof(Resource));

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {
        char* name = (char*) malloc(51*sizeof(char));

        if (fil_choice == 2 || fil_choice == 3) {
            printf("> Nome a Pesquisar................: ");
            fgets(name, 51, stdin);
            change_last_2(name);
        }

        while(fread(res_aux, sizeof(Resource), 1, fp)) {
            // Filtro A - Listagem Geral
            if (res_aux->status !=0 && fil_choice == 1) {
                r_print_info(res_aux);
            // Filtro B e C - Listagem por Nome/Disponibilidade
            } else if (res_aux->status !=0 && fil_choice == 2) {
                if (!(strncmp(res_aux->name, name, strlen(name)))) {
                    r_print_info(res_aux);
                }
            } else if (res_aux->status !=0 && fil_choice == 3) {
                if (!(strncmp(res_aux->available_at, name, strlen(name)))) {
                    r_print_info(res_aux);
                }
            } else if (fil_choice > 3 || fil_choice < 0) {
                printf("\n>>> Opção inválida, voltando a tela de Recursos...\n");
                break;
            }
        }

        free(name);

        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }

    free(res_aux);
}

void r_dylist_archive(char *ar_name, int fil_choice) {
    FILE *fp;

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {
        Resource* res_aux = (Resource*) malloc(sizeof(Resource));
        Resource* res_list = NULL;
        
        if (fil_choice == 4) {
            // Ordenação por Nome
            while(fread(res_aux, sizeof(Resource), 1, fp)) {
                // Caso #1: Caso o NOME INSERIDO for MENOR que o elemento atual
                if((res_list == NULL) || (strcmp(res_aux->name, res_list->name) < 0)) {
                    res_aux->prox = res_list;
                    res_list = res_aux;
                // Caso #2: Caso o NOME INSERIDO for MAIOR que o elemento autal
                } else {
                    // Gerando apontadores para o Resource anterior da lista e atual.
                    Resource* res_anterior = res_list;
                    Resource* res_atual    = res_list->prox;
                    // Comparando o Resource atual da lista com o Resource lido
                    while((res_atual != NULL) && (strcmp(res_atual->name, res_aux->name) < 0)) {
                        res_anterior = res_atual;
                        res_atual = res_atual->prox;
                    }
                    // O próximo Resource do Resource anterior vai ser o lido, e o próximo lido vai ser o atual
                    res_anterior->prox = res_aux;
                    res_aux->prox      = res_atual;
                }
                // Criando Memória + Lendo Resource
                res_aux = (Resource*) malloc(sizeof(Resource));
            }
        } else {
            // Ordenação por Idade
            while(fread(res_aux, sizeof(Resource), 1, fp)) {
                // Caso #1: Caso o NOME INSERIDO for MENOR que o elemento atual
                if((res_list == NULL) || (res_aux->available_at <= res_list->available_at)) {
                    res_aux->prox = res_list;
                    res_list = res_aux;
                // Caso #2: Caso o NOME INSERIDO for MAIOR que o elemento autal
                } else {
                    // Gerando apontadores para o Resource anterior da lista e atual.
                    Resource* res_anterior = res_list;
                    Resource* res_atual    = res_list->prox;
                    // Comparando o Resource atual da lista com o Resource lido
                    while((res_atual != NULL) && (res_atual->available_at < res_aux->available_at)) {
                        res_anterior = res_atual;
                        res_atual = res_atual->prox;
                    }
                    // O próximo Resource do Resource anterior vai ser o lido, e o próximo lido vai ser o atual
                    res_anterior->prox = res_aux;
                    res_aux->prox      = res_atual;
                }
                // Criando Memória + Lendo Resource
                res_aux = (Resource*) malloc(sizeof(Resource));
            }
        }
        // Exibindo os Resources
        printf("\n>>> Lista de Recursos\n");
        res_aux = res_list;
        while(res_aux != NULL) {
            r_print_info(res_aux);
            res_aux = res_aux->prox;
        }

        // Liberando a memória
        res_aux = res_list;
        while(res_list != NULL) {
            res_list = res_list->prox;
            free(res_aux);
            res_aux = res_list;
        }

        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }
}

void r_print_info(Resource* resource) {
    printf("\n>>> ------------------------------ <<<\n");
    printf("> Recurso.................: %s\n", resource->name);
    printf("> Descricao...............: %s\n", resource->desc);
    printf("> Disponivel Em...........: %s\n", resource->available_at);
}