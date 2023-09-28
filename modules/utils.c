#include <stdio.h>
#include <string.h>
#include <ctype.h>

void get_name(char* _name){
    int isValid = 0; int i;

    do {
        printf(">  Nome: ");
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

char* verify_email(char* email){

}

int verify_cpf(int cpf){

}

int verify_tel(int tel){

}

