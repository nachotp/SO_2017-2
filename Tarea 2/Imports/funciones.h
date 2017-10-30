#ifndef FUNCIONES
#define FUNCIONES

#include <string>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

class carta {
public:
  string valor;
  string color;
  string accion;

  carta(string val, char col);
  carta();

  void imprimir();
};

class jugador {
public:
  vector<carta> mano;
  int numeroJugador;
  void robar(vector<carta> *mazo);
  void mostrarMano();
};

class turnHandler {
  int turnoDe;
public:
  turnHandler(){
    turnoDe = 0;
  }
  int siguenteTurno(int n);
};



void generarCartasNumericas(vector<carta> *cartas);

void generarCartasExtra(vector<carta> *cartas);

#endif
