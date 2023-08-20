#include <stdio.h>
#include <stdlib.h>

// Declaração de Funções
void menu_main(void);
void menu_system(void);
void menu_project(void);
void menu_devs(void);

// Método Main
int main(void) {
    menu_main();
    return 0;
}

// Funções
void menu_main(void) {
    system("clear||cls");

    int option;
    printf("---------------------------------------------\n");
    printf("|                                           |\n");
    printf("|               UFRN - CERES                |\n");
    printf("|                                           |\n");
    printf("---------------------------------------------\n");
    printf("|                                           |\n");
    printf("|           DCT1106 - Programacao           |\n");
    printf("|           Feito por @alecyalcin           |\n");
    printf("|                                           |\n");
    printf("---------------------------------------------\n");
    printf("|                                           |\n");
    printf("|                   Law-C                   |\n");
    printf("|           Sistema de Advocacia            |\n");
    printf("|                                           |\n");
    printf("|        1. Sistema Principal               |\n");
    printf("|        2. Sobre o Projeto                 |\n");
    printf("|        3. Desenvolvedores                 |\n");
    printf("|        0. Sair                            |\n");
    printf("---------------------------------------------\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &option);

    switch(option) {
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
    printf("---------------------------------------------\n");
    printf("|                                           |\n");
    printf("|                   Law-C                   |\n");
    printf("|           Sistema de Advocacia            |\n");
    printf("|                                           |\n");
    printf("|        1. Gestao de Funcionarios          |\n");
    printf("|        2. Gestao de Casos                 |\n");
    printf("|        3. Gestao de Documentos            |\n");
    printf("|        4. Gestao de Recursos              |\n");
    printf("|        5. Agendamento e Calendario        |\n");
    printf("|        0. Sair                            |\n");
    printf("---------------------------------------------\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &option);
}

void menu_project(void) {
    system("clear||cls");

    printf("---------------------------------------------\n");
    printf("|                                           |\n");
    printf("|               UFRN - CERES                |\n");
    printf("|                                           |\n");
    printf("---------------------------------------------\n");
    printf("|                                           |\n");
    printf("|           DCT1106 - Programacao           |\n");
    printf("|           Feito por @alecyalcin           |\n");
    printf("|                                           |\n");
    printf("---------------------------------------------\n");
    printf("|                                           |\n");
    printf("|                   Law-C                   |\n");
    printf("|           Sistema de Advocacia            |\n");
    printf("|                                           |\n");
    printf("| Um Sistema de Gestao para Escritorio de   |\n");
    printf("| Advocacia que conta com diversos Modulos  |\n");
    printf("| que auxiliam os funcionarios a gerenciar  |\n");
    printf("| clientes, casos, consultas, funcionarios  |\n");
    printf("| e mais. Foi desenvolvido utilizando da    |\n");
    printf("| linguagem C para a disciplina DCT1106.    |\n");
    printf("|                                           |\n");
    printf("---------------------------------------------\n");
}

void menu_devs(void) {
    system("clear||cls");

    printf("---------------------------------------------\n");
    printf("|                                           |\n");
    printf("|               UFRN - CERES                |\n");
    printf("|                                           |\n");
    printf("---------------------------------------------\n");
    printf("|                                           |\n");
    printf("|           DCT1106 - Programacao           |\n");
    printf("|           Feito por @alecyalcin           |\n");
    printf("|                                           |\n");
    printf("---------------------------------------------\n");
    printf("|                                           |\n");
    printf("|                   Law-C                   |\n");
    printf("|           Sistema de Advocacia            |\n");
    printf("|                                           |\n");
    printf("|  Equipe:  Alec Can Yalcin                 |\n");
    printf("|  E-mail:  alecyalcin@gmail.com            |\n");
    printf("|  Git:     alecyalcin                      |\n");
    printf("---------------------------------------------\n");
}