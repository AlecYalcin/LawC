#include <stdio.h>
#include <stdlib.h>
// Created Modules
#include "../utils.h"
#include "../data_utils.h"

// Arquivo de database
char* s_ar_name = "modules/service/_services.dat";
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
    get_name(new_service->name, 1);
    // Coletar e Verificar VALOR DO SERVIÇO;
    get_value(&new_service->value);
    // Coletar e Verificar a DESCRIÇÃO DO SERVIÇO;
    get_desc(new_service->desc);
    // Alterando Status 
    new_service->status = 1;

    s_print_info(new_service);

    // Verificar existencia de cliente parecido
    Service* aux_service = s_read_archive(s_ar_name, new_service->name);

    // Criação de arquivos
    if (verify_archive(s_ar_name)) {
        // Se o arquivo existe, apenas adicione.
        if (aux_service == NULL) {
            s_create_archive(s_ar_name, new_service);
        } else {
            printf("\n>>> O Serviço cadastrado já existe.");
        }
    } else {
        // Se o arquivo não existe, crie e adicione.
        create_archive(s_ar_name);
        if (aux_service == NULL) {
            s_create_archive(s_ar_name, new_service);
        } else {
            printf("\n>>> O Serviço cadastrado já existe.");
        }
    }
    // Liberação de memória dinâmica
    free(new_service);
    free(aux_service);
}

void services_r(void) {
    Service* service;
    char filter[51];

    limpa_buffer();
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                 Modulo de Servicos - Pesquisa                 |\n");
    printf("|                                                               |\n");
    printf("|                         Filtro:(Nome)                         |\n");
    printf("-----------------------------------------------------------------\n");
    printf("Digite o Nome: ");
    // Pegando dados e alterando
    fgets(filter, 51, stdin);
    change_last(filter);
    // Procurando os dados nos arquivos
    service = s_read_archive(s_ar_name, filter);
    if (service == NULL) {
        printf("\n>>> Servico não encontrado. \n");
    } else {
        s_print_info(service);

        
        free(service);
    }

}

void services_u(void) {
    Service* service;
    char filter[51];

    limpa_buffer();
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                 Modulo de Servicos - Alterar                  |\n");
    printf("|                                                               |\n");
    printf("|                     Filtro:(Nome, Valor)                      |\n");
    printf("-----------------------------------------------------------------\n");
    printf("Digite o Nome: ");
    // Pegando dados e alterando
    fgets(filter, 51, stdin);
    change_last(filter);
    // Procurando os dados nos arquivos
    service = s_read_archive(s_ar_name, filter);
    if (service == NULL) {
        printf("\n>>> Servico não encontrado. \n");
    } else {
        s_print_info(service);
        
        printf("\n>>> Preencher as Novas Informacoes <<<\n");
        // Coletar e Verificar o NOME DO SERVIÇO;
        get_name(service->name, 1);
        // Coletar e Verificar a DESCRIÇÃO DO SERVIÇO;
        get_value(&service->value);
        // Coletar e Verificar VALOR DO SERVIÇO;
        get_desc(service->desc);

        s_print_info(service);    

        s_update_archive(s_ar_name, filter, service);
    }
}

void services_d(void) {
    Service* service = (Service*) malloc(sizeof(Service));
    char filter[51];

    limpa_buffer();
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                 Modulo de Servicos - Excluir                  |\n");
    printf("|                                                               |\n");
    printf("|                         Filtro:(Nome)                         |\n");
    printf("-----------------------------------------------------------------\n");
    printf("Digite o Nome: ");
    // Pegando dados e alterando
    fgets(filter, 51, stdin);
    change_last(filter);
    // Procurando os dados nos arquivos
    service = s_read_archive(s_ar_name, filter);
    if (service == NULL) {
        printf("\n>>> Serviço não encontrado. \n");
    } else {
        // Excluir Serviço
        s_delete_archive(s_ar_name, service);
    }
}

void services_list(void) {
    int choice;

    limpa_buffer();
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                  Modulo de Servicos - Listar                  |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
    printf("[1] - Sem Filtro, Listagem Geral\n");
    printf("---------------------- Relatório Excludente ---------------------\n");
    printf("[2] - Filtro de Valor\n");
    printf("[3] - Filtro de Nome\n");
    printf("----------------------- Relatório Ordenado ----------------------\n");
    printf("[4] - Ordenação de Nome\n");
    printf("[5] - Ordenação de Valor\n");
    printf("Digite o Numero do Filtro: ");
    scanf("%d", &choice);
    getchar();

    if (!(choice >= 4 && choice <= 5)) {
        s_list_archive(s_ar_name, choice);
    } else {
        s_dylist_archive(s_ar_name, choice);
    }
}