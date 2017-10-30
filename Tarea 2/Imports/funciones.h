#ifndef FUNCIONES
#define FUNCIONES

#include <string>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
#include "carta.h"
#include "turnhandler.h"
using namespace std;

void generarCartasNumericas(vector<carta> *cartas);

void generarCartasExtra(vector<carta> *cartas);

char setupInicial(carta *upperCard);
#endif
