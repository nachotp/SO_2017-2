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
  char color;
  string accion;

  carta(string val, char col){
    valor = val;
    color = col;
  }

  void imprimir(){
    cout << valor << " " << color << '\t';
  }
};

class jugador {
public:
  vector<carta> mano;
  int numeroJugador;
  jugador(){
    cout << "Jugador "<< numeroJugador <<" creado en " << getpid() << endl;
  }
};

class turnHandler {
public:
  int turnoDe;
  turnHandler(){
    turnoDe = 1;
  }
  int siguenteTurno(int n){
    turnoDe = 1 + ((turnoDe + n) & 4);
    return turnoDe;
  }
};



void generarCartasNumericas(vector<carta> *cartas);

void generarCartasExtra(vector<carta> *cartas);

#endif
