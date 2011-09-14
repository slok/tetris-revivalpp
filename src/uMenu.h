# ifndef UMENU_H
# define UMENU_H

# include "map"
# include "uImagenes.h"
# include "cMusica.h"
# include "uFuentes.h"
# include "cNivel.h"
# include "cInsercionString.h"

int menuPrincipal(SDL_Surface *pantalla, multimap<int, string> *contenedor, multimap<int, string> *contenedorExt);
int menuPausa(Matriz *rejilla,SDL_Rect *rectRejilla, SDL_Surface *pantalla, Nivel *nivel, SDL_Surface *rejillaPuntos, SDL_Surface *rejillaSiguiente,
                SDL_Surface *imagenPieza, SDL_Surface *imagenPuntos, SDL_Surface *imagenNivel, SDL_Surface *imagFilas, SDL_Surface *rejillaMusica,
                SDL_Surface *imagCancion,SDL_Rect *posPrevPieza, int piezaMomento, SDL_Surface *nombreJuego);
int menuMuerte(int opcion, Matriz *rejilla,SDL_Rect *rectRejilla, SDL_Surface *pantalla, Nivel *nivel, multimap<int, string> *contenedor, SDL_Surface *rejillaPuntos, SDL_Surface *rejillaSiguiente,
                SDL_Surface *imagenPieza, SDL_Surface *imagenPuntos, SDL_Surface *imagenNivel, SDL_Surface *imagFilas, SDL_Surface *rejillaMusica,
                SDL_Surface *imagCancion,SDL_Rect *posPrevPieza, int piezaMomento, SDL_Surface *nombreJuego);
# endif
