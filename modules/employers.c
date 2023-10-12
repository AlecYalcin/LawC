#include <stdio.h>
#include "utils.h"

typedef struct employer Employer;

struct employer {
    char name[30];
    char birth_date[12];
    char cpf[12];
    char email[30];
    char tel[12];
    char OAB[30];
    char role[30];
    char desc[200];
};

void employer_c(void) {
    Employer new_employer;

    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|               Modulo de Funcionarios - Criacao                |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
    // Coletar e Verificar nome;
    get_name(new_employer.name);
    // Coletar e Verificar data de nascimento.
    get_birth(new_employer.birth_date);
    // Coletar e Verificar CPF;
    get_cpf(new_employer.cpf);
    // Coletar e Verificar o Email;
    get_email(new_employer.email);
    // Coletar e Verificar o Contato;
    get_tel(new_employer.tel);
    // Coletar e Verificar o OAB;
    get_oab(new_employer.OAB);
    // Coletar e Verificar o CARGO;
    get_role(new_employer.role);
    // Coletar e Verificar o DESCRIÇÃO;
    get_desc(new_employer.desc);

    printf("-----------------------------------------------------------------\n");
    printf("Nome: %s,\nData de Nascimento: %s,\nCPF: %s,\nE-mail: %s,\nTel: %s,\nOAB: %s,\nCargo: %s,\nDescricao: %s", new_employer.name, new_employer.birth_date, new_employer.cpf, new_employer.email, new_employer.tel, new_employer.OAB, new_employer.role, new_employer.desc);
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

