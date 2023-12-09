#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
// Created Modules
#include "../data_utils.h"

// Atualização (Create) de Arquivos
void sc_create_archive(char *ar_name, Schedule *schedule) {
    FILE *fp;

    fp = fopen(ar_name, "ab");

    if (!(fp == NULL)) {
        fwrite(schedule, sizeof(Schedule), 1, fp);
        printf("\n>>> Adicionando informacao... <<<\n");
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }
}

// Leitura (Read) de Arquivos
Schedule* sc_read_archive(char *ar_name, char *filter) {
    FILE *fp;
    Schedule* sche_aux = (Schedule*) malloc(sizeof(Schedule));

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {

        while(!feof(fp)) {
            // Lendo o Arquivo
            fread(sche_aux, sizeof(Schedule), 1, fp);
            // Comparando as Strings
            if (strcmp(sche_aux->name, filter) == 0 && sche_aux->status != 0) {
                fclose(fp);

                printf("\n>>> Agendamento encontrado! <<<\n");
                return sche_aux;
            }
        }

        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }

    free(sche_aux);
    return NULL;
}

// Alteração (Update) de Arquivos
void sc_update_archive(char *ar_name, char *filter, Schedule* new_schedule) {
    FILE *fp;
    Schedule* sche_aux = (Schedule*) malloc(sizeof(Schedule));

    fp = fopen(ar_name, "r+b");

    if (!(fp == NULL)) {

        while(!feof(fp)) {
            // Lendo o Arquivo
            fread(sche_aux, sizeof(Schedule), 1, fp);
            // Comparando as Strings
            if (strcmp(sche_aux->name, filter) == 0 && sche_aux->status != 0) {
                // Após encontrar, alterar a localização do ponteiro
                fseek(fp, -1*sizeof(Schedule), SEEK_CUR);
                // Tendo reposicionado o ponteiro, atualizar.
                fwrite(new_schedule, sizeof(Schedule), 1, fp);
                
                printf("\n>>> Agendamento alterado! <<<\n");
                break;
            }
        }
 
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }

    free(sche_aux);
    free(new_schedule);
}

// Excluir (Delete) de Arquivos
void sc_delete_archive(char *ar_name, Schedule* schedule) {
    FILE *fp;
    Schedule* sche_aux = (Schedule*) malloc(sizeof(Schedule));

    fp = fopen(ar_name, "r+b");

    if (!(fp == NULL)) {

        while(!feof(fp)) {
            // Lendo o Arquivo
            fread(sche_aux, sizeof(Schedule), 1, fp);
            // Comparando as Strings
            if (strcmp(sche_aux->name, schedule->name) == 0 && sche_aux->status != 0) {
                schedule->status = 0;
                // Após encontrar, alterar a localização do ponteiro
                fseek(fp, -1*sizeof(Schedule), SEEK_CUR);
                // Tendo reposicionado o ponteiro, atualizar.
                fwrite(schedule, sizeof(Schedule), 1, fp);

                printf("\n>>> Agendamento excluído! <<<\n");
                break;
            }
        }
 
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }

    free(schedule);
    free(sche_aux);
}

// Listagem (List) de Arquivos
void sc_list_archive(char *ar_name, int fil_choice) {
    FILE *fp;
    Schedule* sche_aux = (Schedule*) malloc(sizeof(Schedule));

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {
        int choice; int date_value;

        if (fil_choice == 2) {
            do {
                printf("\n> Para filtrar a data, escolha o dia, mês ou ano para ser o dado da filtragem.\n");
                printf("[1] - Dia\n");
                printf("[2] - Mês\n");
                printf("[3] - Ano\n");
                printf("> Sua escolha: ");
                scanf(" %d", &choice);
            } while(choice < 1 || choice > 3);

            printf("> Digite agora o valor de dia/mês/ano: ");
            scanf(" %d", &date_value);
        }

        while(fread(sche_aux, sizeof(Schedule), 1, fp)) {
            // Filtro A - Listagem Completa
            if (sche_aux->status != 0 && fil_choice == 1) {
                sc_print_info(sche_aux);
            // Filtro B - Listagem por Data           
            } else if (sche_aux->status != 0 && fil_choice == 2) {
                int* date = todays_date();
                int* schedule_date = date_numeric(sche_aux->date);

                if(choice == 1) {
                    if(schedule_date[0] == date_value) {
                        sc_print_info(sche_aux);
                    }
                } else if (choice == 2) {
                    if (schedule_date[1] == date_value) {
                        sc_print_info(sche_aux);
                    }
                } else if (choice == 3) {
                    if (schedule_date[2] == date_value) {
                        sc_print_info(sche_aux);
                    }
                } else {
                    printf("\n!!! Aconteceu algum erro, cancelando operação. !!!\n");
                    break;
                }
            }
        }

        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }

    free(sche_aux);
}

void sc_dylist_archive(char *ar_name, int fil_choice) {
    FILE *fp;

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {
        Schedule* sche_aux = (Schedule*) malloc(sizeof(Schedule));
        Schedule* sche_list = NULL;

        if (fil_choice == 3) {
            // Ordenação por Nome
            while(fread(sche_aux, sizeof(Schedule), 1, fp)) {
                // Caso #1: Caso o NOME INSERIDO for MENOR que o elemento atual
                if((sche_list == NULL) || (strcmp(sche_aux->name, sche_list->name) < 0)) {
                    sche_aux->prox = sche_list;
                    sche_list = sche_aux;
                // Caso #2: Caso o NOME INSERIDO for MAIOR que o elemento autal
                } else {
                    // Gerando apontadores para o Schedule anterior da lista e atual.
                    Schedule* sche_anterior = sche_list;
                    Schedule* sche_atual    = sche_list->prox;
                    // Comparando o Schedule atual da lista com o Schedule lido
                    while((sche_atual != NULL) && (strcmp(sche_atual->name, sche_aux->name) < 0)) {
                        sche_anterior = sche_atual;
                        sche_atual = sche_atual->prox;
                    }
                    // O próximo Schedule do Schedule anterior vai ser o lido, e o próximo lido vai ser o atual
                    sche_anterior->prox = sche_aux;
                    sche_aux->prox      = sche_atual;
                }
                // Criando Memória + Lendo Schedule
                sche_aux = (Schedule*) malloc(sizeof(Schedule));
            }
        } else {
            // Ordenação por Idade
            while(fread(sche_aux, sizeof(Schedule), 1, fp)) {
                // Caso #1: Caso o NOME INSERIDO for MENOR que o elemento atual
                if((sche_list == NULL) || (return_age(sche_aux->date) <= return_age(sche_list->date))) {
                    sche_aux->prox = sche_list;
                    sche_list = sche_aux;
                // Caso #2: Caso o NOME INSERIDO for MAIOR que o elemento autal
                } else {
                    // Gerando apontadores para o Schedule anterior da lista e atual.
                    Schedule* sche_anterior = sche_list;
                    Schedule* sche_atual    = sche_list->prox;
                    // Comparando o Schedule atual da lista com o Schedule lido
                    while((sche_atual != NULL) && (return_age(sche_atual->date) < return_age(sche_aux->date))) {
                        sche_anterior = sche_atual;
                        sche_atual = sche_atual->prox;
                    }
                    // O próximo Schedule do Schedule anterior vai ser o lido, e o próximo lido vai ser o atual
                    sche_anterior->prox = sche_aux;
                    sche_aux->prox      = sche_atual;
                }
                // Criando Memória + Lendo Schedule
                sche_aux = (Schedule*) malloc(sizeof(Schedule));
            }
        }
        // Exibindo os Schedules
        printf("\n>>> Lista de Agendamentos\n");
        sche_aux = sche_list;
        while(sche_aux != NULL) {
            sc_print_info(sche_aux);
            sche_aux = sche_aux->prox;
        }

        // Liberando a memória
        sche_aux = sche_list;
        while(sche_list != NULL) {
            sche_list = sche_list->prox;
            free(sche_aux);
            sche_aux = sche_list;
        }

        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }
}

void sc_print_info(Schedule* schedule) {
    Employer* employer  = get_employer(schedule->id_employer);
    Cliente* client     = get_client(schedule->id_client);
    Service* service    = get_service(schedule->id_service);

    printf("\n>>> ------------------------------ <<<\n");
    printf("> Encontro.............: %s\n", schedule->name);
    printf("> Descricao............: %s\n", schedule->desc);
    printf("> Funcionario..........: %s (%s)\n", employer->name, schedule->id_employer);
    printf("> Cliente..............: %s (%s)\n", client->name, schedule->id_client);
    printf("> Serviço..............: %s (R$%.2f)\n", schedule->id_service, service->value);
    printf("> Data.................: %s\n", schedule->date);
}