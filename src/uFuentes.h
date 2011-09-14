#ifndef UFUENTES_H
#define UFUENTES_H

#include <string>
#include <iostream>
#include <SDL_ttf.h>
using namespace std;

TTF_Font *abrirFuente(string ruta, int tam);
void cerrarFuente(TTF_Font *fuente);
SDL_Surface *cargarTexto(string texto,TTF_Font *fuente,  int r, int g,int b);
char *integerAChar(int numero);
#endif
