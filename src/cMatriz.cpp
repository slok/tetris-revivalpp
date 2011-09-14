
#include "cMatriz.h"
#include "time.h"

Matriz::Matriz(int pixel, int espacioX, int espacioY)
{
    SDL_Rect pos;

    for (int i=0; i<20; i++)
    {
        for (int j=0; j<10; j++)
        {
            pos.x =(espacioX+(pixel*j));
            pos.y =(espacioY+(pixel*i));
            pos.h = pixel;
            pos.w = pixel;
            rejilla[j][i].setColor(-1);
            rejilla[j][i].setPosicion(pos);
            rejilla[j][i].setX(i);
            rejilla[j][i].setY(j);
        }
    }
}
Matriz::Matriz(int pixel, int espacioX, int espacioY, int obstaculosFila, int nivel)
{
    srand(time(NULL));
    SDL_Rect pos;
    int num=0,k=0, color;

    for (int i=0; i<20; i++)
    {
        for (int j=0; j<10; j++)
        {
            pos.x =(espacioX+(pixel*j));
            pos.y =(espacioY+(pixel*i));
            pos.h = pixel;
            pos.w = pixel;
            rejilla[j][i].setColor(-1);
            rejilla[j][i].setPosicion(pos);
            rejilla[j][i].setX(i);
            rejilla[j][i].setY(j);
        }
    }
    this->rellenarPosiciones(obstaculosFila, nivel);
}
Matriz::~Matriz()
{

}
bool Matriz::filaCompleta(int numFila, Nivel *niv, int *puntos)
{
    bool todas=1;
    int i=0;

    while ((i<10) && (todas==1))
    {
        if (rejilla[i][numFila].getColor() == -1)
            todas=0;
        i++;
    }
    if (todas)
    {
        *puntos += niv->getPuntuacion();
    }
   return todas;

}
void Matriz::bajarFilas(int fila) //error al hacer fila cuando no es la de la fila 19
{
   int  todas =0, fila2=0;
    while (todas < 10)
    {
        todas =0;
        for (int i =0; i < 10; i++)
        {
            if (rejilla[i][fila-1].getColor() == -1)
                todas++;

            rejilla[i][fila].setColor(rejilla[i][fila-1].getColor());
        }
        fila2 =fila;
        fila--;
    }
    for (int j =0; j < 10; j++)
    {
        rejilla[j][fila2].setColor(-1);
    }

}
int Matriz::getColorMatriz(int x, int y)
{
    return ((rejilla[x][y].getColor()));
}
int Matriz::getXMatriz(int x, int y)
{
    return ((rejilla[x][y].getX()));
}
int Matriz::getYMatriz(int x, int y)
{
    return ((rejilla[x][y].getY()));
}
int Matriz::getNumeroMatriz(int x, int y)
{
    return ((rejilla[x][y].getNum()));
}
SDL_Rect Matriz::getPosMatriz(int x, int y)
{
    return ((rejilla[x][y].getPosicion()));
}
void Matriz::setColorMatriz(int x, int y, int color)
{
    rejilla[x][y].setColor(color);
}
void Matriz::setNumeroMatriz(int x, int y,int numero)
{
    rejilla[x][y].setNum(numero);
}

int Matriz::contarOcupados(void)
{
    int aux=0;
    for (int i=0; i<20; i++)
    {
        for (int j=0; j<10; j++)
        {
            if (rejilla[j][i].getColor() != -1)
                aux++;
        }
    }
    return aux;
}

void Matriz::rellenarPosiciones(int obstaculosFila,int nivel)
{
    int l=0, num=0, color=0;
    obstaculosFila = (obstaculosFila>5)?5:obstaculosFila;  //si hay mas de 5 obstaculos se pone a 5
    if (nivel > 0)
        for (int k=0; k< nivel; k++)
        {
            for (int i=0;i<10;i++)
            {
                if (rejilla[i][(19-k)].getColor() != -1)
                    l++;
            }
            while (l<obstaculosFila)
            {
                num = (rand()%10);
                if (rejilla[num][(19-k)].getColor() == -1)
                {
                    color = (rand()%7)+1;
                    rejilla[num][(19-k)].setColor(color);
                    l++;
                }
            }
            l=0;
        }
}

