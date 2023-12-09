// Coletando os structs
#include "client/data_clients.h"
#include "employer/data_employers.h"
#include "service/data_services.h"
#include "resource/data_resources.h"
#include "schedule/data_schedules.h"

int verify_archive(char*);
void change_last_2(char*);
void create_archive(char*);
int return_age(char*);
int return_day(char*);
int* todays_date();
int* date_numeric(char*);

// Funções GET para pegar informações dos STRUCTS
Cliente* get_client(char*);
Employer* get_employer(char*);
Service* get_service(char*);
void list_client(char*);
void list_employer(char*);
void list_service(char*);