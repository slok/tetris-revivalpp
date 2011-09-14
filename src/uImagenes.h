#ifndef UIMAGENES_H
#define UIMAGENES_H

//funciones basicas de carga y pintado de imagenes

#include <SDL_image.h>
#include <SDL.h>
#include <iostream>
#include <string>
#include <SDL_ttf.h>
#include <map>
#include "cMatriz.h"
#include "cPieza.h"
#include "uFuentes.h"
#include "cInsercionString.h"
#include "uContenedor.h"
#include "uFicheros.h"

using namespace std;

SDL_Surface *cargarImagen(string ruta);                             //carga una imagen y la optimiza
SDL_Surface *crearPantalla(int ancho, int alto, int profundidad);   //Crea una pantalla (ventana)
void blittingImagen(SDL_Surface *imagen, SDL_Rect *corte, SDL_Surface *pantalla, SDL_Rect posicion);//Hace blitting de una imagen
void blittingImagen(SDL_Surface *imagen, SDL_Rect *corte, SDL_Surface *pantalla,int x, int y); // hace blitting con coordenadas
void rellenarPantalla (SDL_Surface *destino, SDL_Rect posTam, int r, int g, int b);// rellena la pantalla con un color pasado por RGB
void transparentar(SDL_Surface *imagen, int gradoTrans);            //aplica alpha blending ha una imagen
void recortarImagen(SDL_Surface *superficie, SDL_Rect tamPos);      //Recorta la imagen
void flipEnPantalla(SDL_Surface *pantalla);                         //hace un flip en pantalla
void nombreVentana(string titulo);                                  //aplica el titulo  ha la ventana principal
SDL_Rect *cargarBloques(void);
SDL_Rect *cargarPiezas(void);
void dibujarMatriz(Matriz matriz, SDL_Surface *bloques, SDL_Surface *pantalla, SDL_Rect * arrayBloques);
bool dibujarHighScore(int opt, multimap<int, string> *contenedor, SDL_Surface * pantalla);
#endif
