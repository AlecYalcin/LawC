all: employers.o resources.o services.o clients.o schedule.o utils.o
	gcc -o main employers.o resources.o services.o clients.o schedule.o utils.o main.c

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

utils.o: 
	gcc -c modules/utils.c

clean:
	rm -rf *.o 

cleanWin:
	del *.o