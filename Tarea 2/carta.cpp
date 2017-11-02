#include <string>
#include <iostream>
#include <stack>
#include <vector>
#include "Imports/carta.h"
using namespace std;

carta::carta(int val, char col, char mod){
  valor = val;
  color = col;
  modo = mod;
}

carta::carta(){
  valor = -1;
  color = '-';
  modo = 'J';
}

void carta::setColor(){
  char col = 'B';
  while (!(col == 'A' || col == 'V' || col == 'R' || col == 'Z')){
    cout << "Elige un color para la carta [A (Amarillo)/V (Verde)/R (Rojo)/Z (Azul)]: ";
    cin >> col;
  }
  color = col;
}

char carta::getColor(){
  return color;
}

void carta::setModo(char mod){
  modo = mod;
}

char carta::getModo(){
  return modo;
}

void carta::imprimir(){
  cout << "[";
  if (valor < 10) cout << valor;
  else if (valor == 11) cout << "Reversa";
  else if (valor == 12) cout << "Saltar";
  else if (valor == 13) cout << "+2";
  else if (valor == 14) cout << "+4";
  else if (valor == 15) cout << "Color";
  cout << " | ";
  if (color == 'A') cout << "Amarillo";
  else if (color == 'R') cout << "Rojo";
  else if (color == 'Z') cout << "Azul";
  else if (color == 'V') cout << "Verde";
  else cout << "Negro";
  cout << "]";
}

bool carta::operator==(const carta& c) {
  if (color == c.color || valor == c.valor || c.color == 'B') {
    return true;
  } else {
    return false;
  }
}
