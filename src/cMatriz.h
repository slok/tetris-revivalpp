#ifndef MATRIZ_H
#define MATRIZ_H

#include "cBloque.h"
#include "cNivel.h"


class Matriz
{
private:
    Bloque rejilla[10][20];

public:
    Matriz(int pixel, int espacioX, int espacioY);
    Matriz(int pixel, int espacioX, int espacioY, int obstaculosFila, int nivel);
    ~Matriz();
    bool filaCompleta(int numFila, Nivel *niv, int *puntos); //dice si la fila esta completa (cierto = si) e incrementa puntos
    void bajarFilas(int fila); //baja todas las filas a partir de la dada hasta que se ecuentre una sin bloques (se le pasa la fila "completa")
    int getColorMatriz(int x, int y);
    int getXMatriz(int x, int y);
    int getYMatriz(int x, int y);
    int getNumeroMatriz(int x, int y);
    SDL_Rect getPosMatriz(int x, int y);
    void setColorMatriz(int x, int y, int color);
    void setNumeroMatriz(int x, int y,int numero);
    int contarOcupados(void);
    void rellenarPosiciones(int obstaculosFila,int nivel);
};
#endif
