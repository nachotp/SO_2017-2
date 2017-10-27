all = Tarea1

Tarea1: main.o funciones.o mp3tags.o
	gcc main.o funciones.o mp3tags.o -o exe
	./exe

memcheck: main.o funciones.o mp3tags.o
	gcc -g main.o funciones.o mp3tags.o -o exe
	valgrind --leak-check=full --show-leak-kinds=all ./exe

main.o: main.c
	gcc -c main.c -Wall

funciones.o: funciones.c
	gcc -c funciones.c -Wall

mp3tags.o: mp3tags.c
	gcc -c mp3tags.c -Wall

clean:
	rm -f *.o
