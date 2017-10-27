#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "Imports/funciones.h"
#include "Imports/mp3tags.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

int main(int argc, char const *argv[]) {
  char resp[2];
  char **generos;
  printf("¿Desea organizar la biblioteca?\n");
  scanf("%s",resp);
  if (!strcmp(resp,"si")) {
    printf("\n");
    generos = cargarGeneros();
    organizar(generos);
    chdir("Biblioteca De Musica");
  } else {
    exit(0);
  }
  char basedir[200];
  getcwd(basedir,200);
  char dir[200];
  getcwd(dir,200);
  char accion[20];
  char param[100];
  printf("%s\n", "Ingrese accion que desea realizar:");
  printf(KCYN">> " KNRM);
  scanf("%s", accion);
  while (strcmp(accion, "salir")) {

    if (!strcmp(accion, "mostrar")) {
      mostrar();
    } else if (!strcmp(accion, "mover")) {
      scanf(" %[^\n]s", param);
      if (!strcmp(param, "..") && !strcmp(dir, basedir)) {
        printf(KRED "No se puede retroceder mas.\n" KNRM);
      } else {
        chdir(param);
        getcwd(dir, 200);
      }

    } else if (!strcmp(accion,"abrir")) {
      scanf(" %[^\n]s", param);
      mostrarID3(param, generos);
    } else if (!strcmp(accion,"azar")) {
      azar(basedir);
    } else {
      printf(KRED "Comando no reconocido\n" KNRM);
    }
    printf("%s\n", "Ingrese accion que desea realizar:");
    printf(KCYN">> " KNRM);
    scanf("%s", accion);
  }
  killGeneros(generos);
  return 0;
}
