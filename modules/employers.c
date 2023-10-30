#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "employers.h"

typedef struct employer Employer;

void employer_c(void) {
    Employer* new_employer = (Employer*) malloc(sizeof(Employer));

    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|               Modulo de Funcionarios - Criacao                |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
    // Coletar e Verificar nome;
    new_employer->name = (char*) malloc(75*sizeof(char));
    get_name(new_employer->name);
    // Coletar e Verificar data de nascimento.
    get_birth(new_employer->birth_date);
    // Coletar e Verificar CPF;
    get_cpf(new_employer->cpf);
    // Coletar e Verificar o Email;
    new_employer->email = (char*) malloc(75*sizeof(char));
    get_email(new_employer->email);
    // Coletar e Verificar o Contato;
    get_tel(new_employer->tel);
    // Coletar e Verificar o OAB;
    new_employer->OAB = (char*) malloc(50*sizeof(char));
    get_oab(new_employer->OAB);
    // Coletar e Verificar o CARGO;
    new_employer->role = (char*) malloc(50*sizeof(char));
    get_role(new_employer->role);
    // Coletar e Verificar o DESCRIÇÃO;
    new_employer->desc = (char*) malloc(sizeof(char));
    get_desc(new_employer->desc);

    printf("-----------------------------------------------------------------\n");
    printf("Nome: %s,\nData de Nascimento: %s,\nCPF: %s,\nE-mail: %s,\nTel: %s,\nOAB: %s,\nCargo: %s,\nDescricao: %s", new_employer->name, new_employer->birth_date, new_employer->cpf, new_employer->email, new_employer->tel, new_employer->OAB, new_employer->role, new_employer->desc);

    // Liberação de memória dinâmica
    free(new_employer->name);
    free(new_employer->email);
    free(new_employer->OAB);
    free(new_employer->role);
    free(new_employer->desc);
    free(new_employer);
}

void employer_r(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|               Modulo de Funcionarios - Pesquisa               |\n");
    printf("|                                                               |\n");
    printf("|                 Filtro:(CPF, Nome, ID, Cargo)                 |\n");
    printf("-----------------------------------------------------------------\n");
}

void employer_u(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|               Modulo de Funcionarios - Alterar                |\n");
    printf("|                                                               |\n");
    printf("|                 Filtro:(CPF, Nome, ID, Cargo)                 |\n");
    printf("-----------------------------------------------------------------\n");
}

void employer_d(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|               Modulo de Funcionarios - Excluir                |\n");
    printf("|                                                               |\n");
    printf("|                 Filtro:(CPF, Nome, ID, Cargo)                 |\n");
    printf("-----------------------------------------------------------------\n");
}

void employer_list(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                Modulo de Funcionarios - Listar                |\n");
    printf("|                                                               |\n");
    printf("|                 Filtro:(CPF, Nome, ID, Cargo)                 |\n");
    printf("-----------------------------------------------------------------\n");
}

