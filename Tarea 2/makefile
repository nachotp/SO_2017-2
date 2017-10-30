all = Tarea2

Tarea2: main.o funciones.o carta.o jugador.o turnhandler.o
	g++ main.o funciones.o carta.o jugador.o turnhandler.o -o exe
	./exe

memcheck: main.o funciones.o carta.o jugador.o turnhandler.o
	g++ -g main.o funciones.o carta.o jugador.o turnhandler.o -o exe
	valgrind --leak-check=full --show-leak-kinds=all ./exe

main.o: main.cpp
	g++ -c main.cpp -Wall

funciones.o: funciones.cpp
	g++ -c funciones.cpp -Wall

carta.o: carta.cpp
	g++ -c carta.cpp -Wall

jugador.o: jugador.cpp
	g++ -c jugador.cpp -Wall

turnhandler.o: turnhandler.cpp
	g++ -c turnhandler.cpp -Wall

clean:
	rm -f *.o
	rm exe
