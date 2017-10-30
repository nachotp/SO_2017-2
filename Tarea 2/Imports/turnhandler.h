#ifndef HANDLER
#define HANDLER

#include <string>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

class turnHandler {
  int turnoDe;
  int sentido;
public:
  turnHandler(){
    turnoDe = 0;
    sentido = 1;
  }
  void siguenteTurno(int n);
  void cambiarSentido();
  int getTurno();
};

#endif
