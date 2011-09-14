
#include "uImagenes.h"

using namespace std;

SDL_Surface *cargarImagen(string ruta)
{
    SDL_Surface *imagAux=NULL, *imagOptima=NULL;
    imagAux = IMG_Load(ruta.c_str());
    if (imagAux==NULL)
        cout << "Cargando imagen (" << ruta << ") [ ERROR ] :  " << SDL_GetError << endl;
    else
    {
        imagOptima = SDL_DisplayFormat(imagAux);
        cout << "Cargando imagen (" << ruta << ") [ OK ] " << endl;
    }
    SDL_FreeSurface(imagAux);

    SDL_SetColorKey(imagOptima,SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(imagOptima->format,255,0,255)); //color ha trasnparentar (ROSA = 255,0,255)
    return imagOptima;

}
SDL_Surface *crearPantalla(int ancho, int alto, int profundidad)
{
    SDL_Surface *pantalla = NULL;
    pantalla = SDL_SetVideoMode(ancho, alto, profundidad, SDL_HWSURFACE| SDL_DOUBLEBUF);
    if (pantalla == NULL)
        cout << "Creando pantalla [ ERROR ] : "<< SDL_GetError << endl;
    else
    {
        cout << "Creando pantalla [ OK ] " << endl;
        return pantalla;
    }
}
//segundo argumento esta con puntero por que NULL es lo mas tipico
void blittingImagen(SDL_Surface *imagen, SDL_Rect *corte, SDL_Surface *pantalla, SDL_Rect posicion)
{
    int a;
    a = SDL_BlitSurface(imagen, corte, pantalla, &posicion);
    if (a>-1)
       {  }//cout << "Haciendo Blitting [ OK ] " << endl;
    else
        cout << "Haciendo Blitting [ ERROR ] : " << SDL_GetError << endl;
}

void blittingImagen(SDL_Surface *imagen, SDL_Rect *corte, SDL_Surface *pantalla,int x, int y)
{
    int a;
    SDL_Rect aux;
    aux.x=x; aux.y=y;
    a = SDL_BlitSurface(imagen, corte, pantalla, &aux);
    if (a>-1)
       {  }//cout << "Haciendo Blitting [ OK ] " << endl;
    else
        cout << "Haciendo Blitting [ ERROR ] : " << SDL_GetError << endl;
}

void rellenarPantalla (SDL_Surface *destino, SDL_Rect posTam, int r, int g, int b)
{
    int a;
    a = SDL_FillRect(destino, &posTam,SDL_MapRGB(destino->format,r,g,b));
    if (a>-1)
        cout << "Rellenando pantalla [ OK ] " << endl;
    else
        cout << "Rellenando pantalla [ ERROR ] : " << SDL_GetError << endl;
}
void transparentar(SDL_Surface *imagen, int gradoTrans)
{
    int a;
    a = SDL_SetAlpha(imagen, SDL_SRCALPHA|SDL_RLEACCEL, gradoTrans);
    if (a > -1)
        cout << "Aplicando blending [ OK ] " << endl;
    else
        cout << "Aplicando blending [ ERROR ] : " << SDL_GetError << endl;

}
void recortarImagen(SDL_Surface *superficie, SDL_Rect tamPos)
{
    SDL_SetClipRect(superficie, &tamPos);
    cout << "aplicando corte en: X = " << tamPos.x << ", y = " << tamPos.y << " de: H = " << tamPos.h << ", w = " << tamPos.w << " [ OK ] " << endl;
}
void flipEnPantalla(SDL_Surface *pantalla)
{
    int a;
    a = SDL_Flip(pantalla);

    if (a>-1)
        {}//cout << "Aplicando Flip en pantalla [ OK ] " << endl;
    else
        cout << "Aplicando Flip en pantalla [ ERROR ] : " << SDL_GetError << endl;
}
void nombreVentana (string titulo)
{
    SDL_WM_SetCaption(titulo.c_str(),NULL);
    cout << "Estableciendo titulo ha pantalla [ OK ]" << endl;
}
SDL_Rect *cargarBloques(void)
{
   SDL_Rect *arrayBloques;
   arrayBloques = new SDL_Rect [7];
   for (int i = 0; i< 7; i++)
    {
        arrayBloques[i].x = (20*i);
        arrayBloques[i].y = 0;
        arrayBloques[i].w = 20;
        arrayBloques[i].h = 20;
    }
    return arrayBloques;
}
SDL_Rect *cargarPiezas(void)
{
    SDL_Rect *arrayPiezas;
   arrayPiezas = new SDL_Rect [7];
   for (int i = 0; i< 7; i++)
    {
        arrayPiezas[i].x = (50*i);
        arrayPiezas[i].y = 0;
        arrayPiezas[i].w = 50;
        arrayPiezas[i].h = 80;
    }
    return arrayPiezas;
}
void dibujarMatriz(Matriz matriz, SDL_Surface *bloques, SDL_Surface *pantalla, SDL_Rect * arrayBloques)
{
     int color;
          for (int i=0; i < 20; i++)
        {
            for (int j=0; j<10; j++)
            {
               // cout << "x: " <<matriz.getPosMatriz(j,i).x <<"  y: " << matriz.getPosMatriz(j,i).y<< endl;
                color = matriz.getColorMatriz(j,i);
                switch (color)
                {
                    case 1: {
                                blittingImagen(bloques,&arrayBloques[0],pantalla, matriz.getPosMatriz(j,i));
                                break;
                            }
                    case 2: {
                                blittingImagen(bloques,&arrayBloques[1],pantalla, matriz.getPosMatriz(j,i));
                                break;
                            }

                    case 3: {
                                blittingImagen(bloques,&arrayBloques[2],pantalla, matriz.getPosMatriz(j,i));
                                break;
                            }
                    case 4: {
                                blittingImagen(bloques,&arrayBloques[3],pantalla, matriz.getPosMatriz(j,i));
                                break;
                            }
                    case 5: {
                                blittingImagen(bloques,&arrayBloques[4],pantalla, matriz.getPosMatriz(j,i));
                                break;
                            }
                    case 6: {
                                blittingImagen(bloques,&arrayBloques[5],pantalla, matriz.getPosMatriz(j,i));
                                break;
                            }
                    case 7: {
                                blittingImagen(bloques,&arrayBloques[6],pantalla, matriz.getPosMatriz(j,i));
                                break;
                            }
                    default: break;
                }
            }
        }
}

bool dibujarHighScore(int opt, multimap<int, string> *contenedor, SDL_Surface * pantalla)
{
    multimap<int, string>::reverse_iterator apuntador;
    char *auxiliar;
    int i;
    bool salir=0;
    SDL_Surface *fondo, *nombre, *puntos;
    SDL_Event evento;
    SDL_Rect posNombre, posPuntos, posFondo;
    Uint32 timdespues,timantes = SDL_GetTicks();
    TTF_Font *fuente;

    //abrimos fuente
    fuente = abrirFuente("data/fuentes/gow.ttf", 55);

    //creamos fondo y posiciones de pantalla para los nombres
    if (opt==0)
        fondo= cargarImagen("data/imagenes/highScore.png");
    else
        fondo= cargarImagen("data/imagenes/highscoreExtreme.png");
    //empezamos bucle
    while (!salir)
    {
        //iniciamos el iterador
        apuntador=contenedor->rbegin();
        //actualizamos coordenadas
        posNombre.x= 80;
        posPuntos.x= 650;
        posNombre.y= 55;
        posPuntos.y= 55;
        posFondo.x=0;
        posFondo.y=0;

        timdespues = SDL_GetTicks();
        if ((timdespues-timantes) >= (1000/60)) //aplicamos esto para que muestre el high-score en pantalla ha 60 FPS
        {
            timantes = timdespues;
            blittingImagen(fondo, NULL, pantalla, posFondo);
            for (i=0; i<10; i++)
            {
                //cargamos imagenes con lo que tiene el contenedor
                auxiliar= integerAChar(apuntador->first);
                puntos = cargarTexto(auxiliar, fuente, 000, 000, 000);
                nombre = cargarTexto(apuntador->second, fuente, 000, 000, 000);
                //actualizamos las posiciones
                posNombre.y+=45;
                posPuntos.y+=45;
                //aplicamos
                blittingImagen(nombre, NULL,pantalla, posNombre);
                blittingImagen(puntos, NULL,pantalla, posPuntos);
                apuntador++;
            }
            flipEnPantalla(pantalla);
        }
        while (SDL_PollEvent (&evento))
         {
           if (evento.type == SDL_QUIT)
           {
                finalizarLibrerias();
                exit(0);
           }
           if (evento.type == SDL_KEYDOWN)
             {
               switch (evento.key.keysym.sym)
                {
                    case    SDLK_ESCAPE:{salir=1; break;}
                }
            }
         }
    }
    cerrarFuente(fuente);

}



