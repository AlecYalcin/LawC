#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Created Modules
#include "../utils.h"
#include "../data_utils.h"

// Arquivo de database
char* e_ar_name = "modules/employer/_employers.dat";

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
    get_name(new_employer->name, 1);
    // Coletar e Verificar data de nascimento.
    get_birth(new_employer->birth_date, 1);
    // Coletar e Verificar CPF;
    get_cpf(new_employer->cpf, 0);
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

    printf("\n>>> ------------------------------ <<<\n");
    printf("> Nome....................: %s\n", new_employer->name);
    printf("> Idade...................: %s (%d)\n", new_employer->birth_date, return_age(new_employer->birth_date)); 
    printf("> CPF.....................: %s\n", new_employer->cpf);
    printf("> E-mail..................: %s\n", new_employer->email);
    printf("> Telefone................: %s\n", new_employer->tel);
    printf("> OAB.....................: %s\n", new_employer->OAB);
    printf("> Funcao..................: %s\n", new_employer->role);
    printf("> Descricao...............: %s\n", new_employer->desc);

    // Verificar existencia de empregado parecido
    Employer* aux_employer = e_read_archive(e_ar_name, new_employer->cpf);

    // Criação de arquivos
    if (verify_archive(e_ar_name)) {
        // Se o arquivo existe, apenas adicione.
        if (aux_employer == NULL) {
            e_create_archive(e_ar_name, new_employer);
        } else {
            printf("\n>>> O CPF cadastrado já está em uso, tente outro.");
        }

    } else {
        // Se o arquivo não existe, crie e adicione.
        create_archive(e_ar_name);
        if (aux_employer == NULL) {
            e_create_archive(e_ar_name, new_employer);
        } else {
            printf("\n>>> O CPF cadastrado já está em uso, tente outro.");
        }
    }

    // Liberação de memória dinâmica
    free(new_employer);
    free(aux_employer);
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
        printf("\n >>> Funcionário não encontrado. \n");
    } else {
        printf("\n>>> ------------------------------ <<<\n");
        printf("> Nome....................: %s\n", funcionario->name);
        printf("> Idade................: %s (%d)\n", funcionario->birth_date, return_age(funcionario->birth_date)); 
        printf("> CPF.....................: %s\n", funcionario->cpf);
        printf("> E-mail..................: %s\n", funcionario->email);
        printf("> Telefone................: %s\n", funcionario->tel);
        printf("> OAB.....................: %s\n", funcionario->OAB);
        printf("> Funcao..................: %s\n", funcionario->role);
        printf("> Descricao...............: %s\n", funcionario->desc);

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
        printf("\n>>> Funcionário não encontrado. \n");
    } else {
        printf("\n>>> ------------------------------ <<<\n");
        printf("> Nome....................: %s\n", funcionario->name);
        printf("> Idade................: %s (%d)\n", funcionario->birth_date, return_age(funcionario->birth_date)); 
        printf("> CPF.....................: %s\n", funcionario->cpf);
        printf("> E-mail..................: %s\n", funcionario->email);
        printf("> Telefone................: %s\n", funcionario->tel);
        printf("> OAB.....................: %s\n", funcionario->OAB);
        printf("> Funcao..................: %s\n", funcionario->role);
        printf("> Descricao...............: %s\n", funcionario->desc);

        printf("\n>>> Preencher as Novas Informacoes <<<\n");
        // Coletar e Verificar nome;
        get_name(funcionario->name, 1);
        // Coletar e Verificar data de nascimento.
        get_birth(funcionario->birth_date, 1);
        // Coletar e Verificar CPF;
        get_cpf(funcionario->cpf, 0);
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

        printf("\n>>> ------------------------------ <<<\n");
        printf("> Nome....................: %s\n", funcionario->name);
        printf("> Idade................: %s (%d)\n", funcionario->birth_date, return_age(funcionario->birth_date)); 
        printf("> CPF.....................: %s\n", funcionario->cpf);
        printf("> E-mail..................: %s\n", funcionario->email);
        printf("> Telefone................: %s\n", funcionario->tel);
        printf("> OAB.....................: %s\n", funcionario->OAB);
        printf("> Funcao..................: %s\n", funcionario->role);
        printf("> Descricao...............: %s\n", funcionario->desc);

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
        printf("\n>>> Funcionário não encontrado. \n");
    } else {
        // Excluindo o arquivo
        e_delete_archive(e_ar_name, funcionario);  
    }
}

void employer_list(void) {
    int choice;

    limpa_buffer();
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                Modulo de Funcionarios - Listar                |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
    printf("[1] - Sem Filtro, Listagem Geral\n");
    printf("[2] - Filtro de Idade\n");
    printf("[3] - Filtro de Nome\n");
    printf("Digite o Numero do Filtro: ");
    scanf("%d", &choice);
    getchar();
    
    e_list_archive(e_ar_name, choice);
}

