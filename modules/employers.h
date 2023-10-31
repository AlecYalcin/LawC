typedef struct employer Employer;
struct employer {
    char name[50];
    char birth_date[12];
    char cpf[12];
    char email[50];
    char tel[12];
    char OAB[100];
    char role[75];
    char desc[300];
};
void employer_c(void);
void employer_r(void);
void employer_u(void);
void employer_d(void);
void employer_list(void);