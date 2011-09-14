#ifndef UCONTENEDOR_H
#define UCONTENEDOR_H

#include <map>
#include <string>


using namespace std;


// multimap<int, string> crearContenedor(void);
 void borrarContenedor(multimap<int, string> *contenedor);
 void insertarPuntuacion(multimap<int, string> *contenedor, string nombre, int puntuacion );

#endif
