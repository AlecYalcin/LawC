typedef struct employer Employer;
struct employer {
    char* name;
    char birth_date[12];
    char cpf[12];
    char* email;
    char tel[12];
    char* OAB;
    char* role;
    char* desc;
};
void employer_c(void);
void employer_r(void);
void employer_u(void);
void employer_d(void);
void employer_list(void);