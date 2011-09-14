
# ifndef UMAIN_H
# define UMAIN_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include "cBloque.h"
#include "cMusica.h"
#include "uImagenes.h"
#include "cMatriz.h"
#include "cPieza.h"
#include "SDL_ttf.h"
#include "uFuentes.h"
#include "uMenu.h"
#include "cNivel.h"
#include "uFicheros.h"
#include "uContenedor.h"

void pintarMatrizConsola(Matriz mi);
void iniciarLibrerias(void);
void finalizarLibrerias(void);
string devolverRutaCancion(int nCancion);
void gameLoop(void);
void bajarPieza(Matriz *ma, Pieza *pi);
int jugar(int opcion, multimap<int, string> *contenedor, multimap<int, string> *contenedorExt, SDL_Surface *pantalla, Matriz matriz);

#endif
