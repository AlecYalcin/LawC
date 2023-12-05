#include <stdio.h>
#include <stdio_ext.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Função que limpa o STD
void limpa_buffer() {
    fflush(stdin); __fpurge(stdin);
}

// Função para tirar pontuações com '\n'
void change_last(char* text) {
    if (text[strlen(text)-1] == '\n') {
        text[strlen(text)-1] = '\0';
    }
}

// Função para limpar Database (Facilidade)
void clear_database(void) {
    char* archives[5] = {
        "modules/client/_clients.dat",
        "modules/employer/_employers.dat",
        "modules/resource/_resources.dat",
        "modules/service/_services.dat",
        "modules/schedule/_schedule.dat"
    };

    int i, length;

    for(i = 0; i < 5; i++) {
        printf("Arquivo do Módulo: %s...", archives[i]);
        if(remove(archives[i])) {
            printf("Deletado com sucesso!\n");
        } else {
            printf("Houve algum problema!\n");
        }
    }
    getchar();
}

// Funções para Alocação Dinâmica de Texto
char* replicate_string(char* line) {
    int n = strlen(line) + 1;
    char* replicated = (char*) malloc(n*sizeof(char));
    strcpy(replicated, line);
    return replicated;
}

static char* scan_dynamic(void) {
    char line[255];
    fgets(line, 255, stdin);
    change_last(line);
    return replicate_string(line);
}

// Funções relacionadas a Pegar Dados
void get_name(char* _name, int print_changer){
    int isValid = 1; int i; 

    do {
        char* string_aux;
        limpa_buffer();

        // Print para Pegar Dados
        if (print_changer) {
            printf("> Nome....................: ");
        // Print para Pegar Serviço
        } else {
            printf("> Nome do Serviço.........: ");
        }

        fgets(_name, 75, stdin);
        change_last(_name);

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

void get_birth(char* _birth_date, int print_changer) {
    int isValid = 1; int i;

    do {
        limpa_buffer();

        if (print_changer) {
            printf("> Idade (DD/MM/AAAA)......: ");
        } else {
            printf("> Data (DD/MM/AAAA).......: ");
        }

        fgets(_birth_date, 11, stdin);
        change_last(_birth_date);

        // Verificar se tem 10 caracteres
        isValid = 1;
        if (strlen(_birth_date) < 10) {
            printf("\nSua data nao contem caracteres o suficiente.\n");
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
                    printf("\nCaso 01: Sua data é invalida. Tente Novamente.\n");
                    isValid = 0;
                    break;
                }
            } else if (!is_Number) {
                printf("\nCaso 02: Sua data é invalida. Tente Novamente.\n");
                isValid = 0;
                break;
            }
        }
    } while (!isValid);
}

void get_cpf(char* _cpf, int print_changer) {
    int isValid = 1; int i;

    do {
        limpa_buffer();

        if (print_changer == 0) {
            printf("> CPF (Somente Numeros)...: ");
        } else if (print_changer == 1) {
            printf("> CPF do Funcionario......: ");
        } else if (print_changer == 2) {
            printf("> CPF do Cliente..........: ");
        }

        fgets(_cpf, 12, stdin);
        change_last(_cpf);

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
    int isValid = 1; int aux; int i;

    do {
        limpa_buffer();
        printf("> E-mail..................: ");
        fgets(_email, 75, stdin);
        change_last(_email);

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
    int isValid = 1; int i;

    do {
        limpa_buffer();
        printf("> Telefone (Numerico).....: ");
        fgets(_tel, 12, stdin);
        change_last(_tel);

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
    int isValid = 1; int i;

    do {
        limpa_buffer();
        printf("> OAB.....................: ");
        fgets(_oab, 100, stdin);
        change_last(_oab);

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
    int isValid = 1; int i;

    do {
        limpa_buffer();
        printf("> Cargo...................: ");
        fgets(_role, 75, stdin);
        change_last(_role);

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
    limpa_buffer();
    printf("> Descricao...............: ");
    fgets(_desc, 300, stdin);
    change_last(_desc);
}

void get_available_at(char* _available_at) {
    limpa_buffer();
    printf("> Disponivel Em...........: ");
    fgets(_available_at, 300, stdin);
    change_last(_available_at);
}

void get_value(float* _value) {
    limpa_buffer();
    printf("> Valor...................: R$");
    scanf("%f", _value);
}