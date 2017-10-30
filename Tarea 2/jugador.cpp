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

void jugador::preturno(char mod, vector<carta> *mazo){
  if (mod == '2') {
    cout << "Robas 2 cartas por un +2" << endl;
    for (size_t i = 0; i < 2; i++) robar(mazo);
  } else if (mod == '4') {
    cout << "Robas 4 cartas por un +4" << endl;
    for (size_t i = 0; i < 4; i++) robar(mazo);
  }
}

char jugador::jugar(turnHandler *coordinador, carta *upperCard){
  char mod = 'J';

  return mod;
}
