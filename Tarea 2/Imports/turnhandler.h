#ifndef HANDLER
#define HANDLER

#include <string>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

class turnHandler {
public:
  int turnoDe;
  int sentido;
  turnHandler(){
    turnoDe = 0;
    sentido = 1;
    cout << "Coordinador de turnos creado en memoria compartida"<< endl;
  }
  void siguenteTurno(int n);
  void cambiarSentido();
  int getTurno();
};

#endif