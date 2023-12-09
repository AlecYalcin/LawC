typedef struct employer Employer;
struct employer {
    // Código de Exclusão
    int status;
    // Estruturas Fixas
    char name[75];
    char birth_date[12];
    char cpf[12];
    char email[75];
    char tel[12];
    char OAB[100];
    char role[75];
    char desc[300];
    // Apontador de Lista
    Employer* prox; 
};
void employer_c(void);
void employer_r(void);
void employer_u(void);
void employer_d(void);
void employer_list(void);