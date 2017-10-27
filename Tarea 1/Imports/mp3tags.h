#ifndef MP3
#define MP3

typedef struct _id3tag
{
	char title[30];
	char artist[30];
	char album[30];
	char year[4];
	char comment[30];
	unsigned char track;
	unsigned char genre;
} id3tag;

int leerID3(const char* Filename, id3tag* ID3Tag);

void mostrarID3(const char* Filename, char **generos);

#endif
