#include <stdio.h>
#include <ctype.h>
#include <string.h>

void verify_name(char* _name){
    int  isNumber = 0;
    do {
        scanf(" %s", _name);
        printf("Breaker 01");
        for (int i = 0; i <= strlen(_name); i++) {
            printf("Breaker 02");
            if (isdigit(_name)) {
                printf("Breaker 03");
                printf("Seu nome é inválido.");
                isNumber = 1;
                break;
            }
        }
    }  while (!isNumber);
}

char* verify_email(char* email){

}

int verify_cpf(int cpf){

}

int verify_tel(int tel){

}

