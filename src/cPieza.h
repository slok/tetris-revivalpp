#ifndef PIEZA_H
#define PIEZA_H

#include "cMatriz.h"
/*
id 1: (color 1 = rojo) pieza recta
id 2: (color 2 = amarillo) pieza cuadrada
id 3: (color 3 = naranja) pieza "T"
id 4: (color 4 = verde) pieza "L" invertida
id 5: (color 5 = morado) pieza "L"
id 6: (color 6 = azul oscuro) pieza escalon con el pico de arriba hacia la izquierda
id 7: (color 7 = azul claro) pieza escalon con el pico de arriba hacia la derecha
*/

class Pieza
{
private:
   struct posPi
    {
    int x;
    int y;
    } posiciones_de_pieza;

/////// variables
    posPi vectorBloques[4];
    int id;
    int posRot;
    int quieta;
/////// funciones privadas
    //rotaciones
    void rotarPieza0(Matriz *vector,int pos);
    void rotarPieza1(Matriz *vector,int pos);
    void rotarPieza2(Matriz *vector,int pos);
    void rotarPieza3(Matriz *vector,int pos);
    void rotarPieza4(Matriz *vector,int pos);
    void rotarPieza5(Matriz *vector,int pos);
    void rotarPieza6(Matriz *vector,int pos);
    //bajadas de pieza
    void bajarPieza0(Matriz *vector,int pos);
    void bajarPieza1(Matriz *vector,int pos);
    void bajarPieza2(Matriz *vector,int pos);
    void bajarPieza3(Matriz *vector,int pos);
    void bajarPieza4(Matriz *vector,int pos);
    void bajarPieza5(Matriz *vector,int pos);
    void bajarPieza6(Matriz *vector,int pos);
    //mover izquierda pieza
    void izquierdaPieza0(Matriz *vector, int pos);
    void izquierdaPieza1(Matriz *vector, int pos);
    void izquierdaPieza2(Matriz *vector, int pos);
    void izquierdaPieza3(Matriz *vector, int pos);
    void izquierdaPieza4(Matriz *vector, int pos);
    void izquierdaPieza5(Matriz *vector, int pos);
    void izquierdaPieza6(Matriz *vector, int pos);
    //mover izquierda pieza
    void derechaPieza0(Matriz *vector, int pos);
    void derechaPieza1(Matriz *vector, int pos);
    void derechaPieza2(Matriz *vector, int pos);
    void derechaPieza3(Matriz *vector, int pos);
    void derechaPieza4(Matriz *vector, int pos);
    void derechaPieza5(Matriz *vector, int pos);
    void derechaPieza6(Matriz *vector, int pos);
    //mira si hay debajo alguna pieza
    bool hayDebajo0(Matriz *vector, int pos);
    bool hayDebajo1(Matriz *vector, int pos);
    bool hayDebajo2(Matriz *vector, int pos);
    bool hayDebajo3(Matriz *vector, int pos);
    bool hayDebajo4(Matriz *vector, int pos);
    bool hayDebajo5(Matriz *vector, int pos);
    bool hayDebajo6(Matriz *vector, int pos);

public:
    Pieza(Matriz *vector, int color);
    ~Pieza();
    void rotarPieza(Matriz *vector);
    void bajarPieza(Matriz *vector);
    void izquierdaPieza(Matriz *vector);
    void derechaPieza(Matriz *vector);
    bool hayDebajo(Matriz *vector); //dice si en la siguiente linea hay algun bloque que haga contacto (cierto si hay piezas debajo)
    bool tocarTecho(Matriz *vector);
    bool final(void);
};

#endif
