#ifndef FUNCIONES
#define FUNCIONES

#include <string>
#include <vector>

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



class jugador;

void generarCartasNumericas(vector<carta> *cartas);

void generarCartasExtra(vector<carta> *cartas);

#endif
