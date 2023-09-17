all: employers.o resources.o services.o clients.o schedule.o
	gcc -o main employers.o resources.o services.o clients.o schedule.o main.c

employers.o: modules\employers.h
	gcc -c modules\employers.c

resources.o: modules\resources.h
	gcc -c modules\resources.c

services.o: modules\services.h
	gcc -c modules\services.c

clients.o: modules\clients.h
	gcc -c modules\clients.c

schedule.o: modules\schedule.h
	gcc -c modules\schedule.c

clean:
	rm -rf *.o main

cleanWin:
	del *.o main