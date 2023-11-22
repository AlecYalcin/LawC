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
    get_name(new_client->name, 1);
    // Coletar e Verificar data de nascimento.
    get_birth(new_client->birth_date, 1);
    // Coletar e Verificar CPF;
    get_cpf(new_client->cpf, 0);
    // Coletar e Verificar o Email;
    get_email(new_client->email);
    // Coletar e Verificar o Contato;
    get_tel(new_client->tel);
    // Adicionar Status
    new_client->status = 1;

    printf("\n>>> ------------------------------ <<<\n");
    printf("> Nome.................: %s\n", new_client->name);
    printf("> Idade................: %s (%d)\n", new_client->birth_date, return_age(new_client->birth_date)); 
    printf("> CPF..................: %s\n", new_client->cpf);
    printf("> Email................: %s\n", new_client->email);
    printf("> Telefone.............: %s\n", new_client->tel);

    // Verificar existencia de cliente parecido
    Cliente* aux_client = c_read_archive(c_ar_name, new_client->cpf);

    // Criação de arquivos
    if (verify_archive(c_ar_name)) {
        // Se o arquivo existe, apenas adicione.
        if (aux_client == NULL) {
            c_create_archive(c_ar_name, new_client);
        } else {
            printf("\n>>> O CPF cadastrado já está em uso, tente outro.");
        }
    } else {
        // Se o arquivo não existe, crie e adicione.
        create_archive(c_ar_name);
        if (aux_client == NULL) {
            c_create_archive(c_ar_name, new_client);
        } else {
            printf("\n>>> CPF cadastrado já está em uso, tente outro.");
        }
    }

    // Liberação de memória dinâmica
    free(new_client);
    free(aux_client);
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
    printf("-----------------------------------------------------------------\n");
    printf("Digite o CPF: ");
    // Pegando dados e alterando
    fgets(filter, 13, stdin);
    change_last(filter);
    // Procurando os dados nos arquivos
    cliente = c_read_archive(c_ar_name, filter);
    if (cliente == NULL) {
        printf("\n>>> Cliente não encontrado. \n");
    } else {
        printf("\n>>> ------------------------------ <<<\n");
        printf("> Nome.................: %s\n", cliente->name);
        printf("> Idade................: %s (%d)\n", cliente->birth_date, return_age(cliente->birth_date)); 
        printf("> CPF..................: %s\n", cliente->cpf);
        printf("> Email................: %s\n", cliente->email);
        printf("> Telefone.............: %s\n", cliente->tel);

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
    printf("-----------------------------------------------------------------\n");
    printf("Digite o CPF: ");
    // Pegando dados e alterando
    fgets(filter, 13, stdin);
    change_last(filter);
    // Procurando os dados nos arquivos
    cliente = c_read_archive(c_ar_name, filter);
    if (cliente == NULL) {
        printf("\n>>> Cliente não encontrado. \n");
    } else {
        printf("\n>>> ------------------------------ <<<\n");
        printf("> Nome.................: %s\n", cliente->name);
        printf("> Idade................: %s (%d)\n", cliente->birth_date, return_age(cliente->birth_date)); 
        printf("> CPF..................: %s\n", cliente->cpf);
        printf("> Email................: %s\n", cliente->email);
        printf("> Telefone.............: %s\n", cliente->tel);

        printf("\n>>> Preencher as Novas Informacoes <<<\n");
        // Coletar e Verificar nome;
        get_name(cliente->name, 1);
        // Coletar e Verificar data de nascimento.
        get_birth(cliente->birth_date, 1);
        // Coletar e Verificar CPF;
        get_cpf(cliente->cpf, 0);
        // Coletar e Verificar o Email;
        get_email(cliente->email);
        // Coletar e Verificar o Contato;
        get_tel(cliente->tel);

        printf("\n>>> ------------------------------ <<<\n");
        printf("> Nome.................: %s\n", cliente->name);
        printf("> Idade................: %s (%d)\n", cliente->birth_date, return_age(cliente->birth_date)); 
        printf("> CPF..................: %s\n", cliente->cpf);
        printf("> Email................: %s\n", cliente->email);
        printf("> Telefone.............: %s\n", cliente->tel);

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
    printf("-----------------------------------------------------------------\n");   
    printf("Digite o CPF: ");
    // Pegando dados e alterando
    fgets(filter, 13, stdin);
    change_last(filter);
    // Procurando os dados nos arquivos
    cliente = c_read_archive(c_ar_name, filter);
    if (cliente == NULL) {
        printf("\n>>> Cliente não encontrado. \n");
    } else {
        // Excluindo o arquivo
        c_delete_archive(c_ar_name, cliente);  
    }
}

void clients_list(void)  {
    int choice;

    limpa_buffer();
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                Modulo de Funcionarios - Listar                |\n");
    printf("|                      Selecione o Filtro!                      |\n");
    printf("-----------------------------------------------------------------\n");
    printf("[1] - Sem Filtro, Listagem Geral\n");
    printf("[2] - Filtro de Idade\n");
    printf("[3] - Filtro de Nome\n");
    printf("Digite o Numero do Filtro: ");
    scanf("%d", &choice);
    getchar();

    c_list_archive(c_ar_name, choice);
}