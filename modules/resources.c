#include <stdio.h>
#include <stdlib.h>
// Created Modules
#include "utils.h"
#include "../database/data_utils.h"
#include "../database/data_resources.h" //data_clients já tem o include de resources

typedef struct resource Resource;
// Arquivo de database
char* r_ar_name = "database/_resources.dat";

void resources_c(void) {
    Resource* new_resource = (Resource*) malloc(sizeof(Resource));

    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                  Modulo de Recursos - Criacao                 |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
    // Coletar e Verificar o NOME DO RECURSO;
    new_resource->name = (char*) malloc(75*sizeof(char));
    get_name(new_resource->name);
    // Coletar e Verificar a DESCRIÇÃO DO RECURSO;
    new_resource->desc = (char*) malloc(sizeof(char));
    get_desc(new_resource->desc);
    // Coletar e Verificar ONDE ENCONTRAR O RECURSO;
    new_resource->available_at = (char*) malloc(sizeof(char));
    get_available_at(new_resource->available_at);
    printf("-----------------------------------------------------------------\n");
    printf("Nome: %s,\nDescricao: %s,\nDisponivel Em: %s", new_resource->name, new_resource->desc, new_resource->available_at);

    // Criação de arquivos
    if (verify_archive(r_ar_name)) {
        // Se o arquivo existe, apenas adicione.
        r_update_archive(r_ar_name, new_resource);
    } else {
        // Se o arquivo não existe, crie e adicione.
        create_archive(r_ar_name);
        r_update_archive(r_ar_name, new_resource);
    }

    // Liberação de memória dinâmica
    free(new_resource->name);
    free(new_resource->desc);
    free(new_resource->available_at);
    free(new_resource);
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