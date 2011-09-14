
#include "cMusica.h"

/*
    bool esMusica;
    Mix_Chunk *sonido;
    Mix_Music *cancion;
    int canal;
    int volumen;
*/

Musica::Musica(bool esM)
{
    esMusica = esM;
    sonido = NULL;
    cancion = NULL;
}
Musica::Musica(bool esM, Mix_Chunk *son, Mix_Music *can)
{
    esMusica = esM;
    if (esMusica)
    {
        cancion = can;
        sonido = NULL;
    }
    else
    {
        sonido = son;
        cancion =  NULL;
    }
}
Musica::~Musica()
{
    if (esMusica)
        Mix_FreeMusic(cancion);
    else
        Mix_FreeChunk(sonido);
}
Mix_Chunk *Musica::getSonido()
{
    return sonido;
}
Mix_Music *Musica::getCancion()
{
    return cancion;
}

int Musica::getCanal()
{
    return canal;
}
int Musica::getVolumen()
{
    return volumen;
}
int Musica::cargarSonMus(string ruta)
{
    if (esMusica)
        cancion = Mix_LoadMUS (ruta.c_str());
    else
        sonido =  Mix_LoadWAV (ruta.c_str());

   /* if (((esMusica) && (cancion = NULL)) || ((!esMusica) && (sonido = NULL)))
    {
        cout << "sonido/musica: " << ruta.c_str() << " NO se ha cargado correctamente\n";
        return -1;
    }
    else
    {
        cout << "sonido/musica: " << ruta.c_str() << " SI se ha cargado correctamente\n";
        return 0;
    }*/ return 0;

}
int Musica::reproducirSonMus(int veces)
{

    if (esMusica)
    {
        return Mix_PlayMusic(cancion,veces);
        cout << "reproduciendo cancion\n";
    }
    else
    {
        Mix_AllocateChannels(16);
        return Mix_PlayChannel(-1, sonido,veces);
        cout << "reproduciendo sonido";
    }
}
int Musica::pausarSonMus()
{
    Mix_PauseMusic();
}
int Musica::reanudarSonMus()
{
    Mix_ResumeMusic();

}
int Musica::pararSonMus()
{
    return Mix_HaltMusic();
}

int Musica::subirVolumen()
{
    int porciento = ((5*128)/100);
    int volumen2 = 0;
    if (esMusica)
    {
        volumen2 = porciento + Mix_VolumeMusic(-1);
        Mix_VolumeMusic(volumen2);
    }
    else
    {
       volumen2 = porciento + sonido->volume;
       Mix_VolumeChunk(sonido, volumen2);
    }
    volumen= volumen2;
}
int Musica::bajarVolumen()
{
    int porciento = ((5*128)/100);
    int volumen2 = 0;

    if (esMusica)
    {
        volumen2 = Mix_VolumeMusic(-1) - porciento;
        Mix_VolumeMusic(volumen2);
    }
    else
    {
       volumen2 = sonido->volume - porciento;
       Mix_VolumeChunk(sonido, volumen2);
    }
    volumen = volumen;
}
int Musica::fadeOutSonMus(int ms)
{

    if (esMusica)
    {
        return Mix_FadeOutMusic(ms);
    }
    else
    {
        return Mix_FadeOutChannel(-1, ms);
    }
}
int Musica::fadeInSonMus(int ms)
{
    if (esMusica)
    {
        return Mix_FadeInMusic(cancion, 1, ms);
    }
    else
    {
        return Mix_FadeInChannel(-1, sonido, 0, ms);
    }
}

void Musica::liberarRecursosSonMus(void)
{
    if (esMusica)
        Mix_FreeMusic(cancion);
    else
        Mix_FreeChunk(sonido);
}



