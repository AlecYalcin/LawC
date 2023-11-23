typedef struct service Service;

struct service {
    int status;
    char name[50];
    char desc[300];
    float value;
};
void services_c(void);
void services_r(void);
void services_u(void);
void services_d(void);
void services_list(void);