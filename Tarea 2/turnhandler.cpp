#include <string>
#include <iostream>
#include <stack>
#include <vector>
#include "Imports/turnhandler.h"
using namespace std;

void turnHandler::siguenteTurno(int n){
  turnoDe = ((turnoDe + (n*sentido)) % 4);
}

void turnHandler::cambiarSentido(){
  sentido *= -1;
  cout << "Sentido invertido!" << endl;
}

int turnHandler::getTurno(){
  return turnoDe;
}
