#ifndef CARTA
#define CARTA

#include <string>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

class carta {
public:
  string valor;
  string color;
  string accion;

  carta(string val, char col);
  carta();

  void imprimir();
};

#endif
