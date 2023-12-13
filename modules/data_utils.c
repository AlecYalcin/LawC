#include <stdio.h> 
#include <stdio_ext.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>
// Coletando os structs
#include "data_utils.h"

// Verificação de Arquivos
int verify_archive(char* ar_name) {
    FILE *fp;

    if (fp = fopen(ar_name, "rb")) {
        fclose(fp);
        // O Arquivo EXISTE
        return 1;
    } else {
        // O Arquivo NÃO EXISTE
        return 0;
    }
}

// Função para tirar pontuações com '\n'
void change_last_2(char* text) {
    if (text[strlen(text)-1] == '\n') {
        text[strlen(text)-1] = '\0';
    }
}

// Criação/Reset de Arquivos
void create_archive(char* ar_name) {
    FILE *fp;

    fp = fopen(ar_name, "wb");
    
    if (!(fp == NULL)) {
        printf("\n>>> Criou o arquivo, nome do arquivo: '%s'.\n", ar_name);
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação\n");
    }
}

// Funções para transformar dados em outros
int return_age(char* birth_date) {
    // A função mais abaixo strtok acaba por 'danificar' o apontador original, sendo assim
    // É criado outro para não ser modificado o valor original com memória dinâmica.
    char* original_date = (char*) malloc((strlen(birth_date)+1)*sizeof(char)); 
    strcpy(original_date, birth_date);

    // Criando um delimitador e uma variável que ira pegar os valores individuais da data
    const char delimeter[2] = "/";
    char* birth_values;

    // Pos 0 - Dia, Pos 1 - Mês, Pos 2 - Ano
    int birth_info[] = {0,0,0}; 

    // Strtok pega a primeira string antes do delimitador, e depois retorna ponteiros nulos com o restante da String
    birth_values = strtok(original_date, delimeter);
    // Enquanto birth_value não for um ponteiro nulo sem retorno, continue
    int index = 0;
    while(birth_values != NULL) {
        // Coletando e Convertendo os valores de String das Datas
        birth_info[index] = atoi(birth_values);
        birth_values = strtok(NULL, delimeter);
        index++;
    }
    // Liberando memória dinâmica
    free(original_date);
    
    // Pegando valores de data
    int* actual_year = todays_date();
    // Calculando a Idade, Baseado no Código a Seguir: https://www.tutorialspoint.com/c-program-to-calculate-age
    if (birth_info[1] > actual_year[1]) {
        // Se o MÊS DE NASCIMENTO > MÊS ATUAL, então ainda não chegou o aniversário. Diminua o Ano em -1 (Pois não completou)
        actual_year[2] = actual_year[2] - 1;
    } else if (birth_info[1] == actual_year[1] ) {
        // Se o MÊS DE NASCIMENTO == MÊS ATUAL, então está no mês do aniversário, verifique se já completou.
        if (birth_info[0] > actual_year[0]) {
            // Se o DIA DE NASCIMENTO > DIA DE HOJE, então não chegou no aniversário. Diminua o ANo em -1 (Pois não completou)
            actual_year[2] = actual_year[2] -1;
        }
    }

    // Calcule a Idade Final
    int age = actual_year[2] - birth_info[2];
    // Limpando o Buffer
    fflush(stdin); __fpurge(stdin);

    return age;
}

int return_day(char* birth_date) {
    // A função mais abaixo strtok acaba por 'danificar' o apontador original, sendo assim
    // É criado outro para não ser modificado o valor original com memória dinâmica.
    char* original_date = (char*) malloc((strlen(birth_date)+1)*sizeof(char)); 
    strcpy(original_date, birth_date);

    // Criando um delimitador e uma variável que ira pegar os valores individuais da data
    const char delimeter[2] = "/";
    char* birth_values;

    // Pos 0 - Dia, Pos 1 - Mês, Pos 2 - Ano
    int birth_info[] = {0,0,0}; 

    // Strtok pega a primeira string antes do delimitador, e depois retorna ponteiros nulos com o restante da String
    birth_values = strtok(original_date, delimeter);
    // Enquanto birth_value não for um ponteiro nulo sem retorno, continue
    int index = 0;
    while(birth_values != NULL) {
        // Coletando e Convertendo os valores de String das Datas
        birth_info[index] = atoi(birth_values);
        birth_values = strtok(NULL, delimeter);
        index++;
    }
    // Liberando memória dinâmica
    free(original_date);
    
    // Pegando valores de data
    int* actual_year = todays_date();
    
    // Calculando os Dias
    int person_day = birth_info[0] + birth_info[1] * 30 + birth_info[2] * 365;
    int todays_day = actual_year[0] + actual_year[1] * 30 + actual_year[2] * 365;
    int diference_in_day = person_day - todays_day;

    // Limpando o Buffer
    fflush(stdin); //__fpurge(stdin);

    return diference_in_day;
}

// Função para pegar a data atual e transformar em um valor numérico
int* todays_date() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int today_year    = tm.tm_year + 1900;
    int today_month   = tm.tm_mon + 1;
    int today_day     = tm.tm_mday;

    int info[] = {today_day, today_month, today_year};
    int* sum_year = info;

    return sum_year;
}

// Função para pegar uma data e transformar em valor numérico
int* date_numeric(char* birth_date) {
    // É criado outro para não ser modificado o valor original com memória dinâmica.
    char* original_date = (char*) malloc((strlen(birth_date)+1)*sizeof(char)); 
    strcpy(original_date, birth_date);

    // Criando um delimitador e uma variável que ira pegar os valores individuais da data
    const char delimeter[2] = "/";
    char* birth_values;

    // Pos 0 - Dia, Pos 1 - Mês, Pos 2 - Ano
    int birth_info[] = {0,0,0}; 

    // Strtok pega a primeira string antes do delimitador, e depois retorna ponteiros nulos com o restante da String
    birth_values = strtok(original_date, delimeter);
    // Enquanto birth_value não for um ponteiro nulo sem retorno, continue
    int index = 0;
    while(birth_values != NULL) {
        // Coletando e Convertendo os valores de String das Datas
        birth_info[index] = atoi(birth_values);
        birth_values = strtok(NULL, delimeter);
        index++;
    }

    // Liberando memória dinâmica
    free(original_date);

    int* sum_year = birth_info;

    return sum_year;
}

// Funções GET para pegar informações dos STRUCTS
Cliente* get_client(char* cpf) {
    FILE *fp;
    Cliente* cli_aux = (Cliente*) malloc(sizeof(Cliente));

    fp = fopen("modules/client/_clients.dat", "rb");

    if (!(fp == NULL)) {

        while(!feof(fp)) {
            // Lendo o Arquivo
            fread(cli_aux, sizeof(Cliente), 1, fp);
            // Comparando as Strings
            if (strcmp(cli_aux->cpf, cpf) == 0 && cli_aux->status != 0) {
                fclose(fp);
                return cli_aux;
            }
        }

        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }

    free(cli_aux);
    return NULL;
}

Employer* get_employer(char* cpf) {
    FILE *fp;
    Employer* emp_aux = (Employer*) malloc(sizeof(Employer));

    fp = fopen("modules/employer/_employers.dat", "rb");

    if (!(fp == NULL)) {

        while(!feof(fp)) {
            // Lendo o Arquivo
            fread(emp_aux, sizeof(Employer), 1, fp);
            // Comparando as Strings
            if (strcmp(emp_aux->cpf, cpf) == 0 && emp_aux->status != 0) {
                fclose(fp);
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

Service* get_service(char* name) {
    FILE *fp;
    Service* ser_aux = (Service*) malloc(sizeof(Service));

    fp = fopen("modules/service/_services.dat", "rb");

    if (!(fp == NULL)) {

        while(!feof(fp)) {
            // Lendo o Arquivo
            fread(ser_aux, sizeof(Service), 1, fp);
            // Comparando as Strings
            if (strcmp(ser_aux->name, name) == 0 && ser_aux->status != 0) {
                fclose(fp);
                return ser_aux;
            }
        }
        
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }

    free(ser_aux);
    return NULL;
}

void list_client(char* cpf) {
    FILE *fp;
    Cliente* cli_aux = (Cliente*) malloc(sizeof(Cliente));

    fp = fopen("modules/client/_clients.dat", "rb");

    if (!(fp == NULL)) {
        int index = 0;
        while(fread(cli_aux, sizeof(Cliente), 1, fp)) {
            // Comparando as Strings
            if (!(strncmp(cli_aux->cpf, cpf, strlen(cpf))) && cli_aux->status != 0) {
                printf("\n>>> ------------------------------ <<<\n");
                printf("> Nome.................: %s\n", cli_aux->name);
                printf("> Idade................: %s (%d)\n", cli_aux->birth_date, return_age(cli_aux->birth_date)); 
                printf("> CPF..................: %s\n", cli_aux->cpf);
                printf("> Email................: %s\n", cli_aux->email);
                printf("> Telefone.............: %s\n", cli_aux->tel);

                index++;
            }
        }

        if(index == 0) {
            printf("\n>>> Não há resultados parecidos.\n");
        }

        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }

    free(cli_aux);
}

void list_employer(char* cpf) {
    FILE *fp;
    Employer* emp_aux = (Employer*) malloc(sizeof(Employer));

    fp = fopen("modules/employer/_employers.dat", "rb");

    if (!(fp == NULL)) {
        int index = 0;
        while(fread(emp_aux, sizeof(Employer), 1, fp)) {
            // Comparando as Strings
            if (!(strncmp(emp_aux->cpf, cpf, strlen(cpf))) && emp_aux->status != 0) {
                printf("\n>>> ------------------------------ <<<\n");
                printf("> Nome....................: %s\n", emp_aux->name);
                printf("> Idade...................: %s (%d)\n", emp_aux->birth_date, return_age(emp_aux->birth_date)); 
                printf("> CPF.....................: %s\n", emp_aux->cpf);
                printf("> E-mail..................: %s\n", emp_aux->email);
                printf("> Telefone................: %s\n", emp_aux->tel);
                printf("> OAB.....................: %s\n", emp_aux->OAB);
                printf("> Funcao..................: %s\n", emp_aux->role);
                printf("> Descricao...............: %s\n", emp_aux->desc);

                index++;
            }
        }

        if (index == 0) {
            printf("\n>>> Não há resultados parecidos.\n");
        }
        
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }

    free(emp_aux);
}

void list_service(char* name) {
    FILE *fp;
    Service* ser_aux = (Service*) malloc(sizeof(Service));

    fp = fopen("modules/service/_services.dat", "rb");

    if (!(fp == NULL)) {
        int index = 0;
        while(fread(ser_aux, sizeof(Service), 1, fp)) {
            // Comparando as Strings
            if (!(strncmp(ser_aux->name, name, strlen(name))) && ser_aux->status != 0) {
                printf("\n>>> ------------------------------ <<<\n");
                printf("> Servico.................: %s\n",      ser_aux->name);
                printf("> Valor...................: R$%.2f\n",  ser_aux->value);
                printf("> Descricao...............: %s\n",      ser_aux->desc);

                index++;
            }
        }

        if (index == 0) {
            printf("\n>>> Não há resultados parecidos.\n");
        }
        
        fclose(fp);
    } else {
        printf("\n>>> Erro na criação do arquivo! <<<\n");
    }

    free(ser_aux);
}