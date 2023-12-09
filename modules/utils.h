#include <stdio_ext.h> 

// Funções de utilidade
void limpa_buffer(void);
void change_last(char*);
void clear_database(void);

// Funções de Coleta Dinâmica
static char* scan_dynamic(void);
char* replicate_string(char*);

// Funções de dados
void get_name(char*, int);
void get_birth(char*, int);
void get_cpf(char*, int);
void get_email(char*);
void get_tel(char*);
void get_oab(char*);
void get_role(char*);
void get_desc(char*);
void get_recurso(char*);
void get_schedule(char*);
void get_available_at(char*);
void get_value(float*);