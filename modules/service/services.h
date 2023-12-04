typedef struct service Service;

struct service {
    // Código de Exclusão
    int status;
    // Estruturas Fixas
    char name[75];
    char desc[300];
    float value;
    // Apontador de Lista
    Service* prox; 
};
void services_c(void);
void services_r(void);
void services_u(void);
void services_d(void);
void services_list(void);