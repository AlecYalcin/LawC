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
    // Adicionar Status
    new_client->status = 1;

    printf("\n\n>>> ------------------------------ <<<");
    printf("\n> Nome.................: %s", new_client->name);
    printf("\n> Idade................: %s", new_client->birth_date);
    printf("\n> CPF..................: %s", new_client->cpf);
    printf("\n> Email................: %s", new_client->email);
    printf("\n> Telefone.............: %s", new_client->tel);


    // Criação de arquivos
    if (verify_archive(c_ar_name)) {
        // Se o arquivo existe, apenas adicione.
        c_create_archive(c_ar_name, new_client);
    } else {
        // Se o arquivo não existe, crie e adicione.
        create_archive(c_ar_name);
        c_create_archive(c_ar_name, new_client);
    }

    // Liberação de memória dinâmica
    free(new_client);
}

void clients_r(void)  {
    Cliente* cliente;
    char filter[13];

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
    // Pegando dados e alterando
    fgets(filter, 13, stdin);
    change_last(filter);
    // Procurando os dados nos arquivos
    cliente = c_read_archive(c_ar_name, filter);
    if (cliente == NULL) {
        printf("Cliente não encontrado. \n");
    } else {
        printf("\n\n>>> ------------------------------ <<<");
        printf("\n> Nome.................: %s", cliente->name);
        printf("\n> Idade................: %s", cliente->birth_date);
        printf("\n> CPF..................: %s", cliente->cpf);
        printf("\n> Email................: %s", cliente->email);
        printf("\n> Telefone.............: %s", cliente->tel);

        free(cliente);
    }
}

void clients_u(void)  {
    Cliente* cliente;
    char filter[13];

    limpa_buffer();
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|               Modulo de Funcionarios - Alterar                |\n");
    printf("|                                                               |\n");
    printf("|                         Filtro:(CPF)                          |\n");
    printf("-----------------------------------------------------------------\n");
    printf("Digite o CPF: ");
    // Pegando dados e alterando
    fgets(filter, 13, stdin);
    change_last(filter);
    // Procurando os dados nos arquivos
    cliente = c_read_archive(c_ar_name, filter);
    if (cliente == NULL) {
        printf("Cliente não encontrado. \n");
    } else {
        printf("\n\n>>> ------------------------------ <<<");
        printf("\n> Nome.................: %s", cliente->name);
        printf("\n> Idade................: %s", cliente->birth_date);
        printf("\n> CPF..................: %s", cliente->cpf);
        printf("\n> Email................: %s", cliente->email);
        printf("\n> Telefone.............: %s", cliente->tel);

        printf("\n\n>>> Preencher as Novas Informacoes <<<\n");
        // Coletar e Verificar nome;
        get_name(cliente->name);
        // Coletar e Verificar data de nascimento.
        get_birth(cliente->birth_date);
        // Coletar e Verificar CPF;
        get_cpf(cliente->cpf);
        // Coletar e Verificar o Email;
        get_email(cliente->email);
        // Coletar e Verificar o Contato;
        get_tel(cliente->tel);

        printf("\n\n>>> ------------------------------ <<<");
        printf("\n> Nome.................: %s", cliente->name);
        printf("\n> Idade................: %s", cliente->birth_date);
        printf("\n> CPF..................: %s", cliente->cpf);
        printf("\n> Email................: %s", cliente->email);
        printf("\n> Telefone.............: %s", cliente->tel);

        c_update_archive(c_ar_name, filter, cliente);
    }
}

void clients_d(void)  {
    Cliente* cliente = (Cliente*) malloc(sizeof(Cliente));
    char filter[13];

    limpa_buffer();
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|               Modulo de Funcionarios - Excluir                |\n");
    printf("|                                                               |\n");
    printf("|                         Filtro:(CPF)                          |\n");
    printf("-----------------------------------------------------------------\n");   
    printf("Digite o CPF: ");
    // Pegando dados e alterando
    fgets(filter, 13, stdin);
    change_last(filter);
    // Procurando os dados nos arquivos
    cliente = c_read_archive(c_ar_name, filter);
    if (cliente == NULL) {
        printf("Cliente não encontrado. \n");
    } else {
        // Excluindo o arquivo
        c_delete_archive(c_ar_name, cliente);  
    }
}

void clients_list(void)  {
    limpa_buffer();
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                Modulo de Funcionarios - Listar                |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
    c_list_archive(c_ar_name);
}