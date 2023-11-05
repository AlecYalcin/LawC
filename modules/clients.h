typedef struct cliente Cliente;
struct cliente {
    int status;
    char name[50];
    char birth_date[12];
    char cpf[12];
    char email[50];
    char tel[12];
};

void clients_c(void);
void clients_r(void);
void clients_u(void);
void clients_d(void);
void clients_list(void);