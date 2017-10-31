#include <string>
#include <iostream>
#include <stack>
#include <vector>
#include "Imports/carta.h"
using namespace std;

carta::carta(string val, char col, char mod){
  valor.reserve(10);
  color.reserve(10);
  valor = val;
  modo = mod;
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
  valor.reserve(10);
  color.reserve(10);
  valor = "-1";
  color = "-";
  modo = 'J';
  cout << "Dummy card creada!" << endl;
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

char carta::getModo(){
  return modo;
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

void carta::copy(carta copyCard){
  valor = "" + copyCard.valor;
  color = "" + copyCard.color;
  modo = copyCard.getModo();
}
/*
bool carta::operator =(const carta& c) {
  color = string(c.color);
  valor = string(c.valor);
  modo = c.modo;
  return true;
}*/
