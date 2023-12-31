#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
// Created Modules
#include "../data_utils.h"

// Atualização (Create) de Arquivos
void s_create_archive(char *ar_name, Service *service) { 
    FILE *fp;

    fp = fopen(ar_name, "ab");

    if (!(fp == NULL)) {
        fwrite(service, sizeof(Service), 1, fp);
        printf("\n>>> Adicionando informacao... <<<\n");
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
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
            if (strcmp(ser_aux->name, filter) == 0 && ser_aux->status != 0) {
                fclose(fp);

                printf("\n>>> Serviço encontrado! <<<\n");
                return ser_aux;
            }
        }
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }

    free(ser_aux);
    return NULL;
}

// Alteração (Update) de Arquivos
void s_update_archive(char *ar_name, char *filter, Service* new_service) {
    FILE *fp;
    Service* ser_aux = (Service*) malloc(sizeof(Service));

    fp = fopen(ar_name, "r+b");

    if (!(fp == NULL)) {

        while(!feof(fp)) {
            // Lendo o Arquivo
            fread(ser_aux, sizeof(Service), 1, fp);
            // Comparando as Strings
            if (strcmp(ser_aux->name, filter) == 0 && ser_aux->status != 0) {
                // Após encontrar, alterar a localização do ponteiro
                fseek(fp, -1*sizeof(Service), SEEK_CUR);
                // Tendo reposicionado o ponteiro, atualizar.
                fwrite(new_service, sizeof(Service), 1, fp);
                
                printf("\n>>> Servico alterado! <<<\n");
                break;
            }
        }
 
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }

    free(ser_aux);
    free(new_service);
}

// Excluir (Delete) de Arquivos
void s_delete_archive(char *ar_name, Service* service) {
    FILE *fp;
    Service* ser_aux = (Service*) malloc(sizeof(Service));

    fp = fopen(ar_name, "r+b");

    if (!(fp == NULL)) {

        while(!feof(fp)) {
            // Lendo o Arquivo
            fread(ser_aux, sizeof(Service), 1, fp);
            // Comparando as Strings
            if (strcmp(ser_aux->name, service->name) == 0 && ser_aux->status != 0) {
                service->status = 0;
                // Após encontrar, alterar a localização do ponteiro
                fseek(fp, -1*sizeof(Service), SEEK_CUR);
                // Tendo reposicionado o ponteiro, atualizar.
                fwrite(service, sizeof(Service), 1, fp);

                printf("\n>>> Serviço excluído! <<<\n");
                break;
            }
        }
 
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }

    free(ser_aux);
}

// Listagem (List) de Arquivos
void s_list_archive(char *ar_name, int fil_choice) {
    FILE *fp;
    Service* ser_aux = (Service*) malloc(sizeof(Service));

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {
        char ord; float num;
        char* name = (char*) malloc(51*sizeof(char));

        // Coletando os Dados de Filtro
        if (fil_choice == 2) {
            int aux = 1;

            while(aux) {
                printf("\n> Para filtrar por valor, por favor digite na seguinte ordem:\n");
                printf("> [>Numero] - Maior ou igual a Numero, Ex: >5, >27, >60\n");
                printf("> [<Numero] - Menor ou igual a Numero, Ex: <6, <60, <35\n");
                printf("> Qualquer outra ordem sera considerada invalida.\n");
                printf("\n> Digite a Ordem ('>' ou '<').....: ");
                scanf(" %c", &ord);

                if (!(ord == '>' || ord == '<')) {
                    printf("\n>>> Ordem invalida. \n");
                } else {
                    printf("\n> Digite o valor.................: R$");
                    scanf("%f", &num); getchar();
                    aux = 0;
                }
            }
        } else if (fil_choice == 3) {
            printf("> Nome a Pesquisar................: ");
            fgets(name, 51, stdin);
            change_last_2(name);
        }

        while(fread(ser_aux, sizeof(Service), 1, fp)) {
            // Filtro A - Listagem Completa
            if (ser_aux->status != 0 && fil_choice == 1) {
                s_print_info(ser_aux);
            
            // Filtro B - Listagem por Valor
            } else if (ser_aux->status != 0 && fil_choice == 2) {
                if (ord == '>') {
                    if (ser_aux->value >= num) {
                        s_print_info(ser_aux);
                    } 
                } else if(ord == '<') {
                    if (ser_aux->value <= num) {
                        s_print_info(ser_aux);
                    }
                }
            // Filtro C - Listagem por Nome
            } else if (ser_aux->status != 0 && fil_choice == 3) {
                if (!(strncmp(ser_aux->name, name, strlen(name)))) {
                    s_print_info(ser_aux);
                }
            } else if (fil_choice > 3 || fil_choice < 0) {
                printf("\n>>> Opção inválida, voltando a tela de Serviços...\n");
                break;
            }
        }

        free(name);

        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }

    free(ser_aux);
}

void s_dylist_archive(char *ar_name, int fil_choice) {
    FILE *fp;

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {
        Service* ser_aux = (Service*) malloc(sizeof(Service));
        Service* ser_list = NULL;

        
        if (fil_choice == 4) {
            // Ordenação por Nome
            while(fread(ser_aux, sizeof(Service), 1, fp)) {
                // Caso #1: Caso o NOME INSERIDO for MENOR que o elemento atual
                if((ser_list == NULL) || (strcmp(ser_aux->name, ser_list->name) < 0)) {
                    ser_aux->prox = ser_list;
                    ser_list = ser_aux;
                // Caso #2: Caso o NOME INSERIDO for MAIOR que o elemento autal
                } else {
                    // Gerando apontadores para o Service anterior da lista e atual.
                    Service* ser_anterior = ser_list;
                    Service* ser_atual    = ser_list->prox;
                    // Comparando o Service atual da lista com o Service lido
                    while((ser_atual != NULL) && (strcmp(ser_atual->name, ser_aux->name) < 0)) {
                        ser_anterior = ser_atual;
                        ser_atual = ser_atual->prox;
                    }
                    // O próximo Service do Service anterior vai ser o lido, e o próximo lido vai ser o atual
                    ser_anterior->prox = ser_aux;
                    ser_aux->prox      = ser_atual;
                }
                // Criando Memória + Lendo Service
                ser_aux = (Service*) malloc(sizeof(Service));
            }
        } else {
            // Ordenação por Nome
            while(fread(ser_aux, sizeof(Service), 1, fp)) {
                // Caso #1: Caso o NOME INSERIDO for MENOR que o elemento atual
                if((ser_list == NULL) || (ser_aux->value <= ser_list->value)) {
                    ser_aux->prox = ser_list;
                    ser_list = ser_aux;
                // Caso #2: Caso o NOME INSERIDO for MAIOR que o elemento autal
                } else {
                    // Gerando apontadores para o Service anterior da lista e atual.
                    Service* ser_anterior = ser_list;
                    Service* ser_atual    = ser_list->prox;
                    // Comparando o Service atual da lista com o Service lido
                    while((ser_atual != NULL) && (ser_atual->value < ser_aux->value)) {
                        ser_anterior = ser_atual;
                        ser_atual = ser_atual->prox;
                    }
                    // O próximo Service do Service anterior vai ser o lido, e o próximo lido vai ser o atual
                    ser_anterior->prox = ser_aux;
                    ser_aux->prox      = ser_atual;
                }
                // Criando Memória + Lendo Service
                ser_aux = (Service*) malloc(sizeof(Service));
            }
        }

        // Exibindo os Services
        printf("\n>>> Lista de Services\n");
        ser_aux = ser_list;
        while(ser_aux != NULL) {
            s_print_info(ser_aux);
            ser_aux = ser_aux->prox;
        }

        // Liberando a memória
        ser_aux = ser_list;
        while(ser_list != NULL) {
            ser_list = ser_list->prox;
            free(ser_aux);
            ser_aux = ser_list;
        }

        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }
}

void s_print_info(Service* service) {
    printf("\n>>> ------------------------------ <<<\n");
    printf("> Servico.................: %s\n",      service->name);
    printf("> Valor...................: R$%.2f\n",  service->value);
    printf("> Descricao...............: %s\n",      service->desc);
}