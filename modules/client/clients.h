typedef struct cliente Cliente;
struct cliente {
    // Código de Exclusão
    int status;
    // Estruturas Dinâmicas
    char name [75];
    char email [75];
    char birth_date[12];
    char cpf[12];
    char tel[12];
    // Apontador de Lista
    Cliente* prox; 
};

void clients_c(void);
void clients_r(void);
void clients_u(void);
void clients_d(void);
void clients_list(void);