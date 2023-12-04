#include "resources.h"

void r_create_archive(char*, Resource*);
Resource* r_read_archive(char*, char*);
void r_update_archive(char*, char*, Resource*);
void r_delete_archive(char*, Resource*);
void r_list_archive(char*, int);
void r_dylist_archive(char*, int);
void r_print_info(Resource*);