
#ifndef CNIVEL_H
#define CNIVEL_H

#include <SDL.h>
#include <string>
#include <iostream>
using namespace std;

class Nivel
{
private:

SDL_Surface *fondo;
int puntuacion, nNivel, velocidad;

public:

Nivel(SDL_Surface *fond,int puntu, int numNivel, int velMS );
Nivel(string fond,int puntu, int numNivel, int velMS );
~Nivel();
SDL_Surface *getFondo(void);
int getPuntuacion(void);
int getnNivel(void);
int getVelocidad(void);
void incrementarNivel(SDL_Surface *fondoNuevo);
void incrementarNivel(string fondoNuevo);
void incrementarNivel(void);
};

#endif
