#include <stdio.h>
#include "utils.h"

typedef struct resource Resource;

struct resource {
    char name[30];
    char desc[200];
    char available_at[200];
};

void resources_c(void) {
    Resource new_resource;
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                  Modulo de Recursos - Criacao                 |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
    // Coletar e Verificar o NOME DO RECURSO;
    get_name(new_resource.name);
    // Coletar e Verificar a DESCRIÇÃO DO RECURSO;
    get_desc(new_resource.desc);
    // Coletar e Verificar ONDE ENCONTRAR O RECURSO;
    get_available_at(new_resource.available_at);
    printf("-----------------------------------------------------------------\n");
    printf("Nome: %s,\nDescricao: %s,\nDisponivel Em: %s", new_resource.name, new_resource.desc, new_resource.available_at);
}

void resources_r(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                 Modulo de Recursos - Pesquisa                 |\n");
    printf("|                                                               |\n");
    printf("|                 Filtro:(Nome, Disponibilidade)                |\n");
    printf("-----------------------------------------------------------------\n");
}

void resources_u(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                 Modulo de Recursos - Alterar                  |\n");
    printf("|                                                               |\n");
    printf("|                         Filtro:(Nome)                         |\n");
    printf("-----------------------------------------------------------------\n");
}

void resources_d(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                 Modulo de Recursos - Excluir                  |\n");
    printf("|                                                               |\n");
    printf("|                         Filtro:(Nome)                         |\n");
    printf("-----------------------------------------------------------------\n");
}

void resources_list(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                 Modulo de Recursos - Listar                   |\n");
    printf("|                                                               |\n");
    printf("|                         Filtro:(Nome)                         |\n");
    printf("-----------------------------------------------------------------\n");
}