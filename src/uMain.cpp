
#include "uMain.h"

void pintarMatrizConsola(Matriz *mi)
{
    for (int i=0; i < 20; i++)
    {
        for (int j=0; j<10; j++)
        {
            cout << mi->getColorMatriz(j,i)<< "  " ;
        }
        cout << endl;
    }
    cout << "\n\n";
}

void iniciarLibrerias(void)
{
    if( SDL_Init(SDL_INIT_VIDEO) == -1 )
    {
        cout << "inicializar SDL_VIDEO [ ERROR ]" << endl;
    }
     if( SDL_Init(SDL_INIT_AUDIO) == -1 )
    {
        cout << "inicializar SDL_AUDIO [ ERROR ]" << endl;
    }
    if( TTF_Init() == -1 )
    {
        cout << "inicializar SDL_TTF [ ERROR ]" << endl;
    }
}

void finalizarLibrerias(void)
{
    TTF_Quit(); cout << "cerrando SDL_TTF [ OK ]" << endl;
    SDL_QuitSubSystem(SDL_INIT_VIDEO);cout << "cerrando SDL_VIDEO [ OK ]" << endl;
    SDL_QuitSubSystem(SDL_INIT_AUDIO);cout << "cerrando SDL_AUDIO [ OK ]" << endl;
}



void gameLoop(void)
{
//Creacion de la pantalla
SDL_Surface *pantalla = NULL;
pantalla = crearPantalla(800,600,24);
nombreVentana("Tetris Revival++ V0.1"); //aplicamos nombre a la ventana
//Declaracion de variables
bool salir=0;
int opt;
multimap <int, string> mapPuntuacionClas, mapPuntuacionExt;
Uint32 timantes, timdespues;
timantes=timantes = SDL_GetTicks();
SDL_Event evento;


//Volcado del fichero al contenedor (map)
leerContenedor(0,&mapPuntuacionClas);
leerContenedor(1,&mapPuntuacionExt);


//Abrir el audio
Mix_OpenAudio(44100,AUDIO_S16, 2, 4096);

while (!salir)
{
    //Switch del menu principal
    switch (menuPrincipal(pantalla, &mapPuntuacionClas, &mapPuntuacionExt))
    {
        case 1:
        //Jugar Classic
        {
            opt=0;
            break;
        }
        case 2:
        //Jugar Extreme
        {
            opt=1;
            break;
        }
        case 3:
        //Salir del programa
        {
            salir=1;
            break;
        }
    }
    if (!salir)
    {
        Matriz matriz(20, 51, 122);
        if (opt==0)
            jugar(opt, &mapPuntuacionClas, &mapPuntuacionExt, pantalla, matriz);
        else
        {
            Matriz matriz(20, 51, 122, 5, 6);
            jugar(opt, &mapPuntuacionClas, &mapPuntuacionExt, pantalla, matriz);
        }
    }
}
//Guardado del map en el fichero
guardarContenedor(0,&mapPuntuacionClas);
guardarContenedor(1,&mapPuntuacionExt);
}


void bajarPieza(Matriz *ma, Pieza *pi)
{
    if (!pi->hayDebajo(ma))
    while (!pi->hayDebajo(ma) && !pi->final())
        { pi->bajarPieza(ma);}
}

string devolverRutaCancion(int nCancion)
{
    string aux;
    switch (nCancion)
    {
        case 1:    {aux="data/sonido/tetris-ska.mp3";break;}
        case 2:    {aux="data/sonido/tetris-hardcrock.mp3";break;}
        case 3:    {aux="data/sonido/tetris-original.mp3";break;}
        case 4:    {aux="data/sonido/tetris-acustica.mp3";break;}
        case 5:    {aux="data/sonido/tetris-gameboy.mp3";break;}
        case 6:    {aux="data/sonido/Apocalyptica-Path.mp3";break;}
        case 7:    {aux="data/sonido/MachineHead-Imperium.mp3";break;}
        case 8:    {aux="data/sonido/Children-HateCrew.mp3";break;}
        case 9:    {aux="data/sonido/IllNiño-This time.mp3";break;}
        case 10:   {aux="data/sonido/koRn-Blind.mp3";break;}
    }
    return aux;

}


//Funcion de el juego, aqui estara el nucleo del Tetris
int jugar(int opcion, multimap<int, string> *contenedor, multimap<int, string> *contenedorExt, SDL_Surface *pantalla, Matriz matriz)
{
//############declaraciones de variables#########################

//de SDL
SDL_Surface *rejillaPiezas,*rejillaPuntos, *rejillaSiguiente, *rejillaMusica, *bloques, *imagenPuntos, *imagenNivel, *imagenPieza, *imagcancion, *auxNivel, *imagFilas, *nombreJuego;
SDL_Rect posFondo, posRejillaPiezas, posRejillaNivel, posRejillaSiguiente, posPantalla, posPuntos, posNivel,posPieza,posRegMus, posCan, posFilas, *posBloques=cargarBloques(), *posPrevPieza=cargarPiezas(), posNombreJuego;
SDL_Event evento;
Uint32 timRefDespues,timRefAntes; //para el refresco de pantalla a 60FPS
Uint32 bajadaAntes, bajadaDespues=SDL_GetTicks(); //para controlar la velocidad de bajada de las piezas
Uint32 refrescoAntes, refrescoDespues=SDL_GetTicks(); //parra controlar el refresco a 60 FPS
TTF_Font *fuenteNumero=abrirFuente("data/fuentes/Transformers.ttf", 20), *fuenteNombre=abrirFuente("data/fuentes/Starjedi.ttf", 13), *fuenteTitulo=abrirFuente("data/fuentes/Transformers.ttf", 40);

//propias de c++
int piezaMomento, piezaSiguiente, puntos=0, k=0, filas=0, difFilas=1, buclePieza, nCancion, poderSubirNivel=0, ganar=0, esprimera=1;
bool salir=0, crearPieza=1, bucleBajada=1, filaComp=0;
string rutaCancion, nombreCancion;

//propias de las clases

Nivel nivelComienzo("data/imagenes/level01.png", 10, 1, 800); //creamos nivel para ir incrementando despues

Musica chunkFila(0);
Musica cancion(1);
Musica chunkNivel(0);


//#####################fin declaracion variables#########################

//Para el reproductor
nCancion=(rand()%9)+1;
rutaCancion=devolverRutaCancion(nCancion);
cancion.cargarSonMus(rutaCancion);
nombreCancion=rutaCancion.erase(0,12);


//cargamos imagenes

rejillaPiezas = cargarImagen("data/imagenes/Rejilla.png");transparentar(rejillaPiezas, 150);
rejillaPuntos = cargarImagen("data/imagenes/reg_pun_niv.png");transparentar(rejillaPuntos, 150);
rejillaSiguiente = cargarImagen("data/imagenes/reg_pieza.png");transparentar(rejillaSiguiente, 150);
rejillaMusica = cargarImagen("data/imagenes/musica.png");transparentar(rejillaMusica, 150);
imagcancion = cargarTexto(nombreCancion,fuenteNombre,0,0,0);
bloques = cargarImagen("data/imagenes/Tiles_bloques.png");
imagenPieza = cargarImagen("data/imagenes/previsualizacion_pieza.png");

nombreJuego=cargarTexto("Tetris Revival ++", fuenteTitulo, 51,51,51);



//posiciones de pantalla

posFondo.x = 0;posFondo.y = 0;
posRejillaPiezas.x = 46; posRejillaPiezas.y = 117;
posRejillaNivel.x = 587;posRejillaNivel.y = 116;
posRejillaSiguiente.x = 387;posRejillaSiguiente.y = 116;
posRegMus.x = 387;posRegMus.y = 346;
posPuntos.x = 609;posPuntos.y = 167;
posNivel.x = 619;posNivel.y = 136;
posPieza.x = 414;posPieza.y = 152;
posFilas.x =609;  posFilas.y=203;
posCan.x = 424;posCan.y = 391;
posNombreJuego.x=250; posNombreJuego.y=0;

posBloques=cargarBloques();


//Activamos el modo repeticion de teclas para cauando se mantenga una tecla la pieza se mueva constante
if (SDL_EnableKeyRepeat( SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL)==-1)
    cout << "Activacion modo repeticion teclas [ ERROR ]" << endl;
else
    cout << "Activacion modo repeticion teclas [ OK ]" << endl;


//generamos 2 numeros al azar para las primeras piezas
srand(time(NULL)); //lo ponemos una vez para que cada vez que se haga un "rand()" no sea el mismo
piezaMomento = (rand()%7)+1;
piezaSiguiente= (rand()%7)+1;


//iniciamos la musica

chunkFila.cargarSonMus("data/sonido/SonidoFila.wav");
chunkNivel.cargarSonMus("data/sonido/SonidoNivel.wav");
cancion.reproducirSonMus(0);
pintarMatrizConsola(&matriz);

//blittings
imagenPuntos=cargarTexto(integerAChar(puntos),fuenteNumero, 250,250,250);
imagenNivel=cargarTexto(integerAChar(nivelComienzo.getnNivel()),fuenteNumero, 250, 250, 250);
imagFilas = cargarTexto(integerAChar(filas), fuenteNumero, 250,250,250);


blittingImagen(rejillaPuntos,NULL, pantalla, posRejillaNivel);
blittingImagen(rejillaSiguiente,NULL, pantalla, posRejillaSiguiente);
blittingImagen(imagenPieza,&posPrevPieza[piezaMomento],pantalla, posPieza);
blittingImagen(imagenNivel, NULL, pantalla, posNivel);
blittingImagen(imagenPuntos, NULL, pantalla, posPuntos);
blittingImagen(imagFilas, NULL, pantalla, posFilas);
blittingImagen(rejillaMusica, NULL, pantalla, posRegMus);
blittingImagen(imagcancion, NULL, pantalla, posCan);
blittingImagen(nombreJuego, NULL, pantalla, posNombreJuego);
dibujarMatriz(matriz, bloques, pantalla, posBloques);
flipEnPantalla(pantalla);


//bucle
while (!salir)
{
   //Comprueba cuando termina una cancion para reproducir la siguiente
    if (Mix_PlayingMusic()==0) //1 si esta reproduciendo y 0 si esta en silencio
    {
        nCancion++;
        if (nCancion==11)
            nCancion=1;
        cancion.liberarRecursosSonMus();
        rutaCancion=devolverRutaCancion(nCancion);
        cancion.cargarSonMus(rutaCancion);
        nombreCancion=rutaCancion.erase(0,12);
        imagcancion=cargarTexto(nombreCancion,fuenteNombre, 0,0,0);
        cancion.reproducirSonMus(0);
    }

    k=19;
    while (k>-1)
    {
        filaComp=matriz.filaCompleta(k, &nivelComienzo, &puntos);
        if (filaComp)
        {
            chunkFila.reproducirSonMus(0);
            filas++;
			poderSubirNivel++; //para cuando haga dos filas seguidas y pase por ejemplo de 4 ha 6 asi pueda entrar ha incrementar nivel ya que no seria multiplo de 5
            matriz.bajarFilas(k);
        }
        else
            k--;
    }

    //comprobamos si tenemos que incrementar nivel

    if ((filas !=0) && (filas % 5 == 0) && (difFilas != filas) || (poderSubirNivel > 4)) //lo de difFilas apra que no siga entrnado en el bucle siempre he incremente nivel
    {
        switch (nivelComienzo.getnNivel())
        {
            case 4:     {auxNivel= cargarImagen("data/imagenes/level02.png");break;}
            case 9:     {auxNivel= cargarImagen("data/imagenes/level03.png");break;}
            case 14:    {auxNivel= cargarImagen("data/imagenes/level04.png");break;}
            case 19:    {auxNivel= cargarImagen("data/imagenes/level05.png");break;}
            case 24:    {auxNivel= cargarImagen("data/imagenes/level06.png");break;}
            case 29:    {auxNivel= cargarImagen("data/imagenes/level07.png");break;}
            case 34:    {auxNivel= cargarImagen("data/imagenes/level08.png");break;}
            case 39:    {auxNivel= cargarImagen("data/imagenes/level09.png");break;}
            case 44:    {auxNivel= cargarImagen("data/imagenes/level10.png");break;}
            case 49:    {auxNivel= cargarImagen("data/imagenes/pasado.png");break;}
            default:    {nivelComienzo.incrementarNivel();auxNivel=NULL; break;}
        }
        if (auxNivel != NULL)
        {
            nivelComienzo.incrementarNivel(auxNivel);
            chunkFila.pararSonMus();
            chunkNivel.reproducirSonMus(0);
        }
        difFilas = filas;
        poderSubirNivel=(poderSubirNivel-5);
    }

    if (opcion==1)
    {
        if (matriz.contarOcupados()<15)
        {
            matriz.rellenarPosiciones(5,6);
        }
    }


    if (nivelComienzo.getnNivel()==50)
    {
        puntos+=30000; //Regalo de 30000 puntos!!!
        cancion.pararSonMus();
        InsercionString recordman;
        ganar=1;
        if (opcion==0)
            recordman.gestionInsertarStringYDibujar(ganar, puntos, contenedor, pantalla);
        else
            recordman.gestionInsertarStringYDibujar(ganar, puntos, contenedorExt, pantalla);
        crearPieza=0;
        salir=1;
    }



    //creamos la pieza
    if (crearPieza)
    {
        Pieza pieza(&matriz, piezaMomento);
        piezaMomento=piezaSiguiente;
        piezaSiguiente = (rand()%7)+1; //creamos la que va a ser la futura pieza
        pintarMatrizConsola(&matriz); //sacamos la matriz por consola para llevar control
        buclePieza=1;
        SDL_FreeSurface(imagenPieza);
        imagenPieza = cargarImagen("data/imagenes/previsualizacion_pieza.png");
        while (buclePieza)
            //////////////////////////////////////////////
        {
            if ((!pieza.hayDebajo(&matriz)) && (!pieza.final()))
            {
                while (SDL_PollEvent (&evento))
                {
                    if (evento.type == SDL_QUIT)
                        exit(0);
                    if (evento.type == SDL_KEYDOWN)
                    {
                        switch (evento.key.keysym.sym)
                        {
                            case SDLK_LEFT:
                            {
                                pieza.izquierdaPieza(&matriz);
                                break;
                            }
                            case SDLK_RIGHT:
                            {
                                pieza.derechaPieza(&matriz);
                                break;
                            }
                            case SDLK_DOWN:
                            {
                                if (!pieza.hayDebajo(&matriz) && !pieza.final())
                                    pieza.bajarPieza(&matriz);
                                break;
                            }
                            case SDLK_SPACE:
                            {
                                bajarPieza(&matriz, &pieza);
                                break;
                            }
                            case SDLK_UP:
                            {
                                pieza.rotarPieza(&matriz);
                                break;
                            }
                            case SDLK_ESCAPE:
                            {
                                //Switch del menu de pausa
                                switch (menuPausa(&matriz, posBloques, pantalla, &nivelComienzo, rejillaPuntos, rejillaSiguiente, imagenPieza, imagenPuntos, imagenNivel, imagFilas, rejillaMusica, imagcancion, posPrevPieza, piezaMomento, nombreJuego))
                                {
                                    case 1:
                                    //Resume
                                    {
                                        break;
                                    }
                                    case 2:
                                    //Salir al menu principal
                                    {
                                        salir=1;
                                        buclePieza=0;
                                        break;
                                    }
                                }
                                break;
                            }
                            //Teclas para Reproductor de Musica
                            case SDLK_o:
                            //Play/Pause
                            {
                                cancion.reanudarSonMus();
                                break;
                            }
                            case SDLK_p:
                            {
                                cancion.pausarSonMus();
                                break;
                            }
                        }
                    }

                }
            }
            else
            {
                buclePieza=0;
                crearPieza=1;
            }

            bajadaDespues = SDL_GetTicks();
            if ((bajadaDespues -bajadaAntes) >= nivelComienzo.getVelocidad())
            {
                bajadaAntes = bajadaDespues;
                pieza.bajarPieza(&matriz);
            }

            refrescoDespues = SDL_GetTicks();
            if ((refrescoDespues -refrescoAntes) >= (1000/60))
            {

                refrescoAntes = refrescoDespues;
                //dibujando el juego
                SDL_FreeSurface(imagenNivel);SDL_FreeSurface(imagenPuntos);

                imagenPuntos=cargarTexto(integerAChar(puntos),fuenteNumero, 255,255,255);
                imagenNivel=cargarTexto(integerAChar(nivelComienzo.getnNivel()),fuenteNumero, 255, 255, 255);
                imagFilas = cargarTexto(integerAChar(filas), fuenteNumero, 250,250,250);
                blittingImagen(nivelComienzo.getFondo(),NULL, pantalla, posFondo);
                blittingImagen(rejillaPiezas,NULL, pantalla, posRejillaPiezas);
                blittingImagen(rejillaPuntos,NULL, pantalla, posRejillaNivel);
                blittingImagen(rejillaSiguiente,NULL, pantalla, posRejillaSiguiente);
                blittingImagen(imagenPieza,&posPrevPieza[(piezaMomento-1)],pantalla, posPieza);
                blittingImagen(imagenNivel, NULL, pantalla, posNivel);
                blittingImagen(imagenPuntos, NULL, pantalla, posPuntos);
                blittingImagen(imagFilas, NULL, pantalla, posFilas);
                blittingImagen(rejillaMusica, NULL, pantalla, posRegMus);
                blittingImagen(imagcancion, NULL, pantalla, posCan);
                blittingImagen(nombreJuego, NULL, pantalla, posNombreJuego);
                dibujarMatriz(matriz, bloques, pantalla, posBloques);
                flipEnPantalla(pantalla);

                SDL_Delay(2); //paramos la SDL 2 ms para que descanse el procesador y atienda otros procesos

                //comprobamos si hemos muerto dentro de los fps para que salga la pieza de muerte
                if (pieza.tocarTecho(&matriz))
                {
                    dibujarMatriz(matriz, bloques, pantalla, posBloques);
                    salir=1;
                    cancion.pararSonMus();
                    Musica cancionRecord(1);
                    cancionRecord.cargarSonMus("data/sonido/CancionRecord.mp3");
                    cancionRecord.reproducirSonMus(0);
                    multimap<int, string>::iterator apuntador;
                    if (opcion==0)
                        apuntador = (contenedor)->begin();
                    else
                        apuntador = (contenedorExt)->begin();
                    if (puntos<=apuntador->first)
                    {
                        cancionRecord.pararSonMus();
                        Musica chunkMuerte(0);
                        chunkMuerte.cargarSonMus("data/sonido/SonidoMuerte.wav");
                        chunkMuerte.reproducirSonMus(0);
                        imagcancion=cargarTexto("Eres un pakete...",fuenteNombre, 0,0,0);
                        //If del menu muerrrte
                        if (opcion==0)
                        {
                            if ((menuMuerte(opcion, &matriz, posBloques, pantalla, &nivelComienzo, contenedor, rejillaPuntos, rejillaSiguiente, imagenPieza, imagenPuntos, imagenNivel, imagFilas, rejillaMusica, imagcancion, posPrevPieza, piezaMomento, nombreJuego))==1)
                                salir=1;
                        }
                        else
                        {
                            if ((menuMuerte(opcion, &matriz, posBloques, pantalla, &nivelComienzo, contenedorExt, rejillaPuntos, rejillaSiguiente, imagenPieza, imagenPuntos, imagenNivel, imagFilas, rejillaMusica, imagcancion, posPrevPieza, piezaMomento, nombreJuego))==1)
                                salir=1;
                        }
                    }
                    else
                    {
                        cancionRecord.reproducirSonMus(0);
                        InsercionString record;
                        if (opcion==0)
                            record.gestionInsertarStringYDibujar(ganar, puntos, contenedor, pantalla);
                        else
                            record.gestionInsertarStringYDibujar(ganar, puntos, contenedorExt, pantalla);
                    }
                }

            }

        }
    }
}
}

