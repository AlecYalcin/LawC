#include <stdio.h>
#include <stdlib.h>
// Created Modules
#include "utils.h"
#include "../database/data_utils.h"
#include "../database/data_schedule.h" //data_clients já tem o include de clients

typedef struct schedule Schedule;
// Arquivo de database
char* sc_ar_name = "database/_schedule.dat";

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
    get_name(new_schedule->name, 1);
    // Coletar e Verificar a DESCRIÇÃO
    get_desc(new_schedule->desc);
    // Coletar os dados do CPF dos Funcionarios Envolvidos
    get_cpf(new_schedule->id_employer, 1);
    // Coletar os dados do CPF dos Clientes Envolvidos
    get_cpf(new_schedule->id_client, 2);
    // Coletar os dados do NOME dos Serviços Envolvidos
    get_name(new_schedule->id_service, 0);
    // Coleta a Data do Encontro
    get_birth(new_schedule->date, 0);
    // Alterar Status
    new_schedule->status = 1;

    printf("\n>>> ------------------------------ <<<\n");
    printf("> Encontro.............: %s\n", new_schedule->name);
    printf("> Descricao............: %s\n", new_schedule->desc);
    printf("> Funcionario..........: %s\n", new_schedule->id_employer);
    printf("> Cliente..............: %s\n", new_schedule->id_client);
    printf("> Serviço..............: %s\n", new_schedule->id_service);
    printf("> Data.................: %s\n", new_schedule->date); // Fazer função pra calcular qnt tempo falta
    //printf("> Valor................: %.2f\n", new_schedule->value?);

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
        printf("\n>>> schedule não encontrado. \n");
    } else {
        printf("\n>>> ------------------------------ <<<\n");
        printf("> Encontro.............: %s\n", schedule->name);
        printf("> Descricao............: %s\n", schedule->desc);
        printf("> Funcionario..........: %s\n", schedule->id_employer);
        printf("> Cliente..............: %s\n", schedule->id_client);
        printf("> Serviço..............: %s\n", schedule->id_service);
        printf("> Data.................: %s\n", schedule->date); // Fazer função pra calcular qnt tempo falta
        free(schedule);
    }
}

void schedule_u(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                Modulo de Agendamento - Alterar                |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
}

void schedule_d(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                Modulo de Agendamento - Excluir                |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
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

void schedule_list(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                Modulo de Agendamento - Listar                 |\n");
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
