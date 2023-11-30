#include "clients.h"

void c_create_archive(char*, Cliente*);
Cliente* c_read_archive(char*, char*);
void c_update_archive(char*, char*, Cliente*);
void c_delete_archive(char*, Cliente*);
void c_list_archive(char*, int);
void c_dylist_archive(char*, int);

void print_info(Cliente*);