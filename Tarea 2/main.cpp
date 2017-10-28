#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <time.h>
#include "Imports/funciones.h"

using namespace std;

int main(int argc, char const *argv[]) {
  // Generar cartas y stack
  vector<carta> *mazo = (vector<carta>*)mmap(NULL, sizeof(stack<carta>), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
  carta *upperCard = (carta*)mmap(NULL, sizeof(carta), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
  mazo->reserve(108);
  generarCartasNumericas(mazo);
  generarCartasExtra(mazo);
  srand(time(0));
  random_shuffle(mazo->begin(),mazo->end());
  upperCard = &(mazo->back());
  mazo->pop_back();
  // creacion de procesos jugadores y piping
  turnHandler *coordinador = (turnHandler*)mmap(NULL, sizeof(turnHandler), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);;
  int pipes[4];
  int turnoDe = 1;
  bool fin = false;
  jugador player;
  pid_t pid;
  pipe(pipes);
  for (size_t i = 0; i < 4; i++){
    close(pipes[i]);
    write(pipes[i],-1,1);
  }
  write(pipes[0],1,1);
  for (size_t i = 3; i > 0; i--) {
    pid = fork();
    if (pid == 0){
      player.numeroJugador = i;
      cout << "Jugador creado: " << player.numeroJugador << endl;
      break;
    }
  }
  if (pid > 0) {
    player.numeroJugador = 0;
    cout << "Jugador creado: " << player.numeroJugador << endl;
  }

  for (size_t i = 0; i < 7; i++) {
    player.robar(mazo);
  }

  int pos = player.numeroJugador;
  cout << "jugador " << pos << " ya robó dejando " << mazo->size() << " cartas restantes" << endl;
  while (!fin) {
    for (size_t i = 0; i < 4; i++) close(pipes[pos]);
    if (turnoDe == player.numeroJugador) {
      cout << "turno de jugador " << turnoDe << ": " << endl;
      cout << "Carta superior: ";
      upperCard->imprimir();
      cout << endl << "tienes: ";
      player.mostrarMano();
      break;
    } else {

    }
    break;
  }


  return 0;
}
