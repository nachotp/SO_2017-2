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
    cout << i <<". ";
    mano[i].imprimir();
    cout << endl;
  }
}

void jugador::preturno(char mod, vector<carta> *mazo){
  if (mod == '2') {
    cout << "Robas 2 cartas por un +2" << endl;
    for (size_t i = 0; i < 2; i++) robar(mazo);
    cout << "Tu mano es: " << endl;;
    mostrarMano();
  } else if (mod == '4') {
    cout << "Robas 4 cartas por un +4" << endl;
    for (size_t i = 0; i < 4; i++) robar(mazo);
    cout << "Tu mano es: " << endl;;
    mostrarMano();
  }
}

carta jugador::jugar(char modo, carta *upperCard){
  int pos;
  carta tempCard;
  if (modo == '2' || modo == '4' || modo == 'S') {
    cout << "Pierdes el turno por ";
    upperCard->imprimir();
    cout << endl;
    return tempCard;
  }

  cout << "Tu mano es: " << endl;
  mostrarMano();
  cout << "Elige una carta por su número: ";
  cin >> pos;
  tempCard = mano[pos];
  if (*upperCard == tempCard) {
    cout << "carta ";
    tempCard.imprimir();
    cout << " compatible!" << endl;
    mano.erase(mano.begin()+pos);
    return tempCard;
  } else {
    /* code */
  }
  return tempCard;
}
