
#ifndef BLOQUE_H
#define BLOQUE_H

#include <SDL.h>

class Bloque
{
private:
    int color;      //color de la pieza (identificador de tipo de pieza)
    int x, y;       //posicion en la matriz bidimensional
    int num;        //numero de pieza (de 1 a 4)
    SDL_Rect pos;   //coordenadas en pantalla de el bloque a pintar

public:
    Bloque();
    Bloque(int c, SDL_Rect p);
    ~Bloque();
    int getColor();
    int getX();
    int getY();
    int getNum();
    SDL_Rect getPosicion();
    void setColor(int c);
    void setX(int n);
    void setY(int n);
    void setNum(int n);
    void setPosicion(SDL_Rect posicion);
};

#endif
