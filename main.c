#include <stdio.h>
#include <stdlib.h>
// Created Modules
#include "modules/employers.h"
#include "modules/resources.h"
#include "modules/services.h"
#include "modules/clients.h"
#include "modules/schedule.h"

// Main Menu Functions
int menu_main(void);
int menu_system(int);
int menu_project(int);
int menu_devs(int);

// Modules Menu Functions
int menu_employer(int);
int menu_services(int);
int menu_resources(int);
int menu_clients(int);
int menu_schedule(int);

/*
    Função feita somente para o "Digite ENTER" 
    Origem: https://github.com/FlaviusGorgonio/LinguaSolta/blob/main/ls.c
*/ 
void exe_breaker(void) {
    fflush(stdin);

    char aux;
    printf("\n>>> Tecle <ENTER> para continuar... <<<\n");
    aux = getchar();
}

// Método Main
int main(void) {
    int option;
    do {
        option = menu_main();

        if (option == 0) {
            printf("\nSaindo do Sistema...\n");
        } else {
            // Entrando em um Novo Loop de Opções
            do {
                if (option == 1) {
                    option = menu_system(option);
                } else if (option == 2) {
                    option = menu_project(option);
                } else if (option == 3) {
                    option = menu_devs(option);
                } else {
                    printf("\nMenu Padrão: Valor Invalido!\n");
                    break;
                }
            } while(option != 0);
            // Definindo qualquer valor diferente de [0,1,2,3] para continuar
            option = 4;
        }
    } while(option != 0);

    return 0;
}

// Funções
int menu_main(void) {
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
    printf("|                     Sistema de Advôcacia                      |\n");
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
    getchar();

    return option;
}

int menu_system(int option) {
    system("clear||cls");

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
    printf("|                     0. Voltar ao Inicio                       |\n");
    printf("-----------------------------------------------------------------\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &option);
    getchar();

    if (option == 0) {
        printf("\nVoltando ao menu...\n");
    } else {
        do {
            if (option == 1) {
                option = menu_employer(option);
            } else if (option == 2) {
                option = menu_services(option);
            } else if (option == 3) {
                option = menu_resources(option);
            } else if (option == 4) {
                option = menu_clients(option);
            } else if (option == 5) {
                option = menu_schedule(option);
            } else {
                printf("\nMenu Sistemas: Valor Invalido!\n");
                break;
            }
        } while(option != 0);
        // Retornando o valor do próprio menu
        option = 1;
    }
    return option;
}

int menu_project(int option) {
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

    return 0;
}

int menu_devs(int option) {
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

    return 0;
}

// MODULO 1 - Funções de Funcionário

int menu_employer(int option) {
    system("clear||cls");

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
    getchar();

    if (option == 0) {
        printf("\nVoltando ao menu de sistema...\n");
        return option;
    } else {
        if (option == 1) {
            employer_c();
        } else if (option == 2) {
            employer_r();
        } else if (option == 3) {
            employer_u();
        } else if (option == 4) {
            employer_d();
        } else if (option == 5) {
            employer_list();
        } else {
            printf("\nMenu Funcionários: Valor Invalido!\n");
        }
    }
    exe_breaker();
    return 1;
}

int menu_resources(int option) {
    system("clear||cls");

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

    if (option == 0) {
        printf("\nVoltando ao menu de sistema...\n");
        return option;
    } else {
        if (option == 1) {
            resources_c();
        } else if (option == 2) {
            resources_r();
        } else if (option == 3) {
            resources_u();
        } else if (option == 4) {
            resources_d();
        } else if (option == 5) {
            resources_list();
        } else {
            printf("\nMenu Recursos: Valor Invalido!\n");
        }
    }

    exe_breaker();
    return 3;
}

int menu_services(int option) {
    system("clear||cls");

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

    if (option == 0) {
        printf("\nVoltando ao menu de sistema...\n");
        return option;
    } else {
        if (option == 1) {
            services_c();
        } else if (option == 2) {
            services_r();
        } else if (option == 3) {
            services_u();
        } else if (option == 4) {
            services_d();
        } else if (option == 5) {
            services_list();
        } else {
            printf("\nMenu de Serviços: Valor Invalido!\n");
        }
    }

    exe_breaker();
    return 2;
}

int menu_clients(int option) {
    system("clear||cls");

    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                      Modulo de Clientes                       |\n");
    printf("|                                                               |\n");
    printf("|                     1. Criar Cliente                          |\n");
    printf("|                     2. Pesquisar Cliente                      |\n");
    printf("|                     3. Alterar Cliente                        |\n");
    printf("|                     4. Excluir Cliente                        |\n");
    printf("|                     5. Listar Clientes                        |\n");
    printf("|                     0. Voltar ao Menu                         |\n");
    printf("-----------------------------------------------------------------\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &option);

    if (option == 0) {
        printf("\nVoltando ao menu de sistema...\n");
        return option;
    } else {
        if (option == 1) {
            clients_c();
        } else if (option == 2) {
            clients_r();
        } else if (option == 3) {
            clients_u();
        } else if (option == 4) {
            clients_d();
        } else if (option == 5) {
            clients_list();
        } else {
            printf("\nMenu de Clientes: Valor Invalido!\n");
        }
    }

    exe_breaker();
    return 4;
}

int menu_schedule(int option) {
    system("clear||cls");

    printf("-----------------------------------------------------------------\n");
    printf("|                                                               |\n");
    printf("|                             Law-C                             |\n");
    printf("|                     Sistema de Advocacia                      |\n");
    printf("|                      Modulo de Agendamentos                   |\n");
    printf("|                                                               |\n");
    printf("|                     1. Criar Agendamento                      |\n");
    printf("|                     2. Pesquisar Agendamento                  |\n");
    printf("|                     3. Alterar Agendamento                    |\n");
    printf("|                     4. Excluir Agendamento                    |\n");
    printf("|                     5. Finalizar Agendamentos                 |\n");
    printf("|                     6. Listar Agendamentos                    |\n");
    printf("|                     7. Calendario de Agendamentos             |\n");
    printf("|                     0. Voltar ao Menu                         |\n");
    printf("-----------------------------------------------------------------\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &option);

    if (option == 0) {
        printf("\nVoltando ao menu de sistema...\n");
        return option;
    } else {
        if (option == 1) {
            schedule_c();
        } else if (option == 2) {
            schedule_r();
        } else if (option == 3) {
            schedule_u();
        } else if (option == 4) {
            schedule_d();
        } else if (option == 5) {
            schedule_end();
        } else if (option == 6) {
            schedule_list();
        } else if (option == 7) {
            schedule_data();
        } else {
            printf("\nMenu de Agendamentos: Valor Invalido!\n");
        }
    }
    
    exe_breaker();
    return 5;
}