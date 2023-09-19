all: employers.o resources.o services.o clients.o schedule.o
	gcc -o main employers.o resources.o services.o clients.o schedule.o main.c

employers.o: 
	gcc -c modules/employers.c

resources.o: 
	gcc -c modules/resources.c

services.o: 
	gcc -c modules/services.c

clients.o: 
	gcc -c modules/clients.c

schedule.o: 
	gcc -c modules/schedule.c

clean:
	rm -rf *.o main

cleanWin:
	del *.o main