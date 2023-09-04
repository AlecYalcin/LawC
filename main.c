#include <stdio.h>
#include <stdlib.h>

// Declaração de Funções
void menu_main(void);
void menu_system(void);
void menu_project(void);
void menu_devs(void);

void menu_employer(void);
void employer_c(void);
void employer_r(void);
void employer_u(void);
void employer_d(void);
void employer_list(void);

void menu_services(void);
void services_c(void);
void services_r(void);
void services_u(void);
void services_d(void);
void services_list(void);

void menu_resources(void);
void resources_c(void);
void resources_r(void);
void resources_u(void);
void resources_d(void);
void resources_list(void);

/*
    Função feita somente para o "Digite ENTER" 
    Origem: https://github.com/FlaviusGorgonio/LinguaSolta/blob/main/ls.c
*/ 
void exe_breaker(void) {
    char aux;
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    aux = getchar();
}

// Método Main
int main(void) {
    menu_main();
    return 0;
}

// Funções
void menu_main(void) {
    system("clear||cls");

    int option;
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                         UFRN - CERES                          |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                     DCT1106 - Programacao                     |\n");
    printf("|                     Feito por @alecyalcin                     |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|  ,.    .                             ,                   ,-.  |\n");
    printf("| /  \\   |                     o       |                  /     |\n");
    printf("| |--| ,-| . , ,-. ,-. ,-: ,-. . ,-:   |    ,-: , , , --- |     |\n");
    printf("| |  | | | |/  | | |   | | |   | | |   |    | | |/|/      \\     |\n");
    printf("| '  ' `-' '   `-' `-' `-` `-' ' `-`   `--' `-` ' '        `-'  |\n");                                      
    printf("|                                                               |\n");
    printf("|                     1. Sistema Principal                      |\n");
    printf("|                     2. Sobre o Projeto                        |\n");
    printf("|                     3. Desenvolvedores                        |\n");
    printf("|                     0. Sair                                   |\n");
    printf("-----------------------------------------------------------------\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &option);

    switch(option) {
        case 0:
        break;

        case 1:
        menu_system();
        break;

        case 2:
        menu_project();
        break;

        case 3:
        menu_devs();
        break;

        default:
        printf("Valor Invalido!\n");
    }
}

void menu_system(void) {
    system("clear||cls");

    int option;
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                                                               |\n");
    printf("|                     1. Gestao de Funcionarios                 |\n");
    printf("|                     2. Gestao de Servicos                     |\n");
    printf("|                     3. Gestao de Recursos                     |\n");
    printf("|                     4. Gestao de Clientes                     |\n");
    printf("|                     5. Agendamento de Servicos                |\n");
    printf("|                     0. Sair                                   |\n");
    printf("-----------------------------------------------------------------\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &option);

    switch(option) {
        case 0:
        break;

        case 1:
        menu_employer();

        case 2:
        menu_services();

        default:
        printf("Valor Invalido!\n");
    }
}

void menu_project(void) {
    system("clear||cls");

    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                         UFRN - CERES                          |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                     DCT1106 - Programacao                     |\n");
    printf("|                     Feito por @alecyalcin                     |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                                                               |\n");
    printf("| Um Sistema de Gestao para Escritorio de Advocacia que conta   |\n");
    printf("| com diversos Modulos que auxliam os funcionarios a gerenciar  |\n");
    printf("| clientes, casos, consultas, funcionarios e mais.              |\n");
    printf("| Foi desenvolvido utilizando da linguagem C para a disciplina. |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
    exe_breaker();
}

void menu_devs(void) {
    system("clear||cls");

    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                         UFRN - CERES                          |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                     DCT1106 - Programacao                     |\n");
    printf("|                     Feito por @alecyalcin                     |\n");
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                                                               |\n");
    printf("|                     Equipe:  Alec Can Yalcin                  |\n");
    printf("|                     E-mail:  alecyalcin@gmail.com             |\n");
    printf("|                     Git:     alecyalcin                       |\n");
    printf("-----------------------------------------------------------------\n");
    exe_breaker();
}

// MODULO 1 - Funções de Funcionário

void menu_employer(void) {
    system("clear||cls");

    int option;
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                    Modulo de Funcionarios                     |\n");
    printf("|                                                               |\n");
    printf("|                     1. Criar Funcionario                      |\n");
    printf("|                     2. Pesquisar Funcionario                  |\n");
    printf("|                     3. Alterar Funcionario                    |\n");
    printf("|                     4. Excluir Funcionario                    |\n");
    printf("|                     5. Listar Funcionarios                    |\n");
    printf("|                     0. Voltar ao Menu                         |\n");
    printf("-----------------------------------------------------------------\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &option);

    switch(option) {
        case 0:
        break;

        case 1:
        employer_c();
        break;

        case 2:
        employer_r();
        break;

        case 3:
        employer_u();
        break;

        case 4:
        employer_d();
        break;

        case 5:
        employer_list();
        break;

        default:
        printf("Valor Invalido!\n");
        exe_breaker();
    }
    
}

void employer_c(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|               Modulo de Funcionarios - Criacao                |\n");
    printf("|                                                               |\n");
    printf("|                     Nome:                                     |\n");
    printf("|                     Idade:                                    |\n");
    printf("|                     CPF:                                      |\n");
    printf("|                     E-mail:                                   |\n");
    printf("|                     Telefone:                                 |\n");
    printf("|                     ID da OAB (Opcional):                     |\n");
    printf("|                     Cargo:                                    |\n");
    printf("|                     Descricao Profissional:                   |\n");
    printf("-----------------------------------------------------------------\n");
    exe_breaker();
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
    exe_breaker();
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
    exe_breaker();
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
    exe_breaker();
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
    exe_breaker();
}

// MODULO 2 - Funções de Serviços

void menu_services(void) {
    system("clear||cls");

    int option;
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                       Modulo de Servicos                      |\n");
    printf("|                                                               |\n");
    printf("|                     1. Criar Servico                          |\n");
    printf("|                     2. Pesquisar Servico                      |\n");
    printf("|                     3. Alterar Servico                        |\n");
    printf("|                     4. Excluir Servico                        |\n");
    printf("|                     5. Listar Servicos                        |\n");
    printf("|                     0. Voltar ao Menu                         |\n");
    printf("-----------------------------------------------------------------\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &option);

    switch(option) {
        case 0:
        break;

        case 1:
        services_c();
        break;

        case 2:
        services_r();
        break;

        case 3:
        services_u();
        break;

        case 4:
        services_d();
        break;

        case 5:
        services_list();
        break;

        default:
        printf("Valor Invalido!\n");
        exe_breaker();
    }
}

void services_c(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                  Modulo de Servicos - Criacao                 |\n");
    printf("|                                                               |\n");
    printf("|                     Nome:                                     |\n");
    printf("|                     Descricao:                                |\n");
    printf("|                     Valor:                                    |\n");
    printf("-----------------------------------------------------------------\n");
    exe_breaker();
}

void services_r(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                 Modulo de Servicos - Pesquisa                 |\n");
    printf("|                                                               |\n");
    printf("|                     Filtro:(Nome, Valor)                      |\n");
    printf("-----------------------------------------------------------------\n");
    exe_breaker();
}

void services_u(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                 Modulo de Servicos - Alterar                  |\n");
    printf("|                                                               |\n");
    printf("|                     Filtro:(Nome, Valor)                      |\n");
    printf("-----------------------------------------------------------------\n");
    exe_breaker();
}

void services_d(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                 Modulo de Servicos - Excluir                  |\n");
    printf("|                                                               |\n");
    printf("|                         Filtro:(Nome)                         |\n");
    printf("-----------------------------------------------------------------\n");
    exe_breaker();
}

void services_list(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                  Modulo de Servicos - Listar                  |\n");
    printf("|                                                               |\n");
    printf("|                     Filtro:(Nome, Valor)                      |\n");
    printf("-----------------------------------------------------------------\n");
    exe_breaker();
}

// MODULO 3 - Funções de Recursos

void menu_resources(void) {
    system("clear||cls");

    int option;
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                       Modulo de Recursos                      |\n");
    printf("|                                                               |\n");
    printf("|                     1. Criar Recurso                          |\n");
    printf("|                     2. Pesquisar Recurso                      |\n");
    printf("|                     3. Alterar Recurso                        |\n");
    printf("|                     4. Excluir Recurso                        |\n");
    printf("|                     5. Listar Recursos                        |\n");
    printf("|                     0. Voltar ao Menu                         |\n");
    printf("-----------------------------------------------------------------\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &option);

    switch(option) {
        case 0:
        break;

        case 1:
        resources_c();
        break;

        case 2:
        resources_r();
        break;

        case 3:
        resources_u();
        break;

        case 4:
        resources_d();
        break;

        case 5:
        resources_list();
        break;

        default:
        printf("Valor Invalido!\n");
        exe_breaker();
    }
}

void resources_c(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                  Modulo de Recursos - Criacao                 |\n");
    printf("|                                                               |\n");
    printf("|                     Nome:                                     |\n");
    printf("|                     Descricao:                                |\n");
    printf("|                     Disponibilidade:                          |\n");
    printf("-----------------------------------------------------------------\n");
    exe_breaker();
}

void resources_r(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                 Modulo de Recursos - Pesquisa                 |\n");
    printf("|                                                               |\n");
    printf("|                 Filtro:(Nome, Disponibilidade)                |\n");
    printf("-----------------------------------------------------------------\n");
    exe_breaker();
}

void resources_u(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                 Modulo de Recursos - Alterar                  |\n");
    printf("|                                                               |\n");
    printf("|                         Filtro:(Nome)                         |\n");
    printf("-----------------------------------------------------------------\n");
    exe_breaker();
}

void resources_d(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                 Modulo de Recursos - Excluir                  |\n");
    printf("|                                                               |\n");
    printf("|                         Filtro:(Nome)                         |\n");
    printf("-----------------------------------------------------------------\n");
    exe_breaker();
}

void resources_list(void) {
    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                 Modulo de Recursos - Listar                   |\n");
    printf("|                                                               |\n");
    printf("|                         Filtro:(Nome)                         |\n");
    printf("-----------------------------------------------------------------\n");
    exe_breaker();
}