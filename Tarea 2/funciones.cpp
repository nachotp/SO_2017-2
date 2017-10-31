#include <string>
#include <iostream>
#include <stack>
#include <vector>
#include "Imports/funciones.h"
using namespace std;

////////////// FUNCIONES EXTRA //////////////
void generarCartasNumericas(vector<carta> *cartas){
  char colores[] = "RVAZ";
  string temp;
  for (size_t i = 0; i < 4; i++) {
    for (size_t j = 1; j < 10; j++) {
      temp = string(1,j+'0');
      for (size_t k = 0; k < 2; k++) cartas->push_back(carta(temp,colores[i],'J'));
    }
    temp = string(1,'0');
    cartas->push_back(carta(temp,colores[i],'J'));
  }
}

void generarCartasExtra(vector<carta> *cartas){
  char colores[] = "RVAZ";
  for (size_t i = 0; i < 4; i++) {
    for (size_t j = 0; j < 2; j++) {
      cartas->push_back(carta(string("Reversa"),colores[i],'R'));
      cartas->push_back(carta(string("Saltar"),colores[i],'S'));
      cartas->push_back(carta(string("+2"),colores[i],'2'));
    }
    cartas->push_back(carta(string("+4"),'B','4'));
    cartas->push_back(carta(string("Color"),'B','C'));
  }
}
