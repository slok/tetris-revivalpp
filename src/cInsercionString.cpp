
#include <SDL_ttf.h>
#include "uFuentes.h"
#include "cInsercionString.h"


InsercionString::InsercionString(void)
{
    nombre = ""; //inicializamos string
    texto = NULL;
    SDL_EnableUNICODE( SDL_ENABLE ); //habilitamos el unicode para SDL
}
InsercionString::~InsercionString(void)
{
    SDL_FreeSurface(texto);
    SDL_EnableUNICODE( SDL_DISABLE ); //deshabilitamos el unicode para SDL


}

string InsercionString::getNombreInsercion(void)
{
    return nombre;
}

SDL_Surface *InsercionString::getTextoInsercion(void)
{
    return texto;
}

void InsercionString::gestionInsertarStringYDibujar(int ganar, int puntos, multimap <int, string> *hallOfFame, SDL_Surface *pantalla)
{
    SDL_Event evento;
    string temp; //variable temporal para la comparacion de strings
    SDL_Surface *fondo;
    SDL_Rect posNombre,posFondo;
    Uint32 timdespues,timantes = SDL_GetTicks();
    bool salir=0;
    TTF_Font *fuente = abrirFuente("data/fuentes/gow.ttf",70 ); //abrimos la fuente

    //asignamos posicion en pantalla
    posFondo.x= 0;
    posFondo.y=0;
    posNombre.x= 350;
    posNombre.y= 400;
    //cargamos imagen
    if (!ganar)
        fondo = cargarImagen("data/imagenes/record.png");
    else
        fondo = cargarImagen("data/imagenes/pasado.png");


    while (!salir)
    {
       while (SDL_PollEvent (&evento))
       {
            if (evento.type==SDL_QUIT)
            {
                finalizarLibrerias();
                exit(0);
            }
            // si pulsa enter salimos del bucle ya que inserto el nombre
            else if( ( evento.type == SDL_KEYDOWN ) && ( evento.key.keysym.sym == SDLK_RETURN ) )
            {
                salir=1;
                insertarPuntuacion(hallOfFame, nombre, puntos); //insertamos el nombre en el contenedor
            }
            // si no salimos recojemos teclas de pulsaciones
            else if(evento.type == SDL_KEYDOWN )
            {
                std::string temp = nombre;

                if( nombre.length() <= 16 )
                {
                    if( evento.key.keysym.unicode == (Uint16)' ' ) //si es espacio en blanco
                    {
                        nombre += "_"; //(char)event.key.keysym.unicode;
                    }
                    else if( ( evento.key.keysym.unicode >= (Uint16)'0' ) && ( evento.key.keysym.unicode <= (Uint16)'9' ) ) //si es numero entonces
                    {
                            nombre += (char)evento.key.keysym.unicode;
                    }
                    else if( ( evento.key.keysym.unicode >= (Uint16)'A' ) && ( evento.key.keysym.unicode <= (Uint16)'Z' ) ) //si es letra mayuscula entonces
                    {
                            nombre += (char)evento.key.keysym.unicode;
                    }
                    else if( ( evento.key.keysym.unicode >= (Uint16)'a' ) && ( evento.key.keysym.unicode <= (Uint16)'z' ) ) //si es letra minuscula entonces
                    {
                            nombre += (char)evento.key.keysym.unicode;
                    }
                }

                if( ( evento.key.keysym.sym == SDLK_BACKSPACE ) && ( nombre.length() != 0 ) )  //si borra un caracter eliminamos el ultimo
                {
                    nombre.erase( nombre.length() - 1 );
                }
                //si son diferentes cargamos texto en uns SDL_Surface, si no es tonteria hacerlo
                if( nombre != temp )
                {
                    SDL_FreeSurface( texto );//liberamos texto antes de cargarlo denuevo
                    if (!ganar)
                        texto = cargarTexto(nombre,fuente, 250, 200, 230);
                    else
                        texto = cargarTexto(nombre,fuente, 176, 82, 187);
                }

            }
        }

         timdespues = SDL_GetTicks();
        if ((timdespues-timantes) >= (1000/60)) //pintamos a 60 FPS
        {
            timantes = timdespues;
            blittingImagen(fondo, NULL, pantalla, posFondo);
            if (nombre.length() != 0) //cuando no sea null el string para evitar errores de blitting y de "texto->w" ya que es nulo
            {
                posNombre.x=((800 - texto->w) / 2); //aplicamos el centrado de pantalla (con division entera, para no dar errores)
                blittingImagen(texto, NULL, pantalla, posNombre);
            }
            flipEnPantalla(pantalla);
        }
    }

    cerrarFuente(fuente); //cerramos la fuente para la memoria
    nombre="";// aplicamos esto apra que
}

