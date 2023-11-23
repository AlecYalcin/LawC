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

        while(fread(sche_aux, sizeof(Schedule), 1, fp)) {
            Employer* employer;
            Cliente* client;
            Service* service;

            // Filtro A - Listagem Completa
            if (sche_aux->status != 0) {
                employer  = get_employer(sche_aux->id_employer);
                client    = get_client(sche_aux->id_client);
                service   = get_service(sche_aux->id_service);

                printf("\n>>> ------------------------------ <<<\n");
                printf("> Encontro.............: %s\n", sche_aux->name);
                printf("> Descricao............: %s\n", sche_aux->desc);
                printf("> Funcionario..........: %s (%s)\n", employer->name, sche_aux->id_employer);
                printf("> Cliente..............: %s (%s)\n", client->name, sche_aux->id_client);
                printf("> Serviço..............: %s (R$%.2f)\n", sche_aux->id_service, service->value);
                printf("> Data.................: %s\n", sche_aux->date); // Fazer função pra calcular qnt tempo falta
            } 
        }

        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }

    free(sche_aux);
}