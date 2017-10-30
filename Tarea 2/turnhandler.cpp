#include <string>
#include <iostream>
#include <stack>
#include <vector>
#include "Imports/turnhandler.h"
using namespace std;

int turnHandler::siguenteTurno(int n){
  turnoDe = ((turnoDe + n) % 4);
  return turnoDe;
}
