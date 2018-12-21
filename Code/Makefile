all:
	echo "Precisez decode, registre, memoire ou clean"
	echo "Pour les .o : decodage.o,registre.o ou memoire.o"
clean :
	rm memoire decode registre *.o

decode : decodage.o
	gcc -g -Wall -o decode decodage.o

decodage.o: decodage.c decodage.h
	gcc -g -c decodage.c -Wall -o decodage.o

registre : registre.c registre.h
	gcc -g -Wall -D TESTS registre.c registre.h -o registre

memoire : memoire.c memoire.h
	gcc -g -Wall -D TESTS memoire.c memoire.h -o memoire

registre.o : registre.c registre.h
	gcc -g -Wall registre.c registre.h -o registre.o

memoire.o : memoire.c memoire.h
	gcc -g -Wall memoire.c memoire.h -o memoire.o
