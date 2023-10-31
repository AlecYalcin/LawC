#include <stdio.h>
#include <stdlib.h>
// Created Modules
#include "utils.h"
#include "../database/data_utils.h"
#include "../database/data_employers.h" //data_clients já tem o include de employers

typedef struct employer Employer;
// Arquivo de database
char* e_ar_name = "database/_employers.dat";

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
    get_name(new_employer->name);
    // Coletar e Verificar data de nascimento.
    get_birth(new_employer->birth_date);
    // Coletar e Verificar CPF;
    get_cpf(new_employer->cpf);
    // Coletar e Verificar o Email;
    get_email(new_employer->email);
    // Coletar e Verificar o Contato;
    get_tel(new_employer->tel);
    // Coletar e Verificar o OAB;
    get_oab(new_employer->OAB);
    // Coletar e Verificar o CARGO;
    get_role(new_employer->role);
    // Coletar e Verificar o DESCRIÇÃO;
    get_desc(new_employer->desc);

    printf("-----------------------------------------------------------------\n");
    printf("Nome: %s,\nData de Nascimento: %s,\nCPF: %s,\nE-mail: %s,\nTel: %s,\nOAB: %s,\nCargo: %s,\nDescricao: %s", new_employer->name, new_employer->birth_date, new_employer->cpf, new_employer->email, new_employer->tel, new_employer->OAB, new_employer->role, new_employer->desc);

    // Criação de arquivos
    if (verify_archive(e_ar_name)) {
        // Se o arquivo existe, apenas adicione.
        e_update_archive(e_ar_name, new_employer);
    } else {
        // Se o arquivo não existe, crie e adicione.
        create_archive(e_ar_name);
        e_update_archive(e_ar_name, new_employer);
    }

    // Liberação de memória dinâmica
    free(new_employer);
}

void employer_r(void) {
    Employer* funcionario = (Employer*) malloc(sizeof(Employer));
    char* filter = (char*) malloc(12*sizeof(char));

    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|               Modulo de Funcionarios - Pesquisa               |\n");
    printf("|                                                               |\n");
    printf("|                         Filtro:(CPF)                          |\n");
    printf("-----------------------------------------------------------------\n");
    printf("Digite o Nome: ");
    scanf("%12[^\n]", filter);

    funcionario = e_read_archive(funcionario, e_ar_name, filter);
    printf("CPF: %s", funcionario->cpf);

    free(filter);
    free(funcionario);
}

void employer_u(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|               Modulo de Funcionarios - Alterar                |\n");
    printf("|                                                               |\n");
    printf("|                         Filtro:(CPF)                          |\n");
    printf("-----------------------------------------------------------------\n");
}

void employer_d(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|               Modulo de Funcionarios - Excluir                |\n");
    printf("|                                                               |\n");
    printf("|                         Filtro:(CPF)                          |\n");
    printf("-----------------------------------------------------------------\n");
}

void employer_list(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                Modulo de Funcionarios - Listar                |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
}

