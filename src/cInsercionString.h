
#ifndef CINSERCIONSTRING_H
#define CINSERCIONSTRING_H

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <map>
#include "uImagenes.h"
#include "uMain.h"

using namespace std;

class InsercionString
{
private:

string nombre;
SDL_Surface *texto;

public:

InsercionString(void);
~InsercionString(void);
string getNombreInsercion(void);
SDL_Surface *getTextoInsercion(void);
void gestionInsertarStringYDibujar(int ganar, int puntos, multimap <int, string> *hallOfFame, SDL_Surface *pantalla); //recoje las pulsaciones del usuario en el objeto
};

#endif
