typedef struct schedule Schedule;

struct schedule {
    int status;
    int finalizado;
    char name[75];
    char desc[200];
    char id_employer[12]; // CPF
    char id_client[12];   // CPF
    char id_service[75];  // Nome
    char date[12];
    // Valor apartir do serviço
};

void schedule_c(void);
void schedule_r(void);
void schedule_u(void);
void schedule_d(void);
void schedule_end(void);
void schedule_list(void);
void schedule_data(void);
