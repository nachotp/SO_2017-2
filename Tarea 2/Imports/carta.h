#ifndef CARTA
#define CARTA

#include <string>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

class carta {
public:
  int valor;
  char color;
  char modo;

  carta(int val, char col, char mod);
  carta();

  void imprimir();
  void setColor();
  char getColor();
  void setModo(char mod);
  char getModo();
  bool operator==(const carta& c);
};

#endif
