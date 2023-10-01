#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void get_name(char* _name){
    int isValid = 1; int i; fflush(stdin);

    do {
        printf("> Nome....................: ");
        gets(_name);

        for (i = 0; i < strlen(_name); i++) {
            char letter = _name[i];
            // Verificando a Integridade do Nome
            int is_Letter = (isalpha(letter) != 0);
            int is_Space  = (isspace(letter) != 0);
            // Se não for uma letra e se não for um espaço, então é inválido.
            if (!is_Letter && !is_Space) {
                printf("O nome contem algum caractere invalido. Tente Novamente.\n");
                isValid = 0;

                break;
            }
        }
    } while (!isValid);
}

void get_birth(char* _birth_date) {
    int isValid = 1; int i; fflush(stdin);

    do {
        printf("> Idade (DD/MM/AAAA)......: ");
        gets(_birth_date);

        // Verificar se tem 10 caracteres
        if (strlen(_birth_date) < 10) {
            printf("\nSua data de aniversario nao contem caracteres o suficiente.\n");
            continue;
        }

        // Verificar se contem o padrão valido
        for (i = 0; i < strlen(_birth_date); i++) {
            char letter = _birth_date[i];
            // Verificadores de Numero
            int is_Number = isdigit(letter);
            // Verificar formatação do slash.
            if(i == 2 || i == 5) {
                if (letter != '/') {
                    printf("\nSua data de aniversario e invalida. Tente Novamente.\n");
                    isValid = 0;

                    break;
                }
            } else if (!is_Number) {
                printf("\nSua data de aniversario e invalida. Tente Novamente.\n");
                isValid = 0;

                break;
            }
        }
    } while (!isValid);
}

void get_cpf(char* _cpf) {
    int isValid = 1; int i; fflush(stdin);

    do {
        printf("> CPF (Somente Numeros)...: ");
        gets(_cpf);

        for (i = 0; i < strlen(_cpf); i++) {
            if (!isdigit(_cpf[i])) {
                printf("\nVoce digitou algum caractere que nao e um numero. Tente novamente.\n");
                isValid = 0;
                break;
            }
        }
    } while(!isValid);
}

void get_email(char* _email) {
    int isValid = 1; int aux; int i; fflush(stdin);

    do {
        printf("> E-mail..................: ");
        gets(_email);

        // Variavel auxiliar para verificar integridade do E-mail
        aux = 0;
        for(i = 0; i < strlen(_email); i++) {
            char letter = _email[i];

            if (letter == ' ') {
                printf("Seu e-mail contem espacos. Tente novamente.\n");
                isValid = 0;

                break;
            }
            
            if (letter == '@') {
                aux = !aux;
            }

            // Ainda planejando como vou fazer para reconhecer terminações de e-mail.
        }

        if (!aux) {
            printf("Seu e-mail nao e valido. Tente novamente.\n");
            isValid = 0;
        } else {
            isValid = 1;
        }
    } while(!isValid);
}

void get_tel(double* _tel) {
    printf("> Telefone................: ");
    scanf("%lf", _tel); getchar();
}

void get_oab(char* _oab) {
    printf("> OAB.....................: ");
    gets(_oab);
}

void get_role(char* _role) {
    printf("> Cargo...................: ");
    gets(_role);
}

void get_desc(char* _desc) {
    printf("> Descricao...............: ");
    gets(_desc);
}

void get_available_at(char* _available_at) {
    printf("> Disponivel Em...........: ");
    gets(_available_at);
}

void get_value(float* _value) {
    printf("> Valor................: R$");
    scanf("%f", _value); getchar();
}