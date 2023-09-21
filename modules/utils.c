#include <stdio.h>
#include <string.h>
#include <regex.h>

void verify_name(char* _name){
    int isValid = 0; int i; regex_t reg_letters;

    do {
        int reg_value = regcomp(&reg_letters,"[a-zA-Z \f\n\r\t\v\u00a0\u1680\u2000-\u200a\u2028\u2029\u202f\u205f\u3000\ufeff]", 0);

        printf(">  Nome:\t");
        scanf(" %s", _name);

        for (i = 0; i <= strlen(_name); i++) {
            char letter = _name[i];
            reg_value = regexec(&reg_letters, &letter, 0, NULL, 0);

            if (reg_value == REG_NOMATCH) {
                printf("A letra burra -> %c", letter);
                printf("\nPadrão de Nome INVÁLIDO, tente novamente.!");
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

