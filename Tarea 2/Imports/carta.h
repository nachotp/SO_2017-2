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
  char modo;

  carta(string val, char col, char mod);
  carta();

  void imprimir();
  void setColor(char col);
  char getModo();
  void copy(carta copyCard);
  bool operator==(const carta& c);
  //bool operator=(const carta& c);
};

#endif
