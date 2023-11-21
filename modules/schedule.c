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
    printf("|                     Funcionários:                             |\n");
    printf("|                     Clientes:                                 |\n");
    printf("|                     Recursos:                                 |\n");
    printf("|                     Serviço:                                  |\n");
    printf("|                     Data:                                     |\n");
    printf("|                     Valor:                                    |\n");
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
}

void schedule_r(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|               Modulo de Agendamento - Pesquisar               |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
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
