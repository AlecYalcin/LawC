#include "services.h"

void s_create_archive(char*, Service*);
Service* s_read_archive(char*, char*);
void s_update_archive(char*, char*, Service*);
void s_delete_archive(char*, Service*);
void s_list_archive(char*, int);
void s_dylist_archive(char*, int);
void s_print_info(Service*);