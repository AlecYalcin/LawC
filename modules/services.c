#include <stdio.h>
#include "utils.h"

typedef struct service Service;

struct service {
    char name[30];
    char desc[200];
    float value;
};

void services_c(void) {
    Service new_service;
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                  Modulo de Servicos - Criacao                 |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
    // Coletar e Verificar o NOME DO SERVIÇO;
    get_name(new_service.name);
    // Coletar e Verificar a DESCRIÇÃO DO SERVIÇO;
    get_desc(new_service.desc);
    // Coletar e Verificar VALOR DO SERVIÇO;
    get_value(&new_service.value);
    printf("-----------------------------------------------------------------\n");
    printf("Nome: %s,\nDescricao: %s,\nValor: R$%.2f", new_service.name, new_service.desc, new_service.value);
}

void services_r(void) {
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