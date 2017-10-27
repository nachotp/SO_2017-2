#include "Imports/funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include "Imports/mp3tags.h"

void mostrar(){
  DIR *dp = NULL;
  struct dirent *dptr = NULL;

  dp = opendir(".");

  while ((dptr = readdir(dp)) != NULL) {
    if (dptr->d_name[0] != '.') {
      printf(" - %s\n", dptr->d_name);
    }
  }
  closedir(dp);
  printf("\n");
}

void crearDir(char *nombre){
  mkdir(nombre, 0777);
}

char **cargarGeneros(){
  char **generos = (char **)malloc(80*sizeof(char *));
  FILE *fp;
  int i;
  fp = fopen("generos.txt","r");
  for (i = 0; i < 80; i++) {
    generos[i] = (char *)malloc(sizeof(char)*100);
    fgets(generos[i], 100, fp);
    generos[i][strcspn(generos[i], "\n")] = '\0';
  }
  fclose(fp);
  return generos;
}

void killGeneros(char **generos){
  int i;
  for (i = 0; i < 80; i++) free(generos[i]);
  free(generos);
}

void organizar(char **generos){
  DIR *artistdp,*dp = NULL;
  struct dirent *artdptr, *dptr = NULL;
  id3tag *cancion;
  char dir[200];
  char nuevodir[200];

  dp = opendir("Biblioteca De Musica");
  chdir("Biblioteca De Musica");
  //cancion = (id3tag *)malloc(sizeof(id3tag));
  //ordenamos por genero
  while ((dptr = readdir(dp)) != NULL) {
    if (dptr->d_name[0] != '.') {
      cancion = (id3tag *)malloc(sizeof(id3tag));
      leerID3(dptr->d_name, cancion);
      crearDir(generos[cancion->genre]);
      sprintf(dir,"./%s", dptr->d_name);
      sprintf(nuevodir,"./%s/%s",generos[cancion->genre], dptr->d_name);
      rename(dir,nuevodir);
      free(cancion);
    }
  }
  closedir(dp);
  //ordenamos por artista
  dp = opendir(".");
  while ((dptr = readdir(dp)) != NULL) {
    if (dptr->d_name[0] != '.') {
      artistdp = opendir(dptr->d_name);
      chdir(dptr->d_name);
      while ((artdptr = readdir(artistdp)) != NULL) {
        if (artdptr->d_name[0] != '.') {
          cancion = (id3tag *)malloc(sizeof(id3tag));
          leerID3(artdptr->d_name, cancion);
          crearDir(cancion->artist);
          sprintf(dir,"./%s", artdptr->d_name);
          sprintf(nuevodir,"./%s/%s",cancion->artist, artdptr->d_name);
          rename(dir,nuevodir);
          free(cancion);
        }
    }
    chdir("..");
    closedir(artistdp);
    }
  }
  closedir(dp);
}

void azar(char *basedir){
  char dir[200];
  getcwd(dir,200);
  chdir(basedir);
  time_t t;
  srand((unsigned) time(&t));
  DIR *dp = NULL;
  struct dirent *dptr = NULL;
  int pickGen, maxGen = 0;
  dp = opendir(".");
  while ((dptr = readdir(dp)) != NULL){
    if (dptr->d_name[0] != '.') maxGen++;
  }
  pickGen = (rand() % maxGen) + 1;
  closedir(dp);
  dp = opendir(".");
  while (pickGen > 0 && (dptr = readdir(dp)) != NULL) {
    if (dptr->d_name[0] != '.') pickGen--;
  }
  closedir(dp);
  chdir(dptr->d_name);

  dp = opendir(".");
  maxGen = 0;
  while ((dptr = readdir(dp)) != NULL){
    if (dptr->d_name[0] != '.') maxGen++;
  }
  pickGen = (rand() % maxGen) + 1;
  closedir(dp);

  dp = opendir(".");
  while (pickGen > 0 && (dptr = readdir(dp)) != NULL) {
    if (dptr->d_name[0] != '.') pickGen--;
  }
  closedir(dp);
  printf("%s\n", dptr->d_name);
  chdir(dptr->d_name);
  mostrar();
  printf("\n");

  chdir(dir);
}
