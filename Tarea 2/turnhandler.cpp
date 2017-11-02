#include <string>
#include <iostream>
#include <stack>
#include <vector>
#include "Imports/turnhandler.h"
using namespace std;

turnHandler::turnHandler(){
  turnoDe = 0;
  sentido = -1;
}

void turnHandler::siguenteTurno(int n){
  turnoDe = ((turnoDe + (n*sentido)) % 4);
  if (turnoDe == -1) turnoDe = 3;
}

void turnHandler::cambiarSentido(){
  sentido *= -1;
  cout << "Sentido invertido!" << endl;
}

int turnHandler::getTurno(){
  return turnoDe;
}
