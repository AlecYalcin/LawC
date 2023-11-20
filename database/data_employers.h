#include "../modules/employers.h"

void e_create_archive(char*, Employer*);
Employer* e_read_archive(char*, char*);
void e_update_archive(char*, char*, Employer*);
void e_delete_archive(char*, Employer*);
void e_list_archive(char*, int);