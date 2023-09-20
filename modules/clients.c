#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


void clients_c(void)  {
    char name[30]; int  age; int cpf; char email[30]; int tel;

    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                  Modulo de Clientes - Criacao                 |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
    printf(">  Nome: \t");
    verify_name(name);

    printf(">  Idade: \t");
    scanf(" %d", &age);
    getchar();

    printf(">  CPF (Somente Numeros): \t");
    scanf(" %d", &cpf);
    getchar();

    printf(">  E-mail: \t");
    scanf(" %s", email);

    printf(">  Telefone (Somente Números): \t");
    scanf(" %d", &tel);
    getchar();

    printf("-----------------------------------------------------------------\n");
    printf("Cliente: \n-> Nome: %s,\n-> Idade: %d,\n-> CPF: %d,\n-> E-mail: %s\n-> Telefone: %d\n", name, age, cpf, email, tel);
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