#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Created Modules
#include "utils.h"
#include "../database/data_utils.h"
#include "../database/data_services.h" //data_clients já tem o include de services
typedef struct service Service;

// Arquivo de database
char* s_ar_name = "database/_services.dat";
void services_c(void) {
    Service* new_service = (Service*) malloc(sizeof(Service));

    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                  Modulo de Servicos - Criacao                 |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
    // Coletar e Verificar o NOME DO SERVIÇO;
    get_name(new_service->name);
    // Coletar e Verificar a DESCRIÇÃO DO SERVIÇO;
    get_desc(new_service->desc);
    // Coletar e Verificar VALOR DO SERVIÇO;
    get_value(&new_service->value);

    printf("\n\n>>> ------------------------------ <<<");
    printf("\n> Servico.................: %s", new_service->name);
    printf("\n> Valor...................: %.2f", new_service->value);
    printf("\n> Descricao...............: %s", new_service->desc);

    // Criação de arquivos
    if (verify_archive(s_ar_name)) {
        // Se o arquivo existe, apenas adicione.
        s_create_archive(s_ar_name, new_service);
    } else {
        // Se o arquivo não existe, crie e adicione.
        create_archive(s_ar_name);
        s_create_archive(s_ar_name, new_service);
    }
    // Liberação de memória dinâmica
    free(new_service);
}

void services_r(void) {
    Service* funcionario;
    char filter[50];

    limpa_buffer();
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                 Modulo de Servicos - Pesquisa                 |\n");
    printf("|                                                               |\n");
    printf("|                     Filtro:(Nome, Valor)                      |\n");
    printf("-----------------------------------------------------------------\n");
}

void services_u(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                 Modulo de Servicos - Alterar                  |\n");
    printf("|                                                               |\n");
    printf("|                     Filtro:(Nome, Valor)                      |\n");
    printf("-----------------------------------------------------------------\n");
}

void services_d(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                 Modulo de Servicos - Excluir                  |\n");
    printf("|                                                               |\n");
    printf("|                         Filtro:(Nome)                         |\n");
    printf("-----------------------------------------------------------------\n");
}

void services_list(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                  Modulo de Servicos - Listar                  |\n");
    printf("|                                                               |\n");
    printf("|                     Filtro:(Nome, Valor)                      |\n");
    printf("-----------------------------------------------------------------\n");
}