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
    get_name(new_resource->name);
    // Coletar e Verificar a DESCRIÇÃO DO RECURSO;
    get_desc(new_resource->desc);
    // Coletar e Verificar ONDE ENCONTRAR O RECURSO;
    get_available_at(new_resource->available_at);
    // Alterar Status
    new_resource->status = 1;

    printf("\n>>> ------------------------------ <<<\n");
    printf("> Recurso.................: %s\n", new_resource->name);
    printf("> Descricao...............: %s\n", new_resource->desc);
    printf("> Disponivel Em...........: %s\n", new_resource->available_at);

    // Verificar existencia de cliente parecido
    Resource* aux_resource = r_read_archive(r_ar_name, new_resource->name);

    // Criação de arquivos
    if (verify_archive(r_ar_name)) {
        // Se o arquivo existe, apenas adicione.
        if (aux_resource == NULL) {
            r_create_archive(r_ar_name, new_resource);
        } else {
            printf("\n>>> O Recurso cadastrado já existe.");
        }

    } else {
        // Se o arquivo não existe, crie e adicione.
        create_archive(r_ar_name);
        if (aux_resource == NULL) {
            r_create_archive(r_ar_name, new_resource);
        } else {
            printf("\n>>> O Recurso cadastrado já existe.");
        }
    }

    // Liberação de memória dinâmica
    free(new_resource);
    free(aux_resource);
}

void resources_r(void) {
    Resource* resource;
    char filter[51];

    limpa_buffer();
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                 Modulo de Recursos - Pesquisa                 |\n");
    printf("|                                                               |\n");
    printf("|                         Filtro:(Nome)                         |\n");
    printf("-----------------------------------------------------------------\n");
    printf("Digite o Nome: ");
    // Pegando dados e alterando
    fgets(filter, 51, stdin);
    change_last(filter);
    // Procurando os dados nos arquivos
    resource = r_read_archive(r_ar_name, filter);
    if (resource == NULL) {
        printf("Recurso não encontrado. \n");
    } else {
        printf("\n>>> ------------------------------ <<<\n");
        printf("> Recurso.................: %s\n", resource->name);
        printf("> Descricao...............: %s\n", resource->desc);
        printf("> Disponivel Em...........: %s\n", resource->available_at);
        
        free(resource);
    }

}

void resources_u(void) {
    Resource* resource;
    char filter[51];

    limpa_buffer();
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                 Modulo de Recursos - Alterar                  |\n");
    printf("|                                                               |\n");
    printf("|                         Filtro:(Nome)                         |\n");
    printf("-----------------------------------------------------------------\n");
    printf("Digite o Nome: ");
    // Pegando dados e alterando
    fgets(filter, 51, stdin);
    change_last(filter);
    // Procurando os dados nos arquivos
    resource = r_read_archive(r_ar_name, filter);
    if (resource == NULL) {
        printf("Recurso não encontrado. \n");
    } else {
        printf("\n>>> ------------------------------ <<<\n");
        printf("> Recurso.................: %s\n", resource->name);
        printf("> Descricao...............: %s\n", resource->desc);
        printf("> Disponivel Em...........: %s\n", resource->available_at);
        
        printf("\n>>> Preencher as Novas Informacoes <<<\n");
        // Coletar e Verificar o NOME DO RECURSO;
        get_name(resource->name);
        // Coletar e Verificar a DESCRIÇÃO DO RECURSO;
        get_desc(resource->desc);
        // Coletar e Verificar ONDE ENCONTRAR O RECURSO;
        get_available_at(resource->available_at);

        printf("\n>>> ------------------------------ <<<\n");
        printf("> Recurso.................: %s\n", resource->name);
        printf("> Descricao...............: %s\n", resource->desc);
        printf("> Disponivel Em...........: %s\n", resource->available_at);     

        r_update_archive(r_ar_name, filter, resource);
    }

}

void resources_d(void) {
    Resource* resource = (Resource*) malloc(sizeof(Resource));
    char filter[51];

    limpa_buffer();
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                 Modulo de Recursos - Excluir                  |\n");
    printf("|                                                               |\n");
    printf("|                         Filtro:(Nome)                         |\n");
    printf("-----------------------------------------------------------------\n");
    printf("Digite o Nome do Recurso: ");
    // Pegando dados e alterando
    fgets(filter, 51, stdin);
    change_last(filter);
    // Procurando os dados nos arquivos
    resource = r_read_archive(r_ar_name, filter);
    if (resource == NULL) {
        printf("\n>>> Recurso não encontrado. \n");
    } else {
        // Excluindo o arquivo
        r_delete_archive(r_ar_name, resource);  
    }
}

void resources_list(void) {
    limpa_buffer();
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                 Modulo de Recursos - Listar                   |\n");
    printf("|                                                               |\n");
    printf("|                         Filtro:(Nome)                         |\n");
    printf("-----------------------------------------------------------------\n");
    r_list_archive(r_ar_name);
}