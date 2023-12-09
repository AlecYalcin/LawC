//#include <stdio_ext.h> 

// Funções de utilidade
void limpa_buffer(void);
void change_last(char*);
void clear_database(void);

// Funções de Coleta Dinâmica
static char* scan_dynamic(void);
char* replicate_string(char*);

// Funções de dados
void get_name(char* _name, int);
void get_birth(char* _birth_date, int);
void get_cpf(char* _cpf, int);
void get_email(char* _email);
void get_tel(char* _tel);
void get_oab(char* _oab);
void get_role(char* _role);
void get_desc(char* _desc);
void get_available_at(char* _available_at);
void get_value(float* _value);