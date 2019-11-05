ifeq ($(DEBUG),true)
	CC = gcc -g
else
	CC = gcc
endif

all: main.o songs.o musiclibrary.o
	$(CC) -o program main.o songs.o musiclibrary.o

main.o: main.c songlist.h musiclibrary.h
	$(CC) -c main.c

songs.o: songs.c songlist.h
	$(CC) -c songs.c

musiclibrary.o: musiclibrary.c musiclibrary.h
	$(CC) -c musiclibrary.c

run:
	./program

clean:
	rm *.o
	rm *~
