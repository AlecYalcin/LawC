#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "clients.h"

typedef struct cliente Cliente;

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
    new_client->name = (char*) malloc(sizeof(char));
    get_name(new_client->name);
    // Coletar e Verificar data de nascimento.
    get_birth(new_client->birth_date);
    // Coletar e Verificar CPF;
    get_cpf(new_client->cpf);
    // Coletar e Verificar o Email;
    new_client->email = (char*) malloc(sizeof(char));
    get_email(new_client->email);
    // Coletar e Verificar o Contato;
    get_tel(new_client->tel);

    printf("-----------------------------------------------------------------\n");
    printf("Cliente: \n-> Nome: %s,\n-> Data de Nascimento: %s,\n-> CPF: %s,\n-> E-mail: %s\n-> Telefone: %s\n", new_client->name, new_client->birth_date, new_client->cpf, new_client->email, new_client->tel);

    // Liberação de memória dinâmica
    free(new_client->name);
    free(new_client->email);
    free(new_client);
}

void clients_r(void)  {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                 Modulo de Clientes - Pesquisa                 |\n");
    printf("|                                                               |\n");
    printf("|              Filtro:(CPF, Nome, E-mail, Telefone)             |\n");
    printf("-----------------------------------------------------------------\n");
}

void clients_u(void)  {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|               Modulo de Funcionarios - Alterar                |\n");
    printf("|                                                               |\n");
    printf("|              Filtro:(CPF, Nome, E-mail, Telefone)             |\n");
    printf("-----------------------------------------------------------------\n");
}

void clients_d(void)  {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|               Modulo de Funcionarios - Excluir                |\n");
    printf("|                                                               |\n");
    printf("|              Filtro:(CPF, Nome, E-mail, Telefone)             |\n");
    printf("-----------------------------------------------------------------\n");   
}

void clients_list(void)  {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                Modulo de Funcionarios - Listar                |\n");
    printf("|                                                               |\n");
    printf("|              Filtro:(CPF, Nome, E-mail, Telefone)             |\n");
    printf("-----------------------------------------------------------------\n");
}