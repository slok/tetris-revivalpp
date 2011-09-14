
#include <SDL_ttf.h>
#include "uFuentes.h"

TTF_Font *abrirFuente(string ruta, int tam)
{
    TTF_Font *fuente;
    fuente = TTF_OpenFont(ruta.c_str(), tam);
    return fuente;
}
void cerrarFuente(TTF_Font *fuente)
{
    TTF_CloseFont(fuente);
}
SDL_Surface *cargarTexto(string texto,TTF_Font *fuente, int r, int g,int b)
{
    SDL_Color fondo={255,0,255}, letra={r, g, b};
    SDL_Surface *imagenTexto=NULL;

    /*imagenTexto = TTF_RenderText_Shaded(fuente, texto.c_str(), letra, fondo);
    SDL_SetColorKey(imagenTexto,SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(imagenTexto->format,255,0,255));*/

    imagenTexto = TTF_RenderText_Blended(fuente, texto.c_str(), letra);
    return imagenTexto;

}

char *integerAChar(int numero)
{
    char buffer[100];
    sprintf(buffer,"%d", numero);
    return buffer;
}
