#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void clients_c(void)  {
    char name[30]; char birth_date[12]; char cpf[12]; char email[30]; char tel[12];

    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                  Modulo de Clientes - Criacao                 |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");

    // Coletar e Verificar nome;
    get_name(name);
    // Coletar e Verificar data de nascimento.
    get_birth(birth_date);
    // Coletar e Verificar CPF;
    get_cpf(cpf);
    // Coletar e Verificar o Email;
    get_email(email);
    // Coletar e Verificar o Contato;
    get_tel(tel);

    printf("-----------------------------------------------------------------\n");
    printf("Cliente: \n-> Nome: %s,\n-> Data de Nascimento: %s,\n-> CPF: %s,\n-> E-mail: %s\n-> Telefone: %s\n", name, birth_date, cpf, email, tel);
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