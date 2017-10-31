#include <string>
#include <iostream>
#include <stack>
#include <vector>
#include "Imports/carta.h"
using namespace std;

carta::carta(string val, char col){
  valor = val;
  if (col == 'A') {
    color = "Amarillo";
  } else if (col == 'R'){
    color = "Rojo";
  } else if (col == 'Z'){
    color = "Azul";
  } else if (col == 'V'){
    color = "Verde";
  } else {
    color = "Negro";
  }
}

carta::carta(){
  valor = "-1";
  color = "-";
}

void carta::setColor(char col){
  if (col == 'A') {
    color = "Amarillo";
  } else if (col == 'R'){
    color = "Rojo";
  } else if (col == 'Z'){
    color = "Azul";
  } else if (col == 'V'){
    color = "Verde";
  }
}

void carta::imprimir(){
  cout << "[" << valor << " | " << color << "]";
}

bool carta::operator ==(const carta& c) {
  if (color == c.color || valor == c.valor) {
    return true;
  } else {
    return false;
  }
}
