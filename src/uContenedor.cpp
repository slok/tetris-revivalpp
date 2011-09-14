
#include <map>
#include <string>
#include <iostream>
#include "uContenedor.h"


/*multimap<int, string> crearContenedor(void)
{
    multimap <int, string> *contenedor;
    return *contenedor;
}*/
void borrarContenedor(multimap<int, string> *contenedor)
{
    contenedor->clear();
}
void insertarPuntuacion(multimap<int, string> *contenedor, string nombre, int puntuacion )
{
    int cuantos;

    multimap<int, string>::iterator apuntador = contenedor->begin();
    contenedor->insert(multimap<int, string>::value_type(puntuacion, nombre));
    cout << "insertando puntuacion" << endl;
    cuantos = contenedor->size();
    //eliminacion en el caso de que haya mas de 10 puntuaciones
    while (cuantos > 10)
    {
        contenedor->erase(apuntador);
        apuntador++;cuantos--;
        cout << "eliminando puntuacion" << endl;
    }


}

