typedef struct resource Resource;

struct resource {
    // Código de Exclusão
    int status;
    // Estruturas Fixas
    char name[75];
    char desc[300];
    char available_at[100];
    // Apontador de Lista
    Resource* prox; 
};

void resources_c(void);
void resources_r(void);
void resources_u(void);
void resources_d(void);
void resources_list(void);