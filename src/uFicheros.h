#ifndef UFICHEROS_H
#define UFICHEROS_H

#include <string>
#include <iostream>
#include <map>

using namespace std;

/*void guardarMatrizFichero(Matriz *matriz,Nivel nivel, int puntuacion);
void cargarMatrizFichero(Matriz *matriz);*/
void guardarContenedor(int opt, multimap<int, string> *contenedor);
void leerContenedor(int opt, multimap<int, string> *contenedor);

#endif
