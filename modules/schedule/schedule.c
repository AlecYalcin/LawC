#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Created Modules
#include "../utils.h"
#include "../data_utils.h"

typedef struct schedule Schedule;
// Arquivo de database
char* sc_ar_name = "modules/schedule/_schedule.dat";

void schedule_c(void) {
    Schedule* new_schedule = (Schedule*) malloc(sizeof(Schedule));

    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                Modulo de Agendamento - Criacao                |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
    // Coletar e Verificar Nome (Identificação) do Encontro
    get_schedule(new_schedule->name);
    // Coletar e Verificar a DESCRIÇÃO
    get_desc(new_schedule->desc);
    // Coletar os dados do CPF dos Funcionarios Envolvidos
    get_cpf(new_schedule->id_employer, 1);

    while(get_employer(new_schedule->id_employer) == NULL) {
        printf("\n!!! Esse funcionario NÃO existe. Tente Novamente. !!!\n");
        get_cpf(new_schedule->id_employer, 1);
    }

    // Coletar os dados do CPF dos Clientes Envolvidos
    get_cpf(new_schedule->id_client, 2);

    while(get_client(new_schedule->id_client) == NULL) {
        printf("\n!!! Esse cliente NÃO existe. Tente Novamente. !!!\n");
        get_cpf(new_schedule->id_client, 2);
    }

    // Coletar os dados do NOME dos Serviços Envolvidos
    get_name(new_schedule->id_service, 0);

    while(get_service(new_schedule->id_service) == NULL) {
        printf("\n!!! Esse serviço NÃO existe. Tente Novamente. !!!\n");
        get_name(new_schedule->id_service, 2);
    }

    // Coleta a Data do Encontro
    get_birth(new_schedule->date, 0);
    // Alterar Status
    new_schedule->status = 1;
    new_schedule->finalizado = 0;

    sc_print_info(new_schedule);

    // Verificar existencia de cliente parecido
    Schedule* aux_schedule = sc_read_archive(sc_ar_name, new_schedule->name);

    // Criação de arquivos
    if (verify_archive(sc_ar_name)) {
        // Se o arquivo existe, apenas adicione.
        if (aux_schedule == NULL) {
            sc_create_archive(sc_ar_name, new_schedule);
        } else {
            printf("\n>>> O Nome cadastrado já está em uso, tente outro.");
        }
    } else {
        // Se o arquivo não existe, crie e adicione.
        create_archive(sc_ar_name);
        if (aux_schedule == NULL) {
            sc_create_archive(sc_ar_name, new_schedule);
        } else {
            printf("\n>>> O Nome cadastrado já está em uso, tente outro.");
        }
    }

    // Liberação de memória dinâmica
    free(new_schedule);
    free(aux_schedule);
}

void schedule_r(void) {
    Schedule* schedule;
    char filter[51];

    limpa_buffer();
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|               Modulo de Agendamento - Pesquisar               |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
    printf("Digite o Nome: ");
    // Pegando dados e alterando
    fgets(filter, 51, stdin);
    change_last(filter);
    // Procurando os dados nos arquivos
    schedule = sc_read_archive(sc_ar_name, filter);
    if (schedule == NULL) {
        printf("\n>>> Agendamento não encontrado. \n");
    } else {
       sc_print_info(schedule);
        free(schedule);
    }
}

void schedule_u(void) {
    Schedule* schedule;
    char filter[51];

    limpa_buffer();
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                Modulo de Agendamento - Alterar                |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
    printf("Digite o Nome: ");
    // Pegando dados e alterando
    fgets(filter, 51, stdin);
    change_last(filter);
    // Procurando os dados nos arquivos
    schedule = sc_read_archive(sc_ar_name, filter);
    if (schedule == NULL) {
        printf("\n>>> Agendamento não encontrado. \n");
    } else {
        sc_print_info(schedule);

        printf("\n>>> Preencher as Novas Informacoes <<<\n");
        
        // Coletar e Verificar Nome (Identificação) do Encontro
        get_schedule(schedule->name);
        // Coletar e Verificar a DESCRIÇÃO
        get_desc(schedule->desc);
        // Coletar os dados do CPF dos Funcionarios Envolvidos
        get_cpf(schedule->id_employer, 1);
        // Coletar os dados do CPF dos Clientes Envolvidos
        get_cpf(schedule->id_client, 2);
        // Coletar os dados do NOME dos Serviços Envolvidos
        get_name(schedule->id_service, 0);
        // Coleta a Data do Encontro
        get_birth(schedule->date, 0);

        sc_print_info(schedule);

        sc_update_archive(sc_ar_name, filter, schedule);
    }
}

void schedule_d(void) {
    Schedule* schedule;
    char filter[51];

    limpa_buffer();
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                Modulo de Agendamento - Excluir                |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
    printf("Digite o Nome: ");
    // Pegando dados e alterando
    fgets(filter, 51, stdin);
    change_last(filter);
    // Procurando os dados nos arquivos
    schedule = sc_read_archive(sc_ar_name, filter);
    if (schedule == NULL) {
        printf("\n>>> Agendamento não encontrado. \n");
    } else {
        // Excluindo o arquivo
        sc_delete_archive(sc_ar_name, schedule);  
    }
}

void schedule_list(void) {
    int choice;

    limpa_buffer();
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                Modulo de Agendamento - Listar                 |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
    printf("[1] - Sem Filtro, Listagem Geral\n");
    printf("---------------------- Relatório Excludente ---------------------\n");
    printf("[2] - Filtro de Data\n");
    printf("----------------------- Relatório Ordenado ----------------------\n");
    printf("[3] - Ordenação de Nome\n");
    printf("[4] - Ordenação de Data\n");
    printf("Digite o Numero do Filtro: ");
    scanf(" %d", &choice);
    getchar();

    sc_list_archive(sc_ar_name, choice);
    if (!(choice >= 3 && choice <= 4)) {
        sc_list_archive(sc_ar_name, choice);
    } else {
        sc_dylist_archive(sc_ar_name, choice);
    }
}

void schedule_end(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|               Modulo de Agendamento - Finalizar               |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
}

void schedule_data(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|              Modulo de Agendamento - Calendario               |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
}
