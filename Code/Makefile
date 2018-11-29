all: decode

decode : decodage.o
	gcc -g -Wall -o decode decodage.o

decodage.o: decodage.c decodage.h
	gcc -g -c decodage.c -Wall -o decodage.o
