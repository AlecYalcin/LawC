#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    // Alterar status
    new_employer->status = 1;

    // Criação de arquivos
    if (verify_archive(e_ar_name)) {
        // Se o arquivo existe, apenas adicione.
        e_create_archive(e_ar_name, new_employer);
    } else {
        // Se o arquivo não existe, crie e adicione.
        create_archive(e_ar_name);
        e_create_archive(e_ar_name, new_employer);
    }

    // Liberação de memória dinâmica
    free(new_employer);
}

void employer_r(void) {
    Employer* funcionario;
    char filter[13];

    limpa_buffer();
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|               Modulo de Funcionarios - Pesquisa               |\n");
    printf("|                                                               |\n");
    printf("|                         Filtro:(CPF)                          |\n");
    printf("-----------------------------------------------------------------\n");
    printf("Digite o CPF: ");
    // Pegando dados e alterando
    fgets(filter, 13, stdin);
    change_last(filter);
    // Procurando os dados nos arquivos
    funcionario = e_read_archive(e_ar_name, filter);
    if (funcionario == NULL) {
        printf("\n >>> Funcionario não encontrado. \n");
    } else {
        printf("\n\n>>> ------------------------------ <<<");
        printf("\n> Nome....................: %s", funcionario->name);
        printf("\n> Idade...................: %s", funcionario->birth_date);
        printf("\n> CPF.....................: %s", funcionario->cpf);
        printf("\n> E-mail..................: %s", funcionario->email);
        printf("\n> Telefone................: %s", funcionario->tel);
        printf("\n> OAB.....................: %s", funcionario->OAB);
        printf("\n> Funcao..................: %s", funcionario->role);
        printf("\n> Descricao...............: %s", funcionario->desc);

        free(funcionario);
    }

}

void employer_u(void) { 
    Employer* funcionario = (Employer*) malloc(sizeof(Employer));
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
    funcionario = e_read_archive(e_ar_name, filter);
    if (funcionario == NULL) {
        printf("Funcionario não encontrado. \n");
    } else {
        printf("\n\n>>> ------------------------------ <<<");
        printf("\n> Nome....................: %s", funcionario->name);
        printf("\n> Idade...................: %s", funcionario->birth_date);
        printf("\n> CPF.....................: %s", funcionario->cpf);
        printf("\n> E-mail..................: %s", funcionario->email);
        printf("\n> Telefone................: %s", funcionario->tel);
        printf("\n> OAB.....................: %s", funcionario->OAB);
        printf("\n> Funcao..................: %s", funcionario->role);
        printf("\n> Descricao...............: %s", funcionario->desc);

        printf("\n\n>>> Preencher as Novas Informacoes <<<\n");
        // Coletar e Verificar nome;
        get_name(funcionario->name);
        // Coletar e Verificar data de nascimento.
        get_birth(funcionario->birth_date);
        // Coletar e Verificar CPF;
        get_cpf(funcionario->cpf);
        // Coletar e Verificar o Email;
        get_email(funcionario->email);
        // Coletar e Verificar o Contato;
        get_tel(funcionario->tel);
        // Coletar e Verificar o OAB;
        get_oab(funcionario->OAB);
        // Coletar e Verificar o CARGO;
        get_role(funcionario->role);
        // Coletar e Verificar o DESCRIÇÃO;
        get_desc(funcionario->desc);

        printf("\n\n>>> ------------------------------ <<<");
        printf("\n> Nome....................: %s", funcionario->name);
        printf("\n> Idade...................: %s", funcionario->birth_date);
        printf("\n> CPF.....................: %s", funcionario->cpf);
        printf("\n> E-mail..................: %s", funcionario->email);
        printf("\n> Telefone................: %s", funcionario->tel);
        printf("\n> OAB.....................: %s", funcionario->OAB);
        printf("\n> Funcao..................: %s", funcionario->role);
        printf("\n> Descricao...............: %s", funcionario->desc);

        e_update_archive(e_ar_name, filter, funcionario);
    }
    
}

void employer_d(void) {
    Employer* funcionario = (Employer*) malloc(sizeof(Employer));
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
    funcionario = e_read_archive(e_ar_name, filter);
    if (funcionario == NULL) {
        printf("Funcionario não encontrado. \n");
    } else {
        // Excluindo o arquivo
        e_delete_archive(e_ar_name, funcionario);  
    }
}

void employer_list(void) {
    limpa_buffer();
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                Modulo de Funcionarios - Listar                |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
    e_list_archive(e_ar_name);
}

