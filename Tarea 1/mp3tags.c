#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Imports/mp3tags.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

int leerID3(const char* Filename, id3tag *ID3Tag){
	FILE *fp=fopen(Filename,"rb");
	if (fp == NULL) {
		return 0;
	}
	char buffer[128];
	int x;
	fseek(fp,-128,SEEK_END);
	fread(buffer,sizeof(char),sizeof(buffer),fp);

	if(!(buffer[0]=='T' && buffer[1] == 'A' && buffer[2] == 'G')){
		fclose(fp);
		return 0;
	}

	for(x=0;x<30;x++)
		ID3Tag->title[x] = buffer[x+3]; //take 3 off cause of TAG
		ID3Tag->title[30] = '\0';

	for(x=0;x<30;x++)
		ID3Tag->artist[x] = buffer[x+33]; //33 = TAG + title
		ID3Tag->artist[30] = '\0';

	for(x=0;x<30;x++)
		ID3Tag->album[x] = buffer[x+63]; //TAG + title + artist
		ID3Tag->album[30] = '\0';

	for(x=0;x<4;x++)
		ID3Tag->year[x] = buffer[x+93]; //TAG + title + artist + album
		ID3Tag->year[4] = '\0';

	for(x=0;x<30;x++)
		ID3Tag->comment[x] = buffer[x+97]; //TAG + title + artist + album + year
		ID3Tag->comment[30] = '\0';

	if(buffer[127] > 0 && buffer[127] < 256)
		ID3Tag->genre = buffer[127]; //If its between 1-255, put it
	else
		ID3Tag->genre = 255; //255 means unused

	//ID3 1.1 compatibility (Track field)
	if(ID3Tag->comment[28] == '\0')
		ID3Tag->track = ID3Tag->comment[29]; //If comment ends at 28.. then 29 is the track
	else
		ID3Tag->track = 0; //0 mean's unknown track
	fclose(fp);
	return 1;
}

void mostrarID3(const char* Filename, char **generos){
	id3tag *cancion = (id3tag *)malloc(sizeof(id3tag));
	if (leerID3(Filename, cancion)) {
		printf("Titulo: %s\n", cancion->title);
		printf("Artista: %s\n", cancion->artist);
		printf("Album: %s\n", cancion->album);
		printf("Anio: %s\n", cancion->year);
		printf("Genero: %s\n\n", generos[cancion->genre]);
	} else {
		printf(KRED"%s\n"KNRM, "Canción no encontrada");
	}


	free(cancion);
}
