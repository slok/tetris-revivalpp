
# include "uMenu.h"



//Menu Principal
int menuPrincipal(SDL_Surface *pantalla, multimap<int, string> *contenedor, multimap<int, string> *contenedorExt)
{
//Declaracion de variables
SDL_Rect rectAr[6], rectFondo={0,0};
SDL_Rect posCreditos;
    posCreditos.x=0;
    posCreditos.y=0;
SDL_Surface *opAr[6], *fondo=cargarImagen("data/imagenes/fondo.png");
SDL_Surface *creditos=cargarImagen("data/imagenes/creditos.png");
string titulos [6]={"Classic","Extreme","High Score Classic","High Score Extreme","Creditos","Salir"};

TTF_Font *fuenteSelect = abrirFuente("data/fuentes/Starjedi.ttf", 43), *fuenteOver = abrirFuente("data/fuentes/Starjhol.ttf", 40);
int opt=0,i, gradoTrans=255;
bool salir=0;

SDL_Event evento, evento2;

Uint32 timedespues,timeantes=SDL_GetTicks();

Musica chunkMenu(0);
Musica cancionMenu(1);
Musica chunkFinal(0);


//Activamos el modo repeticion de teclas para cauando se mantenga una tecla nos movamos por las opciones de forma constante
if (SDL_EnableKeyRepeat(500, 200)==-1)
    cout << "Activacion modo repeticion teclas [ ERROR ]" << endl;
else
    cout << "Activacion modo repeticion teclas [ OK ]" << endl;

//Carga de musica y chunks
chunkMenu.cargarSonMus("data/sonido/SonidoMenu.wav");
cancionMenu.cargarSonMus("data/sonido/tetris-ska.mp3");
chunkFinal.cargarSonMus("data/sonido/SonidoAgur.wav");

//Inicio de musica
cancionMenu.reproducirSonMus(-1);

//Carga de textos
opAr[0]=cargarTexto(titulos[0],fuenteSelect, 64,131,196); //25,67,225);

for (i=1; i<6; i++)
    opAr[i]=cargarTexto(titulos[i],fuenteOver,  255,255,255);

//Posición de textos
for (i=0; i< 6; i++)
{
    rectAr[i].x = 150;
    rectAr[i].y = (i*80)+95;
}

//Menu loop
while (!salir)
{
    timedespues = SDL_GetTicks();

    if ((timedespues-timeantes) >= (1000/60))
        {
            timeantes=timedespues;
            blittingImagen(fondo,NULL, pantalla, rectFondo);
            for (i=0; i<6;i++)
            blittingImagen(opAr[i],NULL, pantalla, rectAr[i]);
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
                    case    SDLK_UP:    {
                                            chunkMenu.reproducirSonMus(0); //Para que suene cuando vayas por las opciones
                                            if (opt==0)
                                            {
                                                SDL_FreeSurface(opAr[opt]);
                                                SDL_FreeSurface(opAr[5]);
                                                opAr[opt]=cargarTexto(titulos[opt],fuenteOver,  255,255,255);
                                                opAr[5]=cargarTexto(titulos[5],fuenteSelect,  64,131,196);
                                                opt=5;
                                            }
                                            else
                                            {
                                                SDL_FreeSurface(opAr[opt]);
                                                SDL_FreeSurface(opAr[opt-1]);
                                                opAr[opt]=cargarTexto(titulos[opt],fuenteOver,  255,255,255);
                                                opAr[opt-1]=cargarTexto(titulos[opt-1],fuenteSelect,  64,131,196);
                                                opt--;
                                            }
                                            break;
                                        }
                    case   SDLK_DOWN:   {
                                            chunkMenu.reproducirSonMus(0);
                                            if (opt==5)
                                            {
                                                SDL_FreeSurface(opAr[opt]);
                                                SDL_FreeSurface(opAr[0]);
                                                opAr[opt]=cargarTexto(titulos[opt],fuenteOver,  255,255,255);
                                                opAr[0]=cargarTexto(titulos[0],fuenteSelect,64,131,196);
                                                opt=0;
                                            }
                                            else
                                            {
                                                SDL_FreeSurface(opAr[opt]);
                                                SDL_FreeSurface(opAr[opt+1]);
                                                opAr[opt]=cargarTexto(titulos[opt],fuenteOver,  255,255,255);
                                                opAr[opt+1]=cargarTexto(titulos[opt+1],fuenteSelect,64,131,196);
                                                opt++;
                                            }
                                            break;
                                        }
                    case   SDLK_RETURN: {
                                            switch (opt)
                                            {
                                                case 0:
                                                    {
                                                        //Classic
                                                        cout << "A jugar Classic"<< endl;
                                                        salir=1;
                                                        return 1;
                                                        break;
                                                    }
                                                case 1:
                                                    {
                                                        //Extreme
                                                        cout << "A jugar Extreme"<< endl;
                                                        salir=1;
                                                        return 2;
                                                        break;
                                                    }
                                                case 2:
                                                    {
                                                        //High Score Classic
                                                        cout << "A high score classic" << endl;
                                                        dibujarHighScore(0,contenedor, pantalla);
                                                        break;
                                                    }
                                                case 3:
                                                    {
                                                        //High Score Classic
                                                        cout << "A high score extreme" << endl;
                                                        dibujarHighScore(1,contenedorExt, pantalla);
                                                        break;
                                                    }
                                                case 4:
                                                    {
                                                        //Creditos
                                                        cout << "A los créditos"<< endl;
                                                        int salCred=0;
                                                        blittingImagen(creditos, NULL, pantalla, posCreditos);
                                                        while (!salCred)
                                                        {
                                                            while (SDL_PollEvent (&evento2))
                                                            {
                                                                if (evento2.type == SDL_KEYDOWN)
                                                                    if (evento2.key.keysym.sym==SDLK_ESCAPE)
                                                                        salCred=1;
                                                            }
                                                            timedespues=SDL_GetTicks();
                                                            if ((timedespues-timeantes) >= (1000/60))
                                                            {
                                                                timeantes=timedespues;
                                                                flipEnPantalla(pantalla);
                                                            }
                                                        }
                                                        break;
                                                    }
                                                case 5:
                                                    {
                                                        //Salir
                                                        cancionMenu.pararSonMus();
                                                        chunkFinal.reproducirSonMus(0);
                                                        salir=1;
                                                        SDL_Delay(1000);
                                                        return 3;
                                                        break;
                                                    }
                                            }
                                            break;
                                        }
                }
        }
    }
}

//Cierre de los recursos
cerrarFuente(fuenteOver);
cerrarFuente(fuenteSelect);
for (i=0;i<6;i++)
    SDL_FreeSurface(opAr[i]);
SDL_FreeSurface(fondo);

}



//Menu Pausa
int menuPausa(Matriz *rejilla,SDL_Rect *rectRejilla, SDL_Surface *pantalla, Nivel *nivel, SDL_Surface *rejillaPuntos, SDL_Surface *rejillaSiguiente,
                SDL_Surface *imagenPieza, SDL_Surface *imagenPuntos, SDL_Surface *imagenNivel, SDL_Surface *imagFilas, SDL_Surface *rejillaMusica,
                SDL_Surface *imagCancion,SDL_Rect *posPrevPieza, int piezaMomento, SDL_Surface *nombreJuego)

{
//Declaracion de variables
string titulos [2]={"Resume","Salir al menu"};
SDL_Rect rectAr[2], rectFondo={0,0}, rectplaca={46,117};
SDL_Surface *opAr[2];
SDL_Surface *fondonegro=cargarImagen("data/imagenes/fondonegro.png"), *bloques=cargarImagen("data/imagenes/Tiles_bloques.png");
SDL_Surface *fondoRejilla=cargarImagen("data/imagenes/Rejilla.png");
SDL_Rect posRejillaNivel, posRejillaSiguiente, posPantalla, posPuntos, posNivel,posPieza,posRegMus, posCan, posFilas, posNombreJuego;


Uint32 timedespues, timeantes=SDL_GetTicks();

SDL_Event evento;

TTF_Font *fuenteSelect = abrirFuente("data/fuentes/Starjedi.ttf", 52), *fuenteOver = abrirFuente("data/fuentes/Starjhol.ttf", 40);
int i, opt=0;
bool salir=0;
Musica chunkMenu(0);

//Activamos el modo repeticion de teclas para cauando se mantenga una tecla nos movamos por las opciones de forma constante
if (SDL_EnableKeyRepeat(500, 200)==-1)
    cout << "Activacion modo repeticion teclas [ ERROR ]" << endl;
else
    cout << "Activacion modo repeticion teclas [ OK ]" << endl;

//Carga de sonidos
chunkMenu.cargarSonMus("data/sonido/SonidoMenu.wav");

//Transparentamos las imagenes de fondo (el trascurso del juego)
transparentar(fondoRejilla, 150);
transparentar(fondonegro, 125);

//Posicion de textos
for (i=0; i< 2; i++)
{
    rectAr[i].x = 150;
    rectAr[i].y = (i*100)+200;
}

//Posiciones

posRejillaNivel.x = 587;posRejillaNivel.y = 116;
posRejillaSiguiente.x = 387;posRejillaSiguiente.y = 116;
posRegMus.x = 387;posRegMus.y = 346;
posPuntos.x = 609;posPuntos.y = 167;
posNivel.x = 619;posNivel.y = 136;
posPieza.x = 414;posPieza.y = 152;
posFilas.x =609;  posFilas.y=203;
posCan.x = 424;posCan.y = 391;
posNombreJuego.x=250; posNombreJuego.y=0;


//Carga de textos
opAr[0]=cargarTexto(titulos[0],fuenteSelect, 118,0,0);

for (i=1; i<2; i++)
    opAr[i]=cargarTexto(titulos[i],fuenteOver,  255,255,255);

//Menu loop
while (!salir)
{
        timedespues = SDL_GetTicks();
        if ((timedespues-timeantes) >= (1000/60))
        {
                timeantes=timedespues;
                blittingImagen(nivel->getFondo(),NULL, pantalla, rectFondo);
                blittingImagen(fondoRejilla,NULL, pantalla, rectplaca);
                blittingImagen(rejillaPuntos,NULL, pantalla, posRejillaNivel);
                blittingImagen(rejillaSiguiente,NULL, pantalla, posRejillaSiguiente);
                blittingImagen(imagenPieza,&posPrevPieza[piezaMomento-1],pantalla, posPieza);
                blittingImagen(imagenPuntos, NULL, pantalla, posPuntos);
                blittingImagen(imagenNivel, NULL, pantalla, posNivel);
                blittingImagen(imagenPuntos, NULL, pantalla, posPuntos);
                blittingImagen(rejillaMusica, NULL, pantalla, posRegMus);
                blittingImagen(imagFilas, NULL, pantalla, posFilas);
                blittingImagen(imagCancion, NULL, pantalla, posCan);
                blittingImagen(nombreJuego, NULL, pantalla, posNombreJuego);
                dibujarMatriz(*rejilla, bloques,pantalla, rectRejilla);
                blittingImagen(fondonegro,NULL, pantalla, rectFondo);


                for (i=0; i<2;i++)
                    blittingImagen(opAr[i],NULL, pantalla, rectAr[i]);
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
                    case    SDLK_UP:    {
                                            chunkMenu.reproducirSonMus(0);
                                            if (opt==0)
                                            {
                                                SDL_FreeSurface(opAr[opt]);
                                                SDL_FreeSurface(opAr[1]);
                                                opAr[opt]=cargarTexto(titulos[opt],fuenteOver,  255,255,255);
                                                opAr[1]=cargarTexto(titulos[1],fuenteSelect,  118,0,0);//25,67,225);
                                                opt=1;
                                            }
                                            else
                                            {
                                                SDL_FreeSurface(opAr[opt]);
                                                SDL_FreeSurface(opAr[opt-1]);
                                                opAr[opt]=cargarTexto(titulos[opt],fuenteOver,  255,255,255);
                                                opAr[opt-1]=cargarTexto(titulos[opt-1],fuenteSelect,  118,0,0);//25,67,225);
                                                opt--;
                                            }
                                            break;
                                        }
                    case   SDLK_DOWN:   {
                                            chunkMenu.reproducirSonMus(0);
                                            if (opt==1)
                                            {
                                                SDL_FreeSurface(opAr[opt]);
                                                SDL_FreeSurface(opAr[0]);
                                                opAr[opt]=cargarTexto(titulos[opt],fuenteOver,  255,255,255);
                                                opAr[0]=cargarTexto(titulos[0],fuenteSelect,118,0,0 );// 25,67,225);
                                                opt=0;
                                            }
                                            else
                                            {
                                                SDL_FreeSurface(opAr[opt]);
                                                SDL_FreeSurface(opAr[opt+1]);
                                                opAr[opt]=cargarTexto(titulos[opt],fuenteOver,  255,255,255);
                                                opAr[opt+1]=cargarTexto(titulos[opt+1],fuenteSelect,118,0,0);  //25,67,225);
                                                opt++;
                                            }
                                            break;
                                        }
                    case   SDLK_RETURN: {
                                            salir=1;
                                            switch (opt)
                                            {
                                                case 0:
                                                    {
                                                        //Resume
                                                        cout << "A seguir jugando"<< endl;
                                                        return 1;
                                                        break;
                                                    }
                                                case 1:
                                                    {
                                                        //Salir al menu
                                                        cout << "Al menu principal"<< endl;
                                                        return 2;
                                                        break;
                                                    }
                                            }
                                            break;
                                        }
                    case   SDLK_ESCAPE: {
                                            //Resume
                                            salir=1;
                                            return 1;
                                            break;
                                        }
                }
            }
        }
}


//Cierre de los recursos
cerrarFuente(fuenteOver);
cerrarFuente(fuenteSelect);
for (i=0;i<2;i++)
    SDL_FreeSurface(opAr[i]);
SDL_FreeSurface(bloques);
}



//Menu para cuando se termina el juego
int menuMuerte(int opcion, Matriz *rejilla,SDL_Rect *rectRejilla, SDL_Surface *pantalla, Nivel *nivel, multimap<int, string> *contenedor, SDL_Surface *rejillaPuntos, SDL_Surface *rejillaSiguiente,
                SDL_Surface *imagenPieza, SDL_Surface *imagenPuntos, SDL_Surface *imagenNivel, SDL_Surface *imagFilas, SDL_Surface *rejillaMusica,
                SDL_Surface *imagCancion,SDL_Rect *posPrevPieza, int piezaMomento, SDL_Surface *nombreJuego)
{
//Declaracion de variables
string titulos [2]={"Salir al menu", "High Score"};
SDL_Rect rectAr[2], rectFondo={0,0}, rectplaca={46,117}, rectTitulo={46, 117};
SDL_Surface *opAr[2];
SDL_Surface *fondonegro=cargarImagen("data/imagenes/fondonegro.png"), *bloques=cargarImagen("data/imagenes/Tiles_bloques.png");
SDL_Surface *fondoRejilla=cargarImagen("data/imagenes/Rejilla.png");
SDL_Surface *titulo;
SDL_Rect posRejillaNivel, posRejillaSiguiente, posPantalla, posPuntos, posNivel,posPieza,posRegMus, posCan, posFilas, posNombreJuego;

bool salir = 0;
Uint32 timedespues, timeantes=SDL_GetTicks();
SDL_Event evento;

TTF_Font *fuenteSelect = abrirFuente("data/fuentes/Starjedi.ttf", 52), *fuenteOver = abrirFuente("data/fuentes/Starjhol.ttf", 40);
TTF_Font *fuenteTitulo = abrirFuente("data/fuentes/gow.ttf", 52);

int i, opt=0;

Musica chunkMenu(0);



//Activamos el modo repeticion de teclas para cauando se mantenga una tecla nos movamos por las opciones de forma constante
if (SDL_EnableKeyRepeat(500, 200)==-1)
    cout << "Activacion modo repeticion teclas [ ERROR ]" << endl;
else
    cout << "Activacion modo repeticion teclas [ OK ]" << endl;

//Carga de musica y chunks
chunkMenu.cargarSonMus("data/sonido/SonidoMenu.wav");



//Transparentamos las imagenes de fondo (el trascurso del juego)
transparentar(fondoRejilla, 150);
transparentar(fondonegro, 125);

//Posicion de los textos
for (i=0; i< 2; i++)
{
    rectAr[i].x = 150;
    rectAr[i].y = (i*100)+200;
}

//Posiciones

posRejillaNivel.x = 587;posRejillaNivel.y = 116;
posRejillaSiguiente.x = 387;posRejillaSiguiente.y = 116;
posRegMus.x = 387;posRegMus.y = 346;
posPuntos.x = 609;posPuntos.y = 167;
posNivel.x = 619;posNivel.y = 136;
posPieza.x = 414;posPieza.y = 152;
posFilas.x =609;  posFilas.y=203;
posCan.x = 424;posCan.y = 391;
posNombreJuego.x=250; posNombreJuego.y=0;

//Carga de textos
titulo=cargarTexto("NO RECORD",fuenteTitulo,  0,0,0);
opAr[0]=cargarTexto(titulos[0],fuenteSelect, 118,0,0);

for (i=1; i<2; i++)
    opAr[i]=cargarTexto(titulos[i],fuenteOver,  255,255,255);

//Menu loop
while (!salir)
{
        timedespues = SDL_GetTicks();

        if ((timedespues-timeantes) >= (1000/60))
        {
                timeantes=timedespues;
                blittingImagen(nivel->getFondo(),NULL, pantalla, rectFondo);
                blittingImagen(fondoRejilla,NULL, pantalla, rectplaca);
                blittingImagen(rejillaPuntos,NULL, pantalla, posRejillaNivel);
                blittingImagen(rejillaSiguiente,NULL, pantalla, posRejillaSiguiente);
                blittingImagen(imagenPieza,&posPrevPieza[piezaMomento-1],pantalla, posPieza);
                blittingImagen(imagenPuntos, NULL, pantalla, posPuntos);
                blittingImagen(imagenNivel, NULL, pantalla, posNivel);
                blittingImagen(imagenPuntos, NULL, pantalla, posPuntos);
                blittingImagen(rejillaMusica, NULL, pantalla, posRegMus);
                blittingImagen(imagFilas, NULL, pantalla, posFilas);
                blittingImagen(imagCancion, NULL, pantalla, posCan);
                blittingImagen(nombreJuego, NULL, pantalla, posNombreJuego);
                dibujarMatriz(*rejilla, bloques,pantalla, rectRejilla);
                blittingImagen(fondonegro,NULL, pantalla, rectFondo);
                blittingImagen(titulo, NULL, pantalla, rectTitulo);
                for (i=0; i<2;i++)
                    blittingImagen(opAr[i],NULL, pantalla, rectAr[i]);
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
                    case    SDLK_UP:    {
                                            chunkMenu.reproducirSonMus(0);
                                            if (opt==0)
                                            {
                                                SDL_FreeSurface(opAr[opt]);
                                                SDL_FreeSurface(opAr[1]);
                                                opAr[opt]=cargarTexto(titulos[opt],fuenteOver,  255,255,255);
                                                opAr[1]=cargarTexto(titulos[1],fuenteSelect,  118,0,0);//25,67,225);
                                                opt=1;
                                            }
                                            else
                                            {
                                                SDL_FreeSurface(opAr[opt]);
                                                SDL_FreeSurface(opAr[opt-1]);
                                                opAr[opt]=cargarTexto(titulos[opt],fuenteOver,  255,255,255);
                                                opAr[opt-1]=cargarTexto(titulos[opt-1],fuenteSelect,  118,0,0);//25,67,225);
                                                opt--;
                                            }
                                            break;
                                        }
                    case   SDLK_DOWN:   {
                                            chunkMenu.reproducirSonMus(0);
                                            if (opt==1)
                                            {
                                                SDL_FreeSurface(opAr[opt]);
                                                SDL_FreeSurface(opAr[0]);
                                                opAr[opt]=cargarTexto(titulos[opt],fuenteOver,  255,255,255);
                                                opAr[0]=cargarTexto(titulos[0],fuenteSelect,118,0,0 );// 25,67,225);
                                                opt=0;
                                            }
                                            else
                                            {
                                                SDL_FreeSurface(opAr[opt]);
                                                SDL_FreeSurface(opAr[opt+1]);
                                                opAr[opt]=cargarTexto(titulos[opt],fuenteOver,  255,255,255);
                                                opAr[opt+1]=cargarTexto(titulos[opt+1],fuenteSelect,118,0,0);  //25,67,225);
                                                opt++;
                                            }
                                            break;
                                        }
                    case   SDLK_RETURN: {
                                            salir=1;
                                            switch (opt)
                                            {

                                                case 0:
                                                    {
                                                        //Salir al menu
                                                        cout << "Al menu principal"<< endl;
                                                        return 1;
                                                        break;
                                                    }
                                                case 1:
                                                    {
                                                        //Ver high score
                                                        if (opcion==0)
                                                            dibujarHighScore(0, contenedor, pantalla);
                                                        else
                                                            dibujarHighScore(1, contenedor, pantalla);
                                                        break;
                                                    }
                                            }
                                            break;
                                        }

                }
            }
        }
}


//Cerrar los recursos
cerrarFuente(fuenteOver);
cerrarFuente(fuenteSelect);
for (i=0;i<2;i++)
    SDL_FreeSurface(opAr[i]);
SDL_FreeSurface(bloques);

}
