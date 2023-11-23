typedef struct resource Resource;

struct resource {
    int status;
    char name[50];
    char desc[300];
    char available_at[100];
};

void resources_c(void);
void resources_r(void);
void resources_u(void);
void resources_d(void);
void resources_list(void);