#include <stdio.h>
#include "utils.h"

void employer_c(void) {
    char name[30]; char birth_date[11]; char cpf[12]; char email[30]; double tel; char OAB[15]; char role[30]; char desc[200];

    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|               Modulo de Funcionarios - Criacao                |\n");
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
    get_tel(&tel);
    // Coletar e Verificar o OAB;
    get_oab(OAB);
    // Coletar e Verificar o CARGO;
    get_role(role);
    // Coletar e Verificar o DESCRIÇÃO;
    get_desc(desc);

    printf("-----------------------------------------------------------------\n");
    printf("Nome: %s,\nData de Nascimento: %s,\nCPF: %s,\nE-mail: %s,\nTel: %.lf,\nOAB: %s,\nCargo: %s,\nDescricao: %s", name, birth_date, cpf, email, tel, OAB, role, desc);
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

