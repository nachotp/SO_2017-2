#include <string>
#include <iostream>
#include <stack>
#include <vector>
#include "Imports/funciones.h"
using namespace std;

////////////// METODOS DE CARTAS //////////////
carta::carta(string val, char col){
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

carta::carta(){
  valor = "-1";
  color = "-";
}

void carta::imprimir(){
  cout << "[" << valor << " " << color << "]";
}
////////////// METODOS DE JUGADOR //////////////
void jugador::robar(vector<carta> *mazo){
  mano.push_back(mazo->back());
  mazo->pop_back();
}
void jugador::mostrarMano(){
  for (size_t i = 0; i < mano.size(); i++) {
    mano[i].imprimir();
    if (i < (mano.size()-1)) cout << ", ";
  }
  cout << endl;
}

////////////// METODOS DE TURNHANDLER //////////////
int turnHandler::siguenteTurno(int n){
  turnoDe = ((turnoDe + n) % 4);
  return turnoDe;
}

////////////// FUNCIONES EXTRA //////////////
void generarCartasNumericas(vector<carta> *cartas){
  char colores[] = "RVAZ";
  string temp;
  for (size_t i = 0; i < 4; i++) {
    for (size_t j = 1; j < 10; j++) {
      temp = string(1,j+'0');
      for (size_t k = 0; k < 2; k++) cartas->push_back(carta(temp,colores[i]));
    }
    temp = string(1,'0');
    cartas->push_back(carta(temp,colores[i]));
  }
}

void generarCartasExtra(vector<carta> *cartas){
  char colores[] = "RVAZ";
  for (size_t i = 0; i < 4; i++) {
    for (size_t j = 0; j < 2; j++) {
      cartas->push_back(carta(string("reversa"),colores[i]));
      cartas->push_back(carta(string("salto"),colores[i]));
      cartas->push_back(carta(string("+2"),colores[i]));
    }
    cartas->push_back(carta(string("+4"),'B'));
    cartas->push_back(carta(string("color"),'B'));
  }
}
