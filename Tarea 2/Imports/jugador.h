#ifndef JUGADOR
#define JUGADOR

#include <string>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
#include "carta.h"
#include "turnhandler.h"

using namespace std;

class jugador {
public:
  vector<carta> mano;
  int numeroJugador;
  void robar(vector<carta> *mazo);
  void mostrarMano();
  void preturno(char modificador, vector<carta> *mazo);
  carta jugar(char modo, carta *upperCard);
};

#endif
