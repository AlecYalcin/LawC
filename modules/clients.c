#include <stdio.h>
#include <stdlib.h>
// Created Modules
#include "utils.h"
#include "../database/data_utils.h"
#include "../database/data_clients.h" //data_clients já tem o include de clients

typedef struct cliente Cliente;
// Arquivo de database
char* c_ar_name = "database/_clients.dat";

void clients_c(void)  {
    Cliente* new_client = (Cliente*) malloc(sizeof(Cliente));

    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                  Modulo de Clientes - Criacao                 |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");

    // Coletar e Verificar nome;
    get_name(new_client->name);
    // Coletar e Verificar data de nascimento.
    get_birth(new_client->birth_date);
    // Coletar e Verificar CPF;
    get_cpf(new_client->cpf);
    // Coletar e Verificar o Email;
    get_email(new_client->email);
    // Coletar e Verificar o Contato;
    get_tel(new_client->tel);

    printf("-----------------------------------------------------------------\n");
    printf("Cliente: \n-> Nome: %s,\n-> Data de Nascimento: %s,\n-> CPF: %s,\n-> E-mail: %s\n-> Telefone: %s\n", new_client->name, new_client->birth_date, new_client->cpf, new_client->email, new_client->tel);

    // Criação de arquivos
    if (verify_archive(c_ar_name)) {
        // Se o arquivo existe, apenas adicione.
        c_update_archive(c_ar_name, new_client);
    } else {
        // Se o arquivo não existe, crie e adicione.
        create_archive(c_ar_name);
        c_update_archive(c_ar_name, new_client);
    }

    // Liberação de memória dinâmica
    free(new_client);
}

void clients_r(void)  {
    Cliente* client = (Cliente*) malloc(sizeof(Cliente));
    char* filter = (char*) malloc(12*sizeof(char));

    limpa_buffer();
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                 Modulo de Clientes - Pesquisa                 |\n");
    printf("|                                                               |\n");
    printf("|                         Filtro:(CPF)                          |\n");
    printf("-----------------------------------------------------------------\n");
    printf("Digite o CPF: ");
    fgets(filter, 12, stdin);

    printf("Filter: %s\n", filter);
    
    client = c_read_archive(client, c_ar_name, filter);
    printf("Cliente: \n-> Nome: %s,\n-> Data de Nascimento: %s,\n-> CPF: %s,\n-> E-mail: %s\n-> Telefone: %s\n", client->name, client->birth_date, client->cpf, client->email, client->tel);

    free(filter);
    free(client);
}

void clients_u(void)  {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|               Modulo de Funcionarios - Alterar                |\n");
    printf("|                                                               |\n");
    printf("|                         Filtro:(CPF)                          |\n");
    printf("-----------------------------------------------------------------\n");
}

void clients_d(void)  {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|               Modulo de Funcionarios - Excluir                |\n");
    printf("|                                                               |\n");
    printf("|                         Filtro:(CPF)                          |\n");
    printf("-----------------------------------------------------------------\n");   
}

void clients_list(void)  {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                Modulo de Funcionarios - Listar                |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
}