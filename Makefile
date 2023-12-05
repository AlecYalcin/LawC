all: employers.o resources.o services.o clients.o schedule.o utils.o data_employers.o data_resources.o data_services.o data_clients.o data_schedules.o data_utils.o
	gcc -o main *.o main.c
	rm -rf *.o

employers.o: 
	gcc -c modules/employer/employers.c
	gcc -c modules/employer/data_employers.c

services.o: 
	gcc -c modules/service/services.c
	gcc -c modules/service/data_services.c

resources.o: 
	gcc -c modules/resource/resources.c
	gcc -c modules/resource/data_resources.c

clients.o: 
	gcc -c modules/client/clients.c
	gcc -c modules/client/data_clients.c

schedule.o: 
	gcc -c modules/schedule/schedule.c
	gcc -c modules/schedule/data_schedules.c

utils.o: 
	gcc -c modules/utils.c
	gcc -c modules/data_utils.c

clean:
	rm -rf *.o main

cleanWin:
	del *.o main.exe