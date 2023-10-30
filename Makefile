all: employers.o resources.o services.o clients.o schedule.o utils.o data_employers.o data_resources.o data_services.o data_clients.o data_schedule.o data_utils.o
	gcc -o main *.o main.c

employers.o: 
	gcc -c modules/employers.c
	gcc -c database/data_employers.c

resources.o: 
	gcc -c modules/resources.c
	gcc -c database/data_resources.c

services.o: 
	gcc -c modules/services.c
	gcc -c database/data_services.c

clients.o: 
	gcc -c modules/clients.c
	gcc -c database/data_clients.c

schedule.o: 
	gcc -c modules/schedule.c
	gcc -c database/data_schedule.c

utils.o: 
	gcc -c modules/utils.c
	gcc -c database/data_utils.c

clean:
	rm -rf *.o 

cleanWin:
	del *.o