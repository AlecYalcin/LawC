#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void get_name(char* _name){
    int isValid = 0; int i; fflush(stdin);

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
            } else {
                isValid = 1;
            }
        }
    } while (!isValid);
}

void get_birth(char* _birth_date) {  
    printf("> Idade (DD/MM/AAAA)......: ");
    gets(_birth_date);
}

void get_cpf(double* _cpf) {
    printf("> CPF.....................: ");
    scanf("%lf", _cpf); getchar();
}

void get_email(char* _email) {
    printf("> E-mail..................: ");
    gets(_email);
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