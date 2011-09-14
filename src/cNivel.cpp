

#include "cNivel.h"
#include "uImagenes.h"

/*
SDL_Surface *fondo;
int puntuacion, nNivel, velocidad;
*/

Nivel::Nivel(SDL_Surface *fond,int puntu, int numNivel, int velMS )
{
    fondo=fond;
    puntuacion = puntu;
    nNivel = numNivel;
    velocidad = velMS;
}
Nivel::Nivel(string fond,int puntu, int numNivel, int velMS )
{
    fondo = cargarImagen(fond);
    puntuacion = puntu;
    nNivel = numNivel;
    velocidad = velMS;
}
Nivel::~Nivel()
{
    SDL_FreeSurface(this->fondo);
}
SDL_Surface *Nivel::getFondo(void)
{
    return fondo;
}
int Nivel::getPuntuacion(void)
{
    return puntuacion;
}
int Nivel::getnNivel(void)
{
    return nNivel;
}
int Nivel::getVelocidad(void)
{
    return velocidad;
}
void Nivel::incrementarNivel(SDL_Surface *fondoNuevo)
{
    nNivel++;
    velocidad-=15;
    puntuacion=puntuacion*2;
    SDL_FreeSurface(fondo);
    fondo = fondoNuevo;
}
void Nivel::incrementarNivel(string fondoNuevo)
{
    nNivel++;
    velocidad-=15;
    puntuacion=puntuacion*2;
    SDL_FreeSurface(fondo);
    fondo = cargarImagen(fondoNuevo);
}
void Nivel::incrementarNivel()
{
    nNivel++;
    velocidad-=15;
    puntuacion=puntuacion*2;
}
