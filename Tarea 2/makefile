all = Tarea2

Tarea2: main.o funciones.o
	g++ main.o funciones.o -o exe
	./exe

memcheck: main.o funciones.o
	g++ -g main.o funciones.o -o exe
	valgrind --leak-check=full --show-leak-kinds=all ./exe

main.o: main.cpp
	g++ -c main.cpp -Wall

funciones.o: funciones.cpp
	g++ -c funciones.cpp -Wall

clean:
	rm -f *.o
