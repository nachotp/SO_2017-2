#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include "Imports/funciones.h"

using namespace std;

int main(int argc, char const *argv[]) {
  // Generar cartas y stack
  vector<carta> *mazo = (vector<carta>*)mmap(NULL, sizeof(stack<carta>), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
  mazo->reserve(108);
  generarCartasNumericas(mazo);
  generarCartasExtra(mazo);
  random_shuffle(mazo->begin(),mazo->end());


  // creacion de procesos jugadores y piping
  turnHandler coordinador;
  int pipes[4][2];
  int turnoDe = 1;
  bool fin = true;
  jugador player;
  pid_t pid;

  for (size_t i = 4; i < 1; i++) {
    pid = fork();
    pipe(pipes[i]);
    if (pid == 0){
      player.numeroJugador = i+1;
      cout << "Jugador creado: " << player.numeroJugador << endl;
      break;
    }
  }

  if (pid > 0) player.numeroJugador = 1;

  while (!fin) {
    //codigo de coordinador
    if (pid > 0) {
      if (turnoDe < 0) {


      }
    // codigo de jugadores
    } else {
      cout << &mazo[0] << endl;
      if (turnoDe == player.numeroJugador) {
        cout << "Turno de jugador " << player.numeroJugador << endl;
        break;
      }
    }
  }


  return 0;
}
