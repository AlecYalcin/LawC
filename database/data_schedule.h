#include "../modules/schedule.h"

void sc_create_archive(char*, Schedule*);
Schedule* sc_read_archive(char*, char*);
void sc_update_archive(char*, char*, Schedule*);
void sc_delete_archive(char*, Schedule*);
void sc_list_archive(char*, int);