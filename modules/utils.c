#include <stdio.h>
#include <stdio_ext.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void limpa_buffer() {
    fflush(stdin); __fpurge(stdin);
}

void get_name(char* _name){
    int isValid = 1; int i; limpa_buffer();

    do {
        printf("> Nome....................: ");
        fgets(_name, 75, stdin);

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
            } else {
                isValid = 1;
            }
        }
    } while (!isValid);
}

void get_birth(char* _birth_date) {
    int isValid = 1; int i; limpa_buffer();

    do {
        printf("> Idade (DD/MM/AAAA)......: ");
        fgets(_birth_date, 12, stdin);

        // Verificar se tem 10 caracteres
        isValid = 1;
        if (strlen(_birth_date) < 10) {
            printf("\nSua data de aniversario nao contem caracteres o suficiente.\n");
            isValid = 0;
        }

        // Verificar se contem o padrão valido
        for (i = 0; i < strlen(_birth_date)-1; i++) {
            char letter = _birth_date[i];
            // Verificadores de Numero
            int is_Number = isdigit(letter);
            // Verificar formatação do slash.
            if(i == 2 || i == 5) {
                if (letter != '/') {
                    printf("\nCaso 01: Sua data de aniversario e invalida. Tente Novamente.\n");
                    isValid = 0;
                    break;
                }
            } else if (!is_Number) {
                printf("\nCaso 02: Sua data de aniversario e invalida. Tente Novamente.\n");
                isValid = 0;
                break;
            }
        }
    } while (!isValid);
}

void get_cpf(char* _cpf) {
    int isValid = 1; int i; limpa_buffer();

    do {
        printf("> CPF (Somente Numeros)...: ");
        fgets(_cpf, 12, stdin);

        for (i = 0; i < strlen(_cpf); i++) {
            if (!isdigit(_cpf[i])) {
                printf("\nVoce digitou algum caractere que nao e um numero. Tente novamente.\n");
                isValid = 0;
                break;
            } else {
                isValid = 1;
            }
        }
    } while(!isValid);
}

void get_email(char* _email) {
    int isValid = 1; int aux; int i; limpa_buffer();

    do {
        printf("> E-mail..................: ");
        fgets(_email, 75, stdin);

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

void get_tel(char* _tel) {
    int isValid = 1; int i; limpa_buffer();

    do {
        printf("> Telefone (Numerico).....: ");
        fgets(_tel, 12, stdin);

        if (strlen(_tel) < 11 || strlen(_tel) > 12) {
            printf("Ha uma quantidade menor ou maior de informacoes no telefone do que deveria, por favor considere: 00900000000.\n");
            isValid = 0;
            continue;
        } else {
            isValid = 1;
        }

        for(i = 0; i < strlen(_tel); i++) {
            if (!isdigit(_tel[i])) {
                printf("\nVoce digitou algum caractere que nao e um numero. Tente novamente.\n");
                isValid = 0;
                break;
            }
        }
    } while(!isValid);
}

void get_oab(char* _oab) {
    int isValid = 1; int i; limpa_buffer();

    do {
        printf("> OAB.....................: ");
        fgets(_oab, 100, stdin);

        for(i = 0; i < strlen(_oab); i++) {
            char letter = _oab[i];
            // Verificador de Caracteres
            if (!isalnum(letter) && !isspace(letter)) {
                printf("Esse cargo contem caracteres nao comuns. Tente novamente.\n");
                isValid = 0;
                break;
            } else {
                isValid = 1;
            }
        }
    } while(!isValid);
}

void get_role(char* _role) {
    int isValid = 1; int i; limpa_buffer();

    do {
        printf("> Cargo...................: ");
        fgets(_role, 75, stdin);

        for(i = 0; i < strlen(_role); i++) {
            if (!isalpha(_role[i]) && !isspace(_role[i])) {
                printf("Esse cargo contem caracteres nao comuns. Tente novamente.\n");
                isValid = 0;
                break;
            } else {
                isValid = 1;
            }
        }
    } while(!isValid);
}

void get_desc(char* _desc) {
    printf("> Descricao...............: ");
    fgets(_desc, 300, stdin);
}

void get_available_at(char* _available_at) {
    printf("> Disponivel Em...........: ");
    fgets(_available_at, 300, stdin);
}

void get_value(float* _value) {
    printf("> Valor................: R$");
    scanf("%f", _value);
}