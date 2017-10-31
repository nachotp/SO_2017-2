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
#include "Imports/carta.h"
#include "Imports/jugador.h"
#include "Imports/turnhandler.h"

using namespace std;

int main(int argc, char const *argv[]) {

  // Generar cartas y mazo
  vector<carta> *mazo = (vector<carta>*)mmap(NULL, sizeof(vector<carta>), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
  carta *upperCard = (carta*)mmap(NULL, sizeof(carta), PROT_READ|PROT_WRITE|PROT_EXEC, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
  mazo->reserve(108);
  generarCartasNumericas(mazo);
  generarCartasExtra(mazo);

  // Mezclar cartas y dejar una boca arriba
  srand(time(0));
  random_shuffle(mazo->begin(),mazo->end());
  upperCard = &(mazo->back());
  mazo->pop_back();

  // creacion de turnHandler, procesos jugadores y piping
  turnHandler *coordinador = (turnHandler *)mmap(NULL, sizeof(turnHandler), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
  *coordinador = turnHandler();
  int pipes[4][2];
  bool fin = false;
  jugador player;
  pid_t pid;

  //Setear configuración inicial
  char modo[1];
  modo[0] = setupInicial(upperCard);
  if (modo[0] == 'R') coordinador->cambiarSentido();

  for (size_t i = 0; i < 4; i++){
    pipe(pipes[i]);
    write(pipes[i][1],"0",1);
  }

  for (size_t i = 3; i > 0; i--) {
    pid = fork();
    if (pid == 0){
      player.numeroJugador = i;
      break;
    }
  }

  if (pid > 0) {
    player.numeroJugador = 0;
    write(pipes[0][1],modo,1);
  }

  int pos = player.numeroJugador;
  //robar mano de carta inicial para cada jugador
  for (size_t i = 0; i < 7; i++) player.robar(mazo);

  while (!fin) {
    read(pipes[pos][0], modo, 1);
    if (modo[0] != '0') {
      cout << "Turno de jugador " << pos << " del proceso "<< getpid() << " modo " << modo[0] << ": " << endl;
      cout << "Carta superior: ";
      upperCard->imprimir();
      cout << endl;

      player.preturno(modo[0], mazo);
      modo[0] = player.jugar(modo[0], upperCard);

      if (modo[0] == 'R') coordinador->cambiarSentido();
      coordinador->siguenteTurno(1);
      //cerrar turno y entregar al siguiente jugador
      write(pipes[pos][1],"0",1);
      write(pipes[coordinador->getTurno()][1],modo,1);
      cout << endl;
    }
  }


  return 0;
}
