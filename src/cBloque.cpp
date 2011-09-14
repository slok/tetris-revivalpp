

#include "cBloque.h"
/*
    int color;
    SDL_Rect pos;
*/


Bloque::Bloque()
{ }
Bloque::Bloque(int c, SDL_Rect p)
{
    color = c;
    pos = p;
}
Bloque::~Bloque()
{}

int Bloque::getColor()
{
    return color;
}
int Bloque::getX()
{
    return x;
}
int Bloque::getY()
{
    return y;
}
int Bloque::getNum()
{
    return num;
}
SDL_Rect Bloque::getPosicion()
{
  return pos;
}
void Bloque::setColor(int c)
{
    color = c;
}
void Bloque::setX(int n)
{
    x = n;
}
void Bloque::setY(int n)
{
    y = n;
}
void Bloque::setNum(int n)
{
    num = n;
}
void Bloque::setPosicion(SDL_Rect posicion)
{
    pos= posicion;
}
