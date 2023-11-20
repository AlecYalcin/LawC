#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
// Created Modules
#include "../modules/employers.h"
#include "../database/data_utils.h"

// Atualização (Create) de Arquivos
void e_create_archive(char *ar_name, Employer *employer) { 
    FILE *fp;

    fp = fopen(ar_name, "ab");

    if (!(fp == NULL)) {
        fwrite(employer, sizeof(Employer), 1, fp);
        printf("\n>>> Adicionando informacao... <<<\n");
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }
}

// Leitura (Read) de Arquivos
Employer* e_read_archive(char *ar_name, char *filter) {
    FILE *fp;
    Employer* emp_aux = (Employer*) malloc(sizeof(Employer));

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {

        while(!feof(fp)) {
            // Lendo o Arquivo
            fread(emp_aux, sizeof(Employer), 1, fp);
            // Comparando as Strings
            if (strcmp(emp_aux->cpf, filter) == 0 && emp_aux->status != 0) {
                fclose(fp);

                printf("\n>>> Funcionário encontrado! <<<\n");
                return emp_aux;
            }
        }

        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }

    free(emp_aux);
    return NULL;
}

// Alteração (Update) de Arquivos
void e_update_archive(char *ar_name, char *filter, Employer* new_funcionario) {
    FILE *fp;
    Employer* emp_aux = (Employer*) malloc(sizeof(Employer));

    fp = fopen(ar_name, "r+b");

    if (!(fp == NULL)) {

        while(!feof(fp)) {
            // Lendo o Arquivo
            fread(emp_aux, sizeof(Employer), 1, fp);
            // Comparando as Strings
            if (strcmp(emp_aux->cpf, filter) == 0 && emp_aux->status != 0) {
                // Após encontrar, alterar a localização do ponteiro
                fseek(fp, -1*sizeof(Employer), SEEK_CUR);
                // Tendo reposicionado o ponteiro, atualizar.
                fwrite(new_funcionario, sizeof(Employer), 1, fp);
                
                printf("\n>>> Funcionário alterado! <<<\n");
                break;
            }
        }
 
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }

    free(emp_aux);
}

// Excluir (Delete) de Arquivos
void e_delete_archive(char *ar_name, Employer* employer) {
    FILE *fp;
    Employer* emp_aux = (Employer*) malloc(sizeof(Employer));

    fp = fopen(ar_name, "r+b");

    if (!(fp == NULL)) {
        while(!feof(fp)) {
            // Lendo o Arquivo
            fread(emp_aux, sizeof(Employer), 1, fp);
            // Comparando as Strings
            if (strcmp(employer->cpf, emp_aux->cpf) == 0 && emp_aux->status != 0) {
                employer->status = 0;
                // Após encontrar, alterar a localização do ponteiro
                fseek(fp, -1*sizeof(Employer), SEEK_CUR);
                // Tendo reposicionado o ponteiro, atualizar.
                fwrite(employer, sizeof(Employer), 1, fp);
                
                printf("\n>>> Funcionário excluído! <<<\n");
                break;
            }
        }

        // Fechando os arquivos
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }

    free(employer);
    free(emp_aux);
}

// Listagem (List) de Arquivos
void e_list_archive(char *ar_name, int fil_choice) {
    FILE *fp;
    Employer* emp_aux = (Employer*) malloc(sizeof(Employer));

    fp = fopen(ar_name, "rb");

    if (!(fp == NULL)) {
        char ord; int num;
        char* name = (char*) malloc(sizeof(char));

        // Coletando os Dados de Filtro
        if (fil_choice == 2) {
            int aux = 1;

            while(aux) {
                printf("\n> Para filtrar por idade, por favor digite na seguinte ordem:\n");
                printf("> [>Numero] - Maior ou igual a Numero, Ex: >5, >27, >60\n");
                printf("> [<Numero] - Menor ou igual a Numero, Ex: <6, <60, <35\n");
                printf("> Qualquer outra ordem sera considerada invalida.\n");
                printf("\n> Digite a Ordem ('>' ou '<').....: ");
                scanf(" %c", &ord);

                if (!(ord == '>' || ord == '<')) {
                    printf("\n>>> Ordem invalida. \n");
                } else {
                    printf("\n> Digite o numero.................: ");
                    scanf("%d", &num); getchar();
                    aux = 0;
                }
            }
        } else if (fil_choice == 3) {
            printf("> Nome a Pesquisar................: ");
            fgets(name, 51, stdin);
            change_last_2(name);
        }

        while(fread(emp_aux, sizeof(Employer), 1, fp)) {
            // Filtro A - Listagem Completa
            if (emp_aux->status != 0 && fil_choice == 1) {
                printf("\n>>> ------------------------------ <<<\n");
                printf("> Nome....................: %s\n", emp_aux->name);
                printf("> Idade...................: %s (%d)\n", emp_aux->birth_date, return_age(emp_aux->birth_date)); 
                printf("> CPF.....................: %s\n", emp_aux->cpf);
                printf("> E-mail..................: %s\n", emp_aux->email);
                printf("> Telefone................: %s\n", emp_aux->tel);
                printf("> OAB.....................: %s\n", emp_aux->OAB);
                printf("> Funcao..................: %s\n", emp_aux->role);
                printf("> Descricao...............: %s\n", emp_aux->desc);
            // Filtro B - Listagem por Idade
            } else if (emp_aux->status != 0 && fil_choice == 2) {
                if (ord == '>') {
                    if (return_age(emp_aux->birth_date) >= num) {
                        printf("\n>>> ------------------------------ <<<\n");
                        printf("> Nome....................: %s\n", emp_aux->name);
                        printf("> Idade...................: %s (%d)\n", emp_aux->birth_date, return_age(emp_aux->birth_date)); 
                        printf("> CPF.....................: %s\n", emp_aux->cpf);
                        printf("> E-mail..................: %s\n", emp_aux->email);
                        printf("> Telefone................: %s\n", emp_aux->tel);
                        printf("> OAB.....................: %s\n", emp_aux->OAB);
                        printf("> Funcao..................: %s\n", emp_aux->role);
                        printf("> Descricao...............: %s\n", emp_aux->desc);
                    } 
                } else if(ord == '<') {
                    if (return_age(emp_aux->birth_date) <= num) {
                        printf("\n>>> ------------------------------ <<<\n");
                        printf("> Nome....................: %s\n", emp_aux->name);
                        printf("> Idade...................: %s (%d)\n", emp_aux->birth_date, return_age(emp_aux->birth_date)); 
                        printf("> CPF.....................: %s\n", emp_aux->cpf);
                        printf("> E-mail..................: %s\n", emp_aux->email);
                        printf("> Telefone................: %s\n", emp_aux->tel);
                        printf("> OAB.....................: %s\n", emp_aux->OAB);
                        printf("> Funcao..................: %s\n", emp_aux->role);
                        printf("> Descricao...............: %s\n", emp_aux->desc);
                    }
                }
            // Filtro C - Listagem por Idade
            } else if (emp_aux->status != 0 && fil_choice == 3) {
                if (!(strncmp(emp_aux->name, name, strlen(name)))) {
                    printf("\n>>> ------------------------------ <<<\n");
                        printf("> Nome....................: %s\n", emp_aux->name);
                        printf("> Idade...................: %s (%d)\n", emp_aux->birth_date, return_age(emp_aux->birth_date)); 
                        printf("> CPF.....................: %s\n", emp_aux->cpf);
                        printf("> E-mail..................: %s\n", emp_aux->email);
                        printf("> Telefone................: %s\n", emp_aux->tel);
                        printf("> OAB.....................: %s\n", emp_aux->OAB);
                        printf("> Funcao..................: %s\n", emp_aux->role);
                        printf("> Descricao...............: %s\n", emp_aux->desc);
                }
            } else if (fil_choice > 3 || fil_choice < 0) {
                printf("\n>>> Opção inválida, voltando a tela de Funcionários...\n");
                break;
            }
        }

        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }

    free(emp_aux);
}