#include <stdio.h>
#include "utils.h"

void resources_c(void) {
    char name[30]; char desc[200]; char available_at[200];
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                  Modulo de Recursos - Criacao                 |\n");
    printf("|                                                               |\n");
    printf("|                     Nome:                                     |\n");
    printf("|                     Descricao:                                |\n");
    printf("|                     Disponibilidade:                          |\n");
    printf("-----------------------------------------------------------------\n");
    // Coletar e Verificar o NOME DO RECURSO;
    get_name(name);
    // Coletar e Verificar a DESCRIÇÃO DO RECURSO;
    get_desc(desc);
    // Coletar e Verificar ONDE ENCONTRAR O RECURSO;
    get_available_at(available_at);
    printf("-----------------------------------------------------------------\n");
    printf("Nome: %s,\nDescricao: %s,\nDisponivel Em: %s", name, desc, available_at);
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