typedef struct resource Resource;

struct resource {
    char* name;
    char* desc;
    char* available_at;
};

void resources_c(void);
void resources_r(void);
void resources_u(void);
void resources_d(void);
void resources_list(void);