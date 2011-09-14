#ifndef MUSICA_H
#define MUSICA_H

#include <SDL_mixer.h>
#include <iostream>
#include <string>

using namespace std;

class Musica
{
private:

    bool esMusica;
    Mix_Chunk *sonido;
    Mix_Music *cancion;
    int canal;
    int volumen;

public:

    Musica(bool esM);                                   //Constructor
    Musica(bool esM, Mix_Chunk *son, Mix_Music *can);   //Constructor
    ~Musica();                                          //Destructor
    Mix_Chunk *getSonido();                             //Devuelve el sonido (Mix_Chunk)
    Mix_Music *getCancion();                            //Devuelve la musica (Mix_Music)
    int getCanal();                                     //Devuelve el canal en el que esta el sonido/musica
    int getVolumen();                                   //Devuelve el volumen

    int cargarSonMus(string ruta);                      //Carga el sonido/musica a partir de la ruta
    int reproducirSonMus(int veces);                    //Reproduce un sonido/musica
    int pausarSonMus();                                 //Pausa la musica
    int reanudarSonMus();                               //Reanuda el sonido/musica
    int pararSonMus();                                  //Stop del sonido/musica
    int subirVolumen();                                 //Sube un 5% el volumen del sonido/musica
    int bajarVolumen();                                 //Baja un 5% el volumen del sonido/musica
    int fadeOutSonMus(int ms);                          //La musica/sonido va difuminandose hasta desaparecer
    int fadeInSonMus(int ms);                           //La musica/sonido  va difuminandose hasta estabilizarse
    void liberarRecursosSonMus(void);

};

#endif
