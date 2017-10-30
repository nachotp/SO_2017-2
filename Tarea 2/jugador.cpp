#include <string>
#include <iostream>
#include <stack>
#include <vector>
#include "Imports/jugador.h"
using namespace std;


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

char jugador::jugar(turnHandler *coordinador, carta *upperCard){
  char mod = 'J'

  return mod;
}
