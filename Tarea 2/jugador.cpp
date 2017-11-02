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

void jugador::jugar(carta &upperCard, vector<carta> *mazo){
  unsigned int pos;
  int valor = upperCard.valor;
  char modo = upperCard.getModo();
  carta tempCard;
  if ((valor == 12 || valor == 13 || valor == 14) && modo != 'J') {
    cout << "Pierdes el turno por ";
    upperCard.imprimir();
    cout << endl;

    if (upperCard.getColor() == 'B') upperCard.setColor();
    upperCard.setModo('J');
    cout << endl;
    return;

  } else if (modo == 'C'){
    upperCard.setColor();
    upperCard.setModo('J');
    cout << endl;
  }

  cout << "Tu mano es: " << endl;
  mostrarMano();
  cout << mano.size() << ". Robar una carta." << endl;
  cout << "Elige una carta por su número: ";
  cin >> pos;
  while (pos < 0 && pos > mano.size()){
    cout << "Elige una opción correcta: ";
    cin >> pos;
  }
  tempCard = mano[pos];
  if (pos == mano.size()){
    robar(mazo);
    cout << "Robaste una carta ";
    mano.back().imprimir();
    cout << endl;
    if (mano.back() == upperCard) {
      char resp = '-';
      cout << "¿Deseas jugarla? S/N: ";
      cin >> resp;
      while (!(resp == 'S' || resp == 'N')){
        cout << "Ingrese una opción válida: ";
        cin >> resp;
      }
      if (resp == 'S'){
        tempCard = mano[pos];
        upperCard = tempCard;
        mano.erase(mano.begin() + pos);

        modo = upperCard.getModo();
        if (modo == '4' || modo == 'C'){
          upperCard.setColor();
          if (modo == 'C') upperCard.setModo('J');
        }
      }
    }
  }
  else if (upperCard == tempCard){
    upperCard = tempCard;
    mano.erase(mano.begin() + pos);

    modo = upperCard.getModo();
    if (modo == '4' || modo == 'C'){
      upperCard.setColor();
      if (modo == 'C') upperCard.setModo('J');
    }
  } else {
    mano.erase(mano.begin() + pos);
    robar(mazo);
    cout << "Robaste una carta ";
    mano.back().imprimir();
    cout << endl;
  }
  if (mano.size() == 1) cout << "¡UNO! (jugador " << numeroJugador << ")" << endl;
}
