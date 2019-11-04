all: main.o songs.o
	gcc -o program main.o songs.o

main.o: main.c songlist.h
	gcc -c main.c

songs.o: songs.c songlist.h
	gcc -c songs.c

run:
	./program

check: main.c songs.c songlist.h
	gcc -g main.c songs.c

gdb:
	gdb program.exe

clean:
	rm *.o
	rm *.exe
