all: employers.o resources.o services.o
	gcc -o main employers.o resources.o services.o main.c

employers.o: modules\employers.h
	gcc -c modules\employers.c

resources.o: modules\resources.h
	gcc -c modules\resources.c

services.o: modules\services.h
	gcc -c modules\services.c