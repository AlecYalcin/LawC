// Coletando os structs
#include "data_clients.h"
#include "data_employers.h"
#include "data_services.h"

int verify_archive(char*);
void change_last_2(char*);
void create_archive(char*);
int return_age(char*);

// Funções GET para pegar informações dos STRUCTS
Cliente* get_client(char*);
Employer* get_employer(char*);
Service* get_service(char*);