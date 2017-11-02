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
  turnHandler();
  void siguenteTurno(int n);
  void cambiarSentido();
  int getTurno();
};

#endif
