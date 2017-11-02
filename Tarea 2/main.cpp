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
  bool *fin = (bool*)mmap(NULL, sizeof(bool), PROT_READ|PROT_WRITE|PROT_EXEC, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
  *fin = false;
  *upperCard = carta();
  mazo->reserve(108);
  generarCartasNumericas(mazo);
  generarCartasExtra(mazo);

  // Mezclar cartas y dejar una boca arriba
  srand(time(0));
  random_shuffle(mazo->begin(),mazo->end());
  *upperCard = mazo->back();
  mazo->pop_back();

  // creacion de turnHandler, procesos jugadores y piping
  turnHandler *coordinador = (turnHandler *)mmap(NULL, sizeof(turnHandler), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
  *coordinador = turnHandler();
  int pipes[4][2];
  int *turnoRobar = (int *)mmap(NULL, sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
  *turnoRobar = 0;
  jugador player;
  pid_t pid;

  //Setear configuración inicial
  char modo[1];
  modo[0] = upperCard->getModo();
  if (modo[0] == 'R') coordinador->cambiarSentido();

  for (size_t i = 0; i < 4; i++){
    pipe(pipes[i]);
    write(pipes[i][1],"0",1);
  }

  for (size_t i = 3; i > 0; --i) {
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
  while (*turnoRobar != pos);
  for (size_t i = 0; i < 7; i++) player.robar(mazo);
  *turnoRobar = *turnoRobar + 1;

  while (!mazo->empty() || !fin) {
    read(pipes[pos][0], modo, 1);
    if (modo[0] != '0' && modo[0] != 'X') {
      cout << "Turno de jugador " << pos << " del proceso "<< getpid() << " modo " << modo[0] << ": " << endl;
      cout << "Carta superior: ";
      upperCard->imprimir();
      cout << endl;

      player.preturno(modo[0], mazo);
      player.jugar(*upperCard, mazo);
      modo[0] = upperCard->getModo();
      if (player.mano.size() == 0){
        cout << "El ganador es el jugador " << pos << endl;
        *fin = true;
        for (size_t i = 0; i < 4; i++) write(pipes[i][1],"X",1);
        break;
      }
      if (modo[0] == 'R'){
        coordinador->cambiarSentido();
        upperCard->setModo('J');
      }
      coordinador->siguenteTurno(1);
      //cerrar turno y entregar al siguiente jugador
      write(pipes[pos][1],"0",1);
      write(pipes[coordinador->getTurno()][1],modo,1);
      cout << endl;
    } else if (modo[0] == 'X'){
      return 0;
    }
  }


  return 0;
}
