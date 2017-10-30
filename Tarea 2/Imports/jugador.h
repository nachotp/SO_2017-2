#ifndef JUGADOR
#define JUGADOR

#include <string>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
#include "carta.h"
#include "turnHandler.h"

using namespace std;

class jugador {
public:
  vector<carta> mano;
  int numeroJugador;
  void robar(vector<carta> *mazo);
  void mostrarMano();
  void preturno(char modificador, vector<carta> *mazo);
  char jugar(turnHandler *coordinador, carta *upperCard);
};

#endif
