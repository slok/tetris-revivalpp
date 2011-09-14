
#include <string>
#include <fstream>
#include "cNivel.h"
#include "cMatriz.h"
#include "uFicheros.h"
#include "uContenedor.h"

/*void guardarMatrizFichero(Matriz *matriz, Nivel nivel, int puntuacion )
{
    int y,x;
    ofstream ficheroMatriz("data/saves/savematriz",ios::out);
    ofstream ficheroDatos("data/saves/savedatos",ios::out);
//guardamos la matriz
    for  (y=0;y<20;y++)
    {
        for (x=0;x<10;x++)
        {
            ficheroMatriz << ((*matriz).getColorMatriz(x,y));
        }
    }
//guardamos los datos de nivel y puntuacion, con este orden por linea:fondo, puntuacion nivel, nivel, velocidad y puntuacion
    ficheroDatos << nivel.getFondo() << endl;
    ficheroDatos << nivel.getPuntuacion() << endl;
    ficheroDatos << nivel.getnNivel() << endl;
    ficheroDatos << nivel.getVelocidad() << endl;
    ficheroDatos << puntuacion;

    ficheroMatriz.close();
    ficheroDatos.close();
}
void cargarMatrizFichero(Matriz *matriz)
{
    int y,x;
    char c;
    //char buffer[255];

    ifstream fichero("data/saves/savematriz",ios::in);
    //fichero >>buffer;
    for  (y=0;y<20;y++)
        for (x=0;x<10;x++)
        {
            fichero.get(c);
            (*matriz).setColorMatriz(x,y,int(c));
        }

}*/

void guardarContenedor(int opt, multimap<int, string> *contenedor)
{


    multimap<int, string>::reverse_iterator apuntador; //iterador reverrse para recorrerlo al reves poniendo los mayores arriba
    apuntador=contenedor->rbegin(); //comienzo reversible desde atras
    if (opt==0)
    {
        ofstream fichero("data/saves/saveContenedor",ios::out);
        for (int i=0; i<10;i++)
        {
            fichero<< apuntador->second<<endl;
            fichero << apuntador->first<< endl;
            apuntador++; //por el iterador reverse se hace ++ y no --
        }
        fichero.close();
    }
    else
    {
        ofstream fichero2("data/saves/saveContenedorExt",ios::out);
        for (int i=0; i<10;i++)
        {
            fichero2<< apuntador->second<<endl;
            fichero2 << apuntador->first<< endl;
            apuntador++; //por el iterador reverse se hace ++ y no --
        }
         fichero2.close();
    }


    cout << "escritura de contenedor en fichero [ OK ]" << endl;
}
void leerContenedor(int opt, multimap<int, string> *contenedor)
{
    string nombre;
    int puntos;


    if (opt==0)
    {
        ifstream fichero3("data/saves/saveContenedor",ios::in);
        for (int i=0; i<10;i++)
        {
            fichero3 >> nombre;
            fichero3 >> puntos;
            insertarPuntuacion(contenedor, nombre, puntos);
            cout << "nombre:  " << nombre << "  puntos: " <<  puntos<< endl;
        }
        fichero3.close();

    }
    else
    {
        ifstream fichero4("data/saves/saveContenedorExt",ios::in);
        for (int i=0; i<10;i++)
        {
            fichero4 >> nombre;
            fichero4 >> puntos;
            insertarPuntuacion(contenedor, nombre, puntos);
            cout << "nombre:  " << nombre << "  puntos: " <<  puntos<< endl;
        }
        fichero4.close();

    }
    cout << "carga de fichero a contenedor [ OK ]" << endl;


}
