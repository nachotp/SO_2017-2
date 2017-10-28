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

  carta(string val, char col){
    valor = val;
    if (col == 'A') {
      color = "Amarillo";
    } else if (col == 'R'){
      color = "Rojo";
    } else if (col == 'Z'){
      color = "Azul";
    } else {
      color = "Verde";
    }

  }
  carta(){
    valor = "-1";
    color = "-";
  }

  void imprimir(){
    cout << "[" << valor << " " << color << "]\t";
  }
};

class jugador {
public:
  vector<carta> mano;
  int numeroJugador;
  void robar(vector<carta> *mazo){
    mano.push_back(mazo->back());
    mazo->pop_back();
  }
  void mostrarMano(){
    for (size_t i = 0; i < mano.size(); i++) {
      mano[i].imprimir();
    }
    cout << endl;
  }
};

class turnHandler {
public:
  int turnoDe;
  turnHandler(){
    turnoDe = 0;
  }
  int siguenteTurno(int n){
    turnoDe = ((turnoDe + n) & 4);
    return turnoDe;
  }
};



void generarCartasNumericas(vector<carta> *cartas);

void generarCartasExtra(vector<carta> *cartas);

#endif
