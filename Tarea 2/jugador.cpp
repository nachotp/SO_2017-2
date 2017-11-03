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

void jugador::jugar(carta &pupperCard, vector<carta> *mazo){
  unsigned int pos;
  int valor = pupperCard.valor;
  char modo = pupperCard.getModo();
  carta tempCard;
  if ((valor == 12 || valor == 13 || valor == 14) && modo != 'J') {
    cout << "Pierdes el turno por ";
    pupperCard.imprimir();
    cout << endl;

    if (pupperCard.getColor() == 'B') pupperCard.setColor();
    pupperCard.setModo('J');
    cout << endl;
    return;

  } else if (modo == 'C'){
    pupperCard.setColor();
    pupperCard.setModo('J');
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
    if (mano.back() == pupperCard) {
      char resp = '-';
      cout << "¿Deseas jugarla? S/N: ";
      cin >> resp;
      while (!(resp == 'S' || resp == 'N')){
        cout << "Ingrese una opción válida: ";
        cin >> resp;
      }
      if (resp == 'S'){
        tempCard = mano[pos];
        pupperCard = tempCard;
        mano.erase(mano.begin() + pos);

        modo = pupperCard.getModo();
        if (modo == '4' || modo == 'C'){
          pupperCard.setColor();
          if (modo == 'C') pupperCard.setModo('J');
        }
      }
    }
  }
  else if (pupperCard == tempCard){
    pupperCard = tempCard;
    mano.erase(mano.begin() + pos);

    modo = pupperCard.getModo();
    if (modo == '4' || modo == 'C'){
      pupperCard.setColor();
      if (modo == 'C') pupperCard.setModo('J');
    }
  } else {
    pupperCard = tempCard;
    if (modo == '4' || modo == 'C'){
      pupperCard.setColor();
    }
    pupperCard.setModo('J');
    mano.erase(mano.begin() + pos);
    robar(mazo);
    cout << "Carta descarta." << endl;
    cout << "Robaste una carta ";
    mano.back().imprimir();
    cout << " quedan "  << mazo->size() << endl;
  }
  if (mano.size() == 1) cout << "¡UNO! (jugador " << numeroJugador << ")" << endl;
}
