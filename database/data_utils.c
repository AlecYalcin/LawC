#include <stdio.h> 
#include <stdlib.h>

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
