#include <string>
#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include "Imports/funciones.h"
using namespace std;

void generarCartasNumericas(vector<carta> *cartas){
  char colores[] = "RVAZ";
  string temp;
  for (size_t i = 0; i < 4; i++) {
    for (size_t j = 1; j < 10; j++) {
      temp = string(1,j+'0');
      for (size_t k = 0; k < 2; k++) {
        cartas->push_back(carta(temp,colores[i]));
      }
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
