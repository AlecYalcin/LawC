#include <stdio.h> 
//#include <stdio_ext.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

    // Pegando valores de data
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int today_year    = tm.tm_year + 1900;
    int today_month   = tm.tm_mon + 1;
    int today_day     = tm.tm_mday;
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

    // Calculando a Idade, Baseado no Código a Seguir: https://www.tutorialspoint.com/c-program-to-calculate-age
    if (birth_info[1] > today_month) {
        // Se o MÊS DE NASCIMENTO > MÊS ATUAL, então ainda não chegou o aniversário. Diminua o Ano em -1 (Pois não completou)
        today_year = today_year - 1;
    } else if (birth_info[1] == today_month ) {
        // Se o MÊS DE NASCIMENTO == MÊS ATUAL, então está no mês do aniversário, verifique se já completou.
        if (birth_info[0] > today_day) {
            // Se o DIA DE NASCIMENTO > DIA DE HOJE, então não chegou no aniversário. Diminua o ANo em -1 (Pois não completou)
            today_year = today_year -1;
        }
    }

    // Calcule a Idade Final
    int age = today_year - birth_info[2];
    // Limpando o Buffer
    fflush(stdin); //__fpurge(stdin);

    return age;
}