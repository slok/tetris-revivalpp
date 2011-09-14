
#include "cPieza.h"
#include "iostream"


void Pieza::rotarPieza0(Matriz *vector, int pos)
{
  if (((vectorBloques[0].x > -1) &&(vectorBloques[1].x > 0)) && ((vectorBloques[3].x <10)&&(vectorBloques[1].x <8)))
    switch (pos)
    {
        case 1: {   if ((vector->getColorMatriz(vectorBloques[0].x-1, vectorBloques[0].y+1) == -1) &&
                        (vector->getColorMatriz(vectorBloques[2].x+1, vectorBloques[2].y-1) == -1) &&
                        (vector->getColorMatriz(vectorBloques[3].x+2, vectorBloques[3].y-1) == -1))

                    {
                        //bloque 1
                        vector->setColorMatriz((vectorBloques[0].x)-1,(vectorBloques[0].y)+1,1);
                        vector->setColorMatriz((vectorBloques[0].x),vectorBloques[0].y,-1);
                        vectorBloques[0].x = vectorBloques[0].x-1;
                        vectorBloques[0].y = vectorBloques[0].y+1;
                        //bloque 3
                        vector->setColorMatriz((vectorBloques[2].x)+1,(vectorBloques[2].y)-1,1);
                        vector->setColorMatriz(vectorBloques[2].x,vectorBloques[2].y,-1);
                        vectorBloques[2].x = vectorBloques[2].x+1;
                        vectorBloques[2].y = vectorBloques[2].y-1;
                        //bloque 4
                        vector->setColorMatriz((vectorBloques[3].x)+2,(vectorBloques[3].y)-2,1);
                        vector->setColorMatriz(vectorBloques[3].x,vectorBloques[3].y,-1);
                        vectorBloques[3].x = vectorBloques[3].x+2;
                        vectorBloques[3].y = vectorBloques[3].y-2;
                        posRot = 2;
                    }
                    break;

                }
        case 2: {   if ((vector->getColorMatriz(vectorBloques[2].x-1, vectorBloques[2].y+1) == -1) &&
                        (vector->getColorMatriz(vectorBloques[0].x+1, vectorBloques[0].y-1) == -1) &&
                        (vector->getColorMatriz(vectorBloques[3].x-2, vectorBloques[3].y+2) == -1))

                    {
                         //bloque 1
                        vector->setColorMatriz((vectorBloques[0].x)+1,(vectorBloques[0].y)-1,1);
                        vector->setColorMatriz((vectorBloques[0].x),vectorBloques[0].y,-1);
                        vectorBloques[0].x = vectorBloques[0].x+1;
                        vectorBloques[0].y = vectorBloques[0].y-1;
                        //bloque 3
                        vector->setColorMatriz((vectorBloques[2].x)-1,(vectorBloques[2].y)+1,1);
                        vector->setColorMatriz(vectorBloques[2].x,vectorBloques[2].y,-1);
                        vectorBloques[2].x = vectorBloques[2].x-1;
                        vectorBloques[2].y = vectorBloques[2].y+1;
                        //bloque 4
                        vector->setColorMatriz((vectorBloques[3].x)-2,(vectorBloques[3].y)+2,1);
                        vector->setColorMatriz(vectorBloques[3].x,vectorBloques[3].y,-1);
                        vectorBloques[3].x = vectorBloques[3].x-2;
                        vectorBloques[3].y = vectorBloques[3].y+2;
                        posRot = 1;
                    }
                    break;
                }
        default: break;
    }

}
void Pieza::rotarPieza1(Matriz *vector, int pos)
{
    //no tiene rotacion
}
void Pieza::rotarPieza2(Matriz *vector, int pos)
{
if ((vectorBloques[0].x > 0) && (vectorBloques[2].x < 9))
    switch (pos)
    {
        case 1: {   if((vector->getColorMatriz(vectorBloques[3].x-1, vectorBloques[3].y+1) == -1))
                    {
                        //bloque 4
                        vector->setColorMatriz((vectorBloques[3].x)-1,(vectorBloques[3].y)+1,3);
                        vector->setColorMatriz(vectorBloques[3].x,vectorBloques[3].y,-1);
                        vectorBloques[3].x = vectorBloques[3].x-1;
                        vectorBloques[3].y = vectorBloques[3].y+1;
                        posRot = 2;
                    }
                    break;
                }
        case 2: {   if((vector->getColorMatriz(vectorBloques[0].x+1, vectorBloques[0].y+1) == -1))
                    {
                        //bloque 1
                        vector->setColorMatriz((vectorBloques[0].x)+1,(vectorBloques[0].y)+1,3);
                        vector->setColorMatriz(vectorBloques[0].x,vectorBloques[0].y,-1);
                        vectorBloques[0].x = vectorBloques[0].x+1;
                        vectorBloques[0].y = vectorBloques[0].y+1;
                        posRot = 3;
                    }
                    break;

                }
        case 3: {   if((vector->getColorMatriz(vectorBloques[0].x-1, vectorBloques[0].y-1) == -1))
                    {
                        //bloque 1
                        vector->setColorMatriz((vectorBloques[0].x)-1,(vectorBloques[0].y)-1,3);
                        vector->setColorMatriz(vectorBloques[0].x,vectorBloques[0].y,-1);
                        vectorBloques[0].x = vectorBloques[0].x-1;
                        vectorBloques[0].y = vectorBloques[0].y-1;
                        //bloque 2
                        vector->setColorMatriz((vectorBloques[1].x)+2,(vectorBloques[1].y),3);
                        vector->setColorMatriz(vectorBloques[1].x,vectorBloques[1].y,-1);
                        vectorBloques[1].x = vectorBloques[1].x+2;
                        vectorBloques[1].y = vectorBloques[1].y;
                        posRot = 4;
                    }
                    break;

                }
            case 4: {
                        if((vector->getColorMatriz(vectorBloques[3].x-1, vectorBloques[3].y-1) == -1))
                        {
                            //bloque 2
                            vector->setColorMatriz((vectorBloques[1].x)-2,(vectorBloques[1].y),3);
                            vector->setColorMatriz(vectorBloques[1].x,vectorBloques[1].y,-1);
                            vectorBloques[1].x = vectorBloques[1].x-2;
                            vectorBloques[1].y = vectorBloques[1].y;
                            //bloque 4
                            vector->setColorMatriz((vectorBloques[3].x)+1,(vectorBloques[3].y)-1,3);
                            vector->setColorMatriz(vectorBloques[3].x,vectorBloques[3].y,-1);
                            vectorBloques[3].x = vectorBloques[3].x+1;
                            vectorBloques[3].y = vectorBloques[3].y-1;
                            posRot = 1;
                        }
                        break;
                    }

        default: break;
    }
}
void Pieza::rotarPieza3(Matriz *vector, int pos)
{
    if ((vectorBloques[1].x > 0) && (vectorBloques[1].x < 9))
    switch (pos)
    {
        case 1: {   if ((vector->getColorMatriz(vectorBloques[0].x-1, vectorBloques[0].y+1) == -1) &&
                        (vector->getColorMatriz(vectorBloques[2].x+2, vectorBloques[2].y-1) == -1) &&
                        (vector->getColorMatriz(vectorBloques[3].x+1, vectorBloques[3].y) == -1))

                    {
                        //bloque 1
                        vector->setColorMatriz((vectorBloques[0].x)-1,(vectorBloques[0].y)+1,4);
                        vector->setColorMatriz(vectorBloques[0].x,vectorBloques[0].y,-1);
                        vectorBloques[0].x = vectorBloques[0].x-1;
                        vectorBloques[0].y = vectorBloques[0].y+1;
                        //bloque 3
                        vector->setColorMatriz((vectorBloques[2].x)+2,(vectorBloques[2].y)-1,4);
                        vector->setColorMatriz(vectorBloques[2].x,vectorBloques[2].y,-1);
                        vectorBloques[2].x = vectorBloques[2].x+2;
                        vectorBloques[2].y = vectorBloques[2].y-1;
                        //bloque 4
                        vector->setColorMatriz((vectorBloques[3].x)+1,(vectorBloques[3].y),4);
                        vector->setColorMatriz(vectorBloques[3].x,vectorBloques[3].y,-1);
                        vectorBloques[3].x = vectorBloques[3].x+1;
                        vectorBloques[3].y = vectorBloques[3].y;
                        posRot = 2;
                    }
                    break;
                }

        case 2: {   if ((vector->getColorMatriz(vectorBloques[0].x+1, vectorBloques[0].y-1) == -1) &&
                        (vector->getColorMatriz(vectorBloques[2].x, vectorBloques[2].y-1) == -1) &&
                        (vector->getColorMatriz(vectorBloques[3].x-1, vectorBloques[3].y) == -1))

                    {
                        //bloque 1
                        vector->setColorMatriz((vectorBloques[0].x)+1,(vectorBloques[0].y)-1,4);
                        vector->setColorMatriz(vectorBloques[0].x,vectorBloques[0].y,-1);
                        vectorBloques[0].x = vectorBloques[0].x+1;
                        vectorBloques[0].y = vectorBloques[0].y-1;
                        //bloque 3
                        vector->setColorMatriz((vectorBloques[2].x),(vectorBloques[2].y)-1,4);
                        vector->setColorMatriz(vectorBloques[2].x,vectorBloques[2].y,-1);
                        vectorBloques[2].x = vectorBloques[2].x;
                        vectorBloques[2].y = vectorBloques[2].y-1;
                        //bloque 4
                        vector->setColorMatriz((vectorBloques[3].x)-1,(vectorBloques[3].y),4);
                        vector->setColorMatriz(vectorBloques[3].x,vectorBloques[3].y,-1);
                        vectorBloques[3].x = vectorBloques[3].x-1;
                        vectorBloques[3].y = vectorBloques[3].y;
                        posRot = 3;
                    }
                    break;

                }
        case 3: {   if ((vector->getColorMatriz(vectorBloques[0].x-1, vectorBloques[0].y) == -1) &&
                        (vector->getColorMatriz(vectorBloques[2].x-2, vectorBloques[2].y+1) == -1) &&
                        (vector->getColorMatriz(vectorBloques[3].x+1, vectorBloques[3].y-1) == -1))
                    {
                            //bloque 1
                            vector->setColorMatriz((vectorBloques[0].x)-1,(vectorBloques[0].y),4);
                            vector->setColorMatriz(vectorBloques[0].x,vectorBloques[0].y,-1);
                            vectorBloques[0].x = vectorBloques[0].x-1;
                            vectorBloques[0].y = vectorBloques[0].y;
                            //bloque 3
                            vector->setColorMatriz((vectorBloques[2].x)-2,(vectorBloques[2].y)+1,4);
                            vector->setColorMatriz(vectorBloques[2].x,vectorBloques[2].y,-1);
                            vectorBloques[2].x = vectorBloques[2].x-2;
                            vectorBloques[2].y = vectorBloques[2].y+1;
                            //bloque 4
                            vector->setColorMatriz((vectorBloques[3].x)+1,(vectorBloques[3].y)-1,4);
                            vector->setColorMatriz(vectorBloques[3].x,vectorBloques[3].y,-1);
                            vectorBloques[3].x = vectorBloques[3].x+1;
                            vectorBloques[3].y = vectorBloques[3].y-1;
                            posRot = 4;
                    }
                    break;

                }
        case 4: {if ((vector->getColorMatriz(vectorBloques[0].x+1, vectorBloques[0].y) == -1) &&
                        (vector->getColorMatriz(vectorBloques[2].x, vectorBloques[2].y+1) == -1) &&
                        (vector->getColorMatriz(vectorBloques[3].x-1, vectorBloques[3].y+1) == -1))
                    {
                        //bloque 1
                        vector->setColorMatriz((vectorBloques[0].x)+1,(vectorBloques[0].y),4);
                        vector->setColorMatriz(vectorBloques[0].x,vectorBloques[0].y,-1);
                        vectorBloques[0].x = vectorBloques[0].x+1;
                        vectorBloques[0].y = vectorBloques[0].y;
                        //bloque 3
                        vector->setColorMatriz((vectorBloques[2].x),(vectorBloques[2].y)+1,4);
                        vector->setColorMatriz(vectorBloques[2].x,vectorBloques[2].y,-1);
                        vectorBloques[2].x = vectorBloques[2].x;
                        vectorBloques[2].y = vectorBloques[2].y+1;
                        //bloque 4
                        vector->setColorMatriz((vectorBloques[3].x)-1,(vectorBloques[3].y)+1,4);
                        vector->setColorMatriz(vectorBloques[3].x,vectorBloques[3].y,-1);
                        vectorBloques[3].x = vectorBloques[3].x-1;
                        vectorBloques[3].y = vectorBloques[3].y+1;
                        posRot = 1;
                    }
                    break;

                }
        default: break;
    }

}
void Pieza::rotarPieza4(Matriz *vector, int pos)
{
   if ((vectorBloques[1].x > 0)&& (vectorBloques[1].x < 9))
    switch (pos)
    {
        case 1: {   if ((vector->getColorMatriz(vectorBloques[0].x+1, vectorBloques[0].y) == -1) &&
                        (vector->getColorMatriz(vectorBloques[2].x-1, vectorBloques[2].y-1) == -1) &&
                        (vector->getColorMatriz(vectorBloques[3].x, vectorBloques[3].y-1) == -1))
                    {
                         //bloque 1
                        vector->setColorMatriz((vectorBloques[0].x)+1,(vectorBloques[0].y),5);
                        vector->setColorMatriz(vectorBloques[0].x,vectorBloques[0].y,-1);
                        vectorBloques[0].x = vectorBloques[0].x+1;
                        vectorBloques[0].y = vectorBloques[0].y;
                        //bloque 3
                        vector->setColorMatriz((vectorBloques[2].x)-1,(vectorBloques[2].y)-1,5);
                        vector->setColorMatriz(vectorBloques[2].x,vectorBloques[2].y,-1);
                        vectorBloques[2].x = vectorBloques[2].x-1;
                        vectorBloques[2].y = vectorBloques[2].y-1;
                        //bloque 4
                        vector->setColorMatriz((vectorBloques[3].x),(vectorBloques[3].y)-1,5);
                        vector->setColorMatriz(vectorBloques[3].x,vectorBloques[3].y,-1);
                        vectorBloques[3].x = vectorBloques[3].x;
                        vectorBloques[3].y = vectorBloques[3].y-1;
                        posRot = 2;
                    }
                    break;
                }
        case 2: {   if ((vector->getColorMatriz(vectorBloques[0].x-2, vectorBloques[0].y) == -1) &&
                        (vector->getColorMatriz(vectorBloques[2].x+1, vectorBloques[2].y-1) == -1) &&
                        (vector->getColorMatriz(vectorBloques[3].x-1, vectorBloques[3].y+1) == -1))
                    {
                        //bloque 1
                        vector->setColorMatriz((vectorBloques[0].x)-2,(vectorBloques[0].y),5);
                        vector->setColorMatriz(vectorBloques[0].x,vectorBloques[0].y,-1);
                        vectorBloques[0].x = vectorBloques[0].x-2;
                        vectorBloques[0].y = vectorBloques[0].y;
                        //bloque 3
                        vector->setColorMatriz((vectorBloques[2].x)+1,(vectorBloques[2].y)-1,5);
                        vector->setColorMatriz(vectorBloques[2].x,vectorBloques[2].y,-1);
                        vectorBloques[2].x = vectorBloques[2].x+1;
                        vectorBloques[2].y = vectorBloques[2].y-1;
                        //bloque 4
                        vector->setColorMatriz((vectorBloques[3].x)-1,(vectorBloques[3].y)+1,5);
                        vector->setColorMatriz(vectorBloques[3].x,vectorBloques[3].y,-1);
                        vectorBloques[3].x = vectorBloques[3].x-1;
                        vectorBloques[3].y = vectorBloques[3].y+1;
                        posRot = 3;
                    }
                    break;

                }
        case 3: {   if ((vector->getColorMatriz(vectorBloques[0].x, vectorBloques[0].y+1) == -1) &&
                        (vector->getColorMatriz(vectorBloques[2].x+1, vectorBloques[2].y+1) == -1) &&
                        (vector->getColorMatriz(vectorBloques[3].x-1, vectorBloques[3].y) == -1))
                    {
                          //bloque 1
                        vector->setColorMatriz((vectorBloques[0].x),(vectorBloques[0].y)+1,5);
                        vector->setColorMatriz(vectorBloques[0].x,vectorBloques[0].y,-1);
                        vectorBloques[0].x = vectorBloques[0].x;
                        vectorBloques[0].y = vectorBloques[0].y+1;
                        //bloque 3
                        vector->setColorMatriz((vectorBloques[2].x)+1,(vectorBloques[2].y)+1,5);
                        vector->setColorMatriz(vectorBloques[2].x,vectorBloques[2].y,-1);
                        vectorBloques[2].x = vectorBloques[2].x+1;
                        vectorBloques[2].y = vectorBloques[2].y+1;
                        //bloque 4
                        vector->setColorMatriz((vectorBloques[3].x)-1,(vectorBloques[3].y),5);
                        vector->setColorMatriz(vectorBloques[3].x,vectorBloques[3].y,-1);
                        vectorBloques[3].x = vectorBloques[3].x-1;
                        vectorBloques[3].y = vectorBloques[3].y;
                        posRot = 4;
                    }
                    break;

                }
        case 4: {   if ((vector->getColorMatriz(vectorBloques[0].x+1, vectorBloques[0].y-1) == -1) &&
                        (vector->getColorMatriz(vectorBloques[2].x-1, vectorBloques[2].y+1) == -1) &&
                        (vector->getColorMatriz(vectorBloques[3].x+2, vectorBloques[3].y) == -1))
                    {
                            //bloque 1
                            vector->setColorMatriz((vectorBloques[0].x)+1,(vectorBloques[0].y)-1,5);
                            vector->setColorMatriz(vectorBloques[0].x,vectorBloques[0].y,-1);
                            vectorBloques[0].x = vectorBloques[0].x+1;
                            vectorBloques[0].y = vectorBloques[0].y-1;
                            //bloque 3
                            vector->setColorMatriz((vectorBloques[2].x)-1,(vectorBloques[2].y)+1,5);
                            vector->setColorMatriz(vectorBloques[2].x,vectorBloques[2].y,-1);
                            vectorBloques[2].x = vectorBloques[2].x-1;
                            vectorBloques[2].y = vectorBloques[2].y+1;
                            //bloque 4
                            vector->setColorMatriz((vectorBloques[3].x)+2,(vectorBloques[3].y),5);
                            vector->setColorMatriz(vectorBloques[3].x,vectorBloques[3].y,-1);
                            vectorBloques[3].x = vectorBloques[3].x+2;
                            vectorBloques[3].y = vectorBloques[3].y;
                            posRot = 1;
                    }
                    break;
                }
        default: break;


    }

}
void Pieza::rotarPieza5(Matriz *vector, int pos)
{
    if ((vectorBloques[1].x > 0)&& (vectorBloques[3].x < 9))
    switch (pos)
    {
        case 1: {   if ((vector->getColorMatriz(vectorBloques[2].x, vectorBloques[2].y-1) == -1) &&
                        (vector->getColorMatriz(vectorBloques[3].x-2, vectorBloques[3].y-1) == -1))
                    {
                        //bloque 3
                        vector->setColorMatriz((vectorBloques[2].x),(vectorBloques[2].y)-1,6);
                        vector->setColorMatriz(vectorBloques[2].x,vectorBloques[2].y,-1);
                        vectorBloques[2].x = vectorBloques[2].x;
                        vectorBloques[2].y = vectorBloques[2].y-1;
                        //bloque 4
                        vector->setColorMatriz((vectorBloques[3].x)-2,(vectorBloques[3].y)-1,6);
                        vector->setColorMatriz(vectorBloques[3].x,vectorBloques[3].y,-1);
                        vectorBloques[3].x = vectorBloques[3].x-2;
                        vectorBloques[3].y = vectorBloques[3].y-1;
                        posRot = 2;
                    }
                    break;

                }

        case 2: {   if ((vector->getColorMatriz(vectorBloques[2].x, vectorBloques[2].y+1) == -1) &&
                        (vector->getColorMatriz(vectorBloques[3].x+2, vectorBloques[3].y+1) == -1))
                    {
                        //bloque 3
                        vector->setColorMatriz((vectorBloques[2].x),(vectorBloques[2].y)+1,6);
                        vector->setColorMatriz(vectorBloques[2].x,vectorBloques[2].y,-1);
                        vectorBloques[2].x = vectorBloques[2].x;
                        vectorBloques[2].y = vectorBloques[2].y+1;
                        //bloque 4
                        vector->setColorMatriz((vectorBloques[3].x)+2,(vectorBloques[3].y)+1,6);
                        vector->setColorMatriz(vectorBloques[3].x,vectorBloques[3].y,-1);
                        vectorBloques[3].x = vectorBloques[3].x+2;
                        vectorBloques[3].y = vectorBloques[3].y+1;
                        posRot = 1;
                    }
                    break;
                }

    }

}
void Pieza::rotarPieza6(Matriz *vector, int pos)
{
    if ((vectorBloques[3].x > 0)&& (vectorBloques[2].x < 9))
    switch (pos)
    {
        case 1: {   if ((vector->getColorMatriz(vectorBloques[1].x, vectorBloques[1].y-1) == -1) &&
                        (vector->getColorMatriz(vectorBloques[3].x+2, vectorBloques[3].y-1) == -1))
                    {
                           //bloque 2
                            vector->setColorMatriz((vectorBloques[1].x),(vectorBloques[1].y)-1,7);
                            vector->setColorMatriz(vectorBloques[1].x,vectorBloques[1].y,-1);
                            vectorBloques[1].x = vectorBloques[1].x;
                            vectorBloques[1].y = vectorBloques[1].y-1;
                            //bloque 4
                            vector->setColorMatriz((vectorBloques[3].x)+2,(vectorBloques[3].y)-1,7);
                            vector->setColorMatriz(vectorBloques[3].x,vectorBloques[3].y,-1);
                            vectorBloques[3].x = vectorBloques[3].x+2;
                            vectorBloques[3].y = vectorBloques[3].y-1;
                            posRot = 2;
                    }
                    break;
                }
        case 2: {   if ((vector->getColorMatriz(vectorBloques[1].x, vectorBloques[1].y+1) == -1) &&
                        (vector->getColorMatriz(vectorBloques[3].x-2, vectorBloques[3].y+1) == -1))
                    {
                         //bloque 2
                        vector->setColorMatriz((vectorBloques[1].x),(vectorBloques[1].y)+1,7);
                        vector->setColorMatriz(vectorBloques[1].x,vectorBloques[1].y,-1);
                        vectorBloques[1].x = vectorBloques[1].x;
                        vectorBloques[1].y = vectorBloques[1].y+1;
                        //bloque 4
                        vector->setColorMatriz((vectorBloques[3].x)-2,(vectorBloques[3].y)+1,7);
                        vector->setColorMatriz(vectorBloques[3].x,vectorBloques[3].y,-1);
                        vectorBloques[3].x = vectorBloques[3].x-2;
                        vectorBloques[3].y = vectorBloques[3].y+1;
                        posRot = 1;
                    }
                    break;
                }
        default: break;


    }
}
void Pieza::bajarPieza0(Matriz *vector, int pos)
{
   if (vectorBloques[3].y < 19)
    switch (pos)
    {
        case 1: {
                    vector->setColorMatriz((vectorBloques[3].x), (vectorBloques[3].y)+1, 1);
                    (vectorBloques[3].y)++;
                    (vectorBloques[2].y)++;
                    (vectorBloques[1].y)++;
                    (vectorBloques[0].y)++;
                    vector->setColorMatriz((vectorBloques[0].x), (vectorBloques[0].y)-1, -1);
                    break;
                }
        case 2: {
                    for (int i=0; i<4; i++)
                    {
                        vector->setColorMatriz((vectorBloques[i].x), (vectorBloques[i].y)+1, 1);
                        vectorBloques[i].y++;

                    }
                    for(int j=0; j < 4; j++)
                    {
                        vector->setColorMatriz((vectorBloques[j].x), (vectorBloques[j].y)-1, -1);
                    }
                    break;

                }
        default: break;
    }

}
void Pieza::bajarPieza1(Matriz *vector, int pos)
{
    if (vectorBloques[3].y < 19)
    {
        vector->setColorMatriz((vectorBloques[2].x), (vectorBloques[2].y)+1, 2);
        vector->setColorMatriz((vectorBloques[3].x), (vectorBloques[3].y)+1, 2);
        for (int i=0; i<4; i++)
            vectorBloques[i].y++;
        vector->setColorMatriz((vectorBloques[0].x), (vectorBloques[0].y)-1, -1);
        vector->setColorMatriz((vectorBloques[1].x), (vectorBloques[1].y)-1, -1);
    }
}
void Pieza::bajarPieza2(Matriz *vector, int pos)
{
   int i;
    if (vectorBloques[3].y < 19)
    {
        switch (pos)
        {
            case 1: {
                        for ( i=0; i<4; i++)
                        {
                          vector->setColorMatriz((vectorBloques[i].x), (vectorBloques[i].y)+1, 3);
                          vectorBloques[i].y++;
                        }
                        vector->setColorMatriz((vectorBloques[0].x), (vectorBloques[0].y)-1, -1);
                        vector->setColorMatriz((vectorBloques[1].x), (vectorBloques[1].y)-1, -1);
                        vector->setColorMatriz((vectorBloques[3].x), (vectorBloques[3].y)-1, -1);
                        break;
                    }
            case 2: {
                        for ( i=0; i<4; i++)
                        {
                          vector->setColorMatriz((vectorBloques[i].x), (vectorBloques[i].y)+1, 3);
                          vectorBloques[i].y++;
                        }

                        vector->setColorMatriz((vectorBloques[0].x), (vectorBloques[0].y)-1, -1);
                        vector->setColorMatriz((vectorBloques[1].x), (vectorBloques[1].y)-1, -1);
                        break;
                    }
            case 3: {
                        for ( i=0; i<4; i++)
                        {
                          vector->setColorMatriz((vectorBloques[i].x), (vectorBloques[i].y)+1, 3);
                          vectorBloques[i].y++;
                        }
                        vector->setColorMatriz((vectorBloques[0].x), (vectorBloques[0].y)-1, -1);
                        vector->setColorMatriz((vectorBloques[1].x), (vectorBloques[1].y)-1, -1);
                        vector->setColorMatriz((vectorBloques[2].x), (vectorBloques[2].y)-1, -1);
                        break;
                    }
            case 4: {
                        for ( i=0; i<4; i++)
                        {
                          vector->setColorMatriz((vectorBloques[i].x), (vectorBloques[i].y)+1, 3);
                          vectorBloques[i].y++;
                        }

                        vector->setColorMatriz((vectorBloques[0].x), (vectorBloques[0].y)-1, -1);
                        vector->setColorMatriz((vectorBloques[1].x), (vectorBloques[1].y)-1, -1);
                        break;

                    }
        }
    }

}
void Pieza::bajarPieza3(Matriz *vector, int pos)
{
    int i;
    if (vectorBloques[3].y < 19)
    {
        switch (pos)
        {
            case 1: {
                        vector->setColorMatriz((vectorBloques[2].x), (vectorBloques[2].y)+1, 4);
                        vector->setColorMatriz((vectorBloques[3].x), (vectorBloques[3].y)+1, 4);
                        for ( i=0; i<4; i++)
                          vectorBloques[i].y++;
                        vector->setColorMatriz((vectorBloques[0].x), (vectorBloques[0].y)-1, -1);
                        vector->setColorMatriz((vectorBloques[2].x), (vectorBloques[2].y)-1, -1);
                        break;
                    }
            case 2: {
                        for ( i=0; i<4; i++)
                        {
                          vector->setColorMatriz((vectorBloques[i].x), (vectorBloques[i].y)+1, 4);
                          vectorBloques[i].y++;
                        }
                        vector->setColorMatriz((vectorBloques[0].x), (vectorBloques[0].y)-1, -1);
                        vector->setColorMatriz((vectorBloques[1].x), (vectorBloques[1].y)-1, -1);
                        vector->setColorMatriz((vectorBloques[2].x), (vectorBloques[2].y)-1, -1);

                        break;
                    }
            case 3: {   vector->setColorMatriz((vectorBloques[2].x), (vectorBloques[2].y)+1, 4);
                        vector->setColorMatriz((vectorBloques[3].x), (vectorBloques[3].y)+1, 4);
                        for ( i=0; i<4; i++)
                          vectorBloques[i].y++;
                        vector->setColorMatriz((vectorBloques[2].x), (vectorBloques[2].y)-1, -1);
                        vector->setColorMatriz((vectorBloques[0].x), (vectorBloques[0].y)-1, -1);

                        break;
                    }
            case 4: {
                        for ( i=0; i<4; i++)
                        {
                          vector->setColorMatriz((vectorBloques[i].x), (vectorBloques[i].y)+1, 4);
                          vectorBloques[i].y++;
                        }
                        vector->setColorMatriz((vectorBloques[0].x), (vectorBloques[0].y)-1, -1);
                        vector->setColorMatriz((vectorBloques[1].x), (vectorBloques[1].y)-1, -1);
                        vector->setColorMatriz((vectorBloques[3].x), (vectorBloques[3].y)-1, -1);
                        break;
                    }
        }
    }


}
void Pieza::bajarPieza4(Matriz *vector, int pos)
{
    if (vectorBloques[3].y < 19)
    {
        int i;
        switch (pos)
        {
            case 1: {
                        for ( i=0; i<4; i++)
                        {
                            vector->setColorMatriz((vectorBloques[i].x), (vectorBloques[i].y)+1, 5);
                            vectorBloques[i].y++;
                        }
                        vector->setColorMatriz((vectorBloques[0].x), (vectorBloques[0].y)-1, -1);
                        vector->setColorMatriz((vectorBloques[3].x), (vectorBloques[3].y)-1, -1);
                        break;
                    }

            case 2: {
                        for ( i=0; i<4; i++)
                        {
                            vector->setColorMatriz((vectorBloques[i].x), (vectorBloques[i].y)+1, 5);
                            vectorBloques[i].y++;
                        }
                        vector->setColorMatriz((vectorBloques[0].x), (vectorBloques[0].y)-1, -1);
                        vector->setColorMatriz((vectorBloques[1].x), (vectorBloques[1].y)-1, -1);
                        vector->setColorMatriz((vectorBloques[2].x), (vectorBloques[2].y)-1, -1);

                        break;
                    }
            case 3: {
                        vector->setColorMatriz((vectorBloques[0].x), (vectorBloques[0].y)+1, 5);
                        vector->setColorMatriz((vectorBloques[3].x), (vectorBloques[3].y)+1, 5);
                        for ( i=0; i<4; i++)
                            vectorBloques[i].y++;
                        vector->setColorMatriz((vectorBloques[0].x), (vectorBloques[0].y)-1, -1);
                        vector->setColorMatriz((vectorBloques[2].x), (vectorBloques[2].y)-1, -1);

                        break;
                    }
            case 4: {
                        for ( i=0; i<4; i++)
                        {
                            vector->setColorMatriz((vectorBloques[i].x), (vectorBloques[i].y)+1, 5);
                            vectorBloques[i].y++;
                        }
                        vector->setColorMatriz((vectorBloques[0].x), (vectorBloques[0].y)-1, -1);
                        vector->setColorMatriz((vectorBloques[2].x), (vectorBloques[2].y)-1, -1);
                        vector->setColorMatriz((vectorBloques[1].x), (vectorBloques[1].y)-1, -1);

                        break;
                    }
        }
    }

}
void Pieza::bajarPieza5(Matriz *vector, int pos)
{
    int i;
    if (vectorBloques[3].y < 19)
    {
        switch (pos)
        {
            case 1: {
                        vector->setColorMatriz((vectorBloques[1].x), (vectorBloques[1].y)+1, 6);
                        vector->setColorMatriz((vectorBloques[3].x), (vectorBloques[3].y)+1, 6);
                        for ( i=0; i<4; i++)
                            vectorBloques[i].y++;
                        vector->setColorMatriz((vectorBloques[0].x), (vectorBloques[0].y)-1, -1);
                        vector->setColorMatriz((vectorBloques[2].x), (vectorBloques[2].y)-1, -1);
                        break;

                    }
            case 2: {
                        for ( i=0; i<4; i++)
                        {
                            vector->setColorMatriz((vectorBloques[i].x), (vectorBloques[i].y)+1, 6);
                            vectorBloques[i].y++;
                        }
                        vector->setColorMatriz((vectorBloques[0].x), (vectorBloques[0].y)-1, -1);
                        vector->setColorMatriz((vectorBloques[2].x), (vectorBloques[2].y)-1, -1);
                        vector->setColorMatriz((vectorBloques[3].x), (vectorBloques[3].y)-1, -1);
                        break;
                    }
        }
    }
}
void Pieza::bajarPieza6(Matriz *vector, int pos)
{
    int i;
    if (vectorBloques[3].y < 19)
    {
        switch (pos)
        {
            case 1: {
                        vector->setColorMatriz((vectorBloques[2].x), (vectorBloques[2].y)+1, 7);
                        vector->setColorMatriz((vectorBloques[3].x), (vectorBloques[3].y)+1, 7);
                        for ( i=0; i<4; i++)
                            vectorBloques[i].y++;
                        vector->setColorMatriz((vectorBloques[0].x), (vectorBloques[0].y)-1, -1);
                        vector->setColorMatriz((vectorBloques[1].x), (vectorBloques[1].y)-1, -1);
                        break;

                    }

            case 2: {
                        for (i=0; i<4; i++)
                        {
                            vector->setColorMatriz((vectorBloques[i].x), (vectorBloques[i].y)+1, 7);
                            vectorBloques[i].y++;
                        }
                        vector->setColorMatriz((vectorBloques[0].x), (vectorBloques[0].y)-1, -1);
                        vector->setColorMatriz((vectorBloques[1].x), (vectorBloques[1].y)-1, -1);
                        vector->setColorMatriz((vectorBloques[3].x), (vectorBloques[3].y)-1, -1);
                        break;


                    }
        }
    }

}
void Pieza::izquierdaPieza0(Matriz *vector, int pos)
{
    int i;
    if ((vectorBloques[0].x > 0))
    {
        switch (pos)
        {
            case 1: {if ((vector->getColorMatriz(vectorBloques[0].x-1,vectorBloques[0].y) ==-1)
                    && (vector->getColorMatriz(vectorBloques[1].x-1,vectorBloques[1].y) ==-1)
                    && (vector->getColorMatriz(vectorBloques[2].x-1,vectorBloques[2].y) ==-1)
                    && (vector->getColorMatriz(vectorBloques[3].x-1,vectorBloques[3].y) ==-1))
                        {
                            for (i=0; i<4; i++)
                            {
                                vector->setColorMatriz((vectorBloques[i].x)-1, (vectorBloques[i].y), 1);
                                vectorBloques[i].x--;
                            }
                            for (i=0; i<4; i++)
                                vector->setColorMatriz((vectorBloques[i].x)+1, (vectorBloques[i].y), -1);
                         }
                        break;

                    }
            case 2: {
                        if  (vector->getColorMatriz(vectorBloques[0].x-1,vectorBloques[0].y) ==-1)
                         {
                                vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), 1);
                                 for (i=0; i<4; i++)
                                    vectorBloques[i].x--;

                                vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), -1);
                         }
                        break;
                        }
        }
    }

}
void Pieza::izquierdaPieza1(Matriz *vector, int pos)
{
    int i;
    if ((vectorBloques[0].x > 0) &&
       (vector->getColorMatriz(vectorBloques[0].x-1,vectorBloques[0].y) ==-1) &&
       (vector->getColorMatriz(vectorBloques[2].x-1,vectorBloques[2].y) ==-1))
    {
            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), 2);
            vector->setColorMatriz((vectorBloques[2].x)-1, (vectorBloques[2].y), 2);
            for (i=0; i<4; i++)
                vectorBloques[i].x--;
            vector->setColorMatriz((vectorBloques[1].x)+1, (vectorBloques[1].y), -1);
            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), -1);
    }

}
void Pieza::izquierdaPieza2(Matriz *vector, int pos)
{
    int i;
    if ((vectorBloques[1].x > 0) && (vectorBloques[3].x >0))
    {
        switch (pos)
        {
            case 1: {   if ((vector->getColorMatriz(vectorBloques[0].x-1,vectorBloques[0].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[1].x-1,vectorBloques[1].y) ==-1))

                        {    vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), 3);
                            vector->setColorMatriz((vectorBloques[1].x)-1, (vectorBloques[1].y), 3);
                            for (i=0; i<4; i++)
                                vectorBloques[i].x--;
                            vector->setColorMatriz((vectorBloques[0].x)+1, (vectorBloques[0].y), -1);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), -1);
                        }
                        break;
                    }
            case 2: {
                        if ((vector->getColorMatriz(vectorBloques[0].x-1,vectorBloques[0].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[1].x-1,vectorBloques[1].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[3].x-1,vectorBloques[3].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), 3);
                            vector->setColorMatriz((vectorBloques[1].x)-1, (vectorBloques[1].y), 3);
                            vector->setColorMatriz((vectorBloques[3].x)-1, (vectorBloques[3].y), 3);
                            for (i=0; i<4; i++)
                                vectorBloques[i].x--;
                            vector->setColorMatriz((vectorBloques[0].x)+1, (vectorBloques[0].y), -1);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), -1);
                            vector->setColorMatriz((vectorBloques[2].x)+1, (vectorBloques[2].y), -1);
                        }
                        break;
                    }
            case 3: {   if ((vector->getColorMatriz(vectorBloques[3].x-1,vectorBloques[3].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[1].x-1,vectorBloques[1].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[3].x)-1, (vectorBloques[3].y), 3);
                            vector->setColorMatriz((vectorBloques[1].x)-1, (vectorBloques[1].y), 3);
                            for (i=0; i<4; i++)
                                vectorBloques[i].x--;
                            vector->setColorMatriz((vectorBloques[0].x)+1, (vectorBloques[0].y), -1);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), -1);
                        }
                        break;
                    }
            case 4: {   if  ((vector->getColorMatriz(vectorBloques[0].x-1,vectorBloques[0].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[2].x-1,vectorBloques[2].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[3].x-1,vectorBloques[3].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), 3);
                            vector->setColorMatriz((vectorBloques[2].x)-1, (vectorBloques[2].y), 3);
                            vector->setColorMatriz((vectorBloques[3].x)-1, (vectorBloques[3].y), 3);
                            for (i=0; i<4; i++)
                                vectorBloques[i].x--;
                            vector->setColorMatriz((vectorBloques[0].x)+1, (vectorBloques[0].y), -1);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), -1);
                            vector->setColorMatriz((vectorBloques[1].x)+1, (vectorBloques[1].y), -1);
                        }
                        break;
                    }
        }
    }
}
void Pieza::izquierdaPieza3(Matriz *vector, int pos)
{
    int i;
    if ((vectorBloques[2].x > 0) && (vectorBloques[0].x >0))
        switch (pos)
        {
            case 1: {    if ((vector->getColorMatriz(vectorBloques[0].x-1,vectorBloques[0].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[1].x-1,vectorBloques[1].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[2].x-1,vectorBloques[2].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), 4);
                            vector->setColorMatriz((vectorBloques[2].x)-1, (vectorBloques[2].y), 4);
                            vector->setColorMatriz((vectorBloques[1].x)-1, (vectorBloques[1].y), 4);
                            for (i=0; i<4; i++)
                                vectorBloques[i].x--;
                            vector->setColorMatriz((vectorBloques[0].x)+1, (vectorBloques[0].y), -1);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), -1);
                            vector->setColorMatriz((vectorBloques[1].x)+1, (vectorBloques[1].y), -1);
                        }
                        break;
                    }
            case 2: {   if ((vector->getColorMatriz(vectorBloques[0].x-1,vectorBloques[0].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[3].x-1,vectorBloques[3].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), 4);
                            vector->setColorMatriz((vectorBloques[3].x)-1, (vectorBloques[3].y), 4);
                            for (i=0; i<4; i++)
                                vectorBloques[i].x--;
                            vector->setColorMatriz((vectorBloques[2].x)+1, (vectorBloques[2].y), -1);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), -1);
                        }
                        break;
                    }
            case 3: {
                        if ((vector->getColorMatriz(vectorBloques[0].x-1,vectorBloques[0].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[1].x-1,vectorBloques[1].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[3].x-1,vectorBloques[3].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), 4);
                            vector->setColorMatriz((vectorBloques[3].x)-1, (vectorBloques[3].y), 4);
                            vector->setColorMatriz((vectorBloques[1].x)-1, (vectorBloques[1].y), 4);
                            for (i=0; i<4; i++)
                                vectorBloques[i].x--;
                            vector->setColorMatriz((vectorBloques[1].x)+1, (vectorBloques[1].y), -1);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), -1);
                            vector->setColorMatriz((vectorBloques[2].x)+1, (vectorBloques[2].y), -1);
                        }
                        break;
                    }
            case 4: {   if ((vector->getColorMatriz(vectorBloques[0].x-1,vectorBloques[0].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[2].x-1,vectorBloques[2].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), 4);
                            vector->setColorMatriz((vectorBloques[2].x)-1, (vectorBloques[2].y), 4);
                            for (i=0; i<4; i++)
                                vectorBloques[i].x--;
                            vector->setColorMatriz((vectorBloques[0].x)+1, (vectorBloques[0].y), -1);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), -1);
                        }
                        break;
                    }
        }

}
void Pieza::izquierdaPieza4(Matriz *vector, int pos)
{
    int i;
    if ((vectorBloques[2].x > 0) && (vectorBloques[3].x >0))
        switch (pos)
        {
            case 1: {   if ((vector->getColorMatriz(vectorBloques[0].x-1,vectorBloques[0].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[1].x-1,vectorBloques[1].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[2].x-1,vectorBloques[2].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), 5);
                            vector->setColorMatriz((vectorBloques[2].x)-1, (vectorBloques[2].y), 5);
                            vector->setColorMatriz((vectorBloques[1].x)-1, (vectorBloques[1].y), 5);
                            for (i=0; i<4; i++)
                                vectorBloques[i].x--;
                            vector->setColorMatriz((vectorBloques[1].x)+1, (vectorBloques[1].y), -1);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), -1);
                            vector->setColorMatriz((vectorBloques[0].x)+1, (vectorBloques[0].y), -1);
                        }
                        break;

                    }
            case 2: {   if ((vector->getColorMatriz(vectorBloques[0].x-1,vectorBloques[0].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[2].x-1,vectorBloques[2].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), 5);
                            vector->setColorMatriz((vectorBloques[2].x)-1, (vectorBloques[2].y), 5);
                            for (i=0; i<4; i++)
                                vectorBloques[i].x--;
                            vector->setColorMatriz((vectorBloques[0].x)+1, (vectorBloques[0].y), -1);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), -1);
                        }
                        break;

                    }
            case 3: {   if ((vector->getColorMatriz(vectorBloques[0].x-1,vectorBloques[0].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[1].x-1,vectorBloques[1].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[3].x-1,vectorBloques[3].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), 5);
                            vector->setColorMatriz((vectorBloques[3].x)-1, (vectorBloques[3].y), 5);
                            vector->setColorMatriz((vectorBloques[1].x)-1, (vectorBloques[1].y), 5);
                            for (i=0; i<4; i++)
                                vectorBloques[i].x--;
                            vector->setColorMatriz((vectorBloques[1].x)+1, (vectorBloques[1].y), -1);
                            vector->setColorMatriz((vectorBloques[2].x)+1, (vectorBloques[2].y), -1);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), -1);
                        }
                        break;


                    }
            case 4: {   if ((vector->getColorMatriz(vectorBloques[0].x-1,vectorBloques[0].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[3].x-1,vectorBloques[3].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), 5);
                            vector->setColorMatriz((vectorBloques[3].x)-1, (vectorBloques[3].y), 5);
                            for (i=0; i<4; i++)
                                vectorBloques[i].x--;
                            vector->setColorMatriz((vectorBloques[2].x)+1, (vectorBloques[2].y), -1);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), -1);
                        }
                        break;

                    }
        }

}
void Pieza::izquierdaPieza5(Matriz *vector, int pos)
{
    int i;
    if ((vectorBloques[1].x > 0) && (vectorBloques[3].x >0))
        switch (pos)
        {
            case 1: {   if ((vector->getColorMatriz(vectorBloques[0].x-1,vectorBloques[0].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[1].x-1,vectorBloques[1].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[3].x-1,vectorBloques[3].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), 6);
                            vector->setColorMatriz((vectorBloques[1].x)-1, (vectorBloques[1].y), 6);
                            vector->setColorMatriz((vectorBloques[3].x)-1, (vectorBloques[3].y), 6);
                            for (i=0; i<4; i++)
                                vectorBloques[i].x--;
                            vector->setColorMatriz((vectorBloques[0].x)+1, (vectorBloques[0].y), -1);
                            vector->setColorMatriz((vectorBloques[2].x)+1, (vectorBloques[2].y), -1);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), -1);
                        }
                        break;

                    }
            case 2: {   if ((vector->getColorMatriz(vectorBloques[0].x-1,vectorBloques[0].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[3].x-1,vectorBloques[3].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), 6);
                            vector->setColorMatriz((vectorBloques[3].x)-1, (vectorBloques[3].y), 6);
                            for (i=0; i<4; i++)
                                vectorBloques[i].x--;
                            vector->setColorMatriz((vectorBloques[2].x)+1, (vectorBloques[2].y), -1);
                            vector->setColorMatriz((vectorBloques[1].x)+1, (vectorBloques[1].y), -1);
                        }
                        break;

                    }
        }
}
void Pieza::izquierdaPieza6(Matriz *vector, int pos)
{
    int i;
    if (vectorBloques[1].x > 0)
        switch (pos)
        {
            case 1: {   if ((vector->getColorMatriz(vectorBloques[0].x-1,vectorBloques[0].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[1].x-1,vectorBloques[1].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[3].x-1,vectorBloques[3].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), 7);
                            vector->setColorMatriz((vectorBloques[1].x)-1, (vectorBloques[1].y), 7);
                            vector->setColorMatriz((vectorBloques[3].x)-1, (vectorBloques[3].y), 7);
                            for (i=0; i<4; i++)
                                vectorBloques[i].x--;
                            vector->setColorMatriz((vectorBloques[0].x)+1, (vectorBloques[0].y), -1);
                            vector->setColorMatriz((vectorBloques[2].x)+1, (vectorBloques[2].y), -1);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), -1);
                        }
                        break;

                    }
            case 2: {   if ((vector->getColorMatriz(vectorBloques[1].x-1,vectorBloques[1].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[2].x-1,vectorBloques[2].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[1].x)-1, (vectorBloques[1].y), 7);
                            vector->setColorMatriz((vectorBloques[2].x)-1, (vectorBloques[2].y), 7);
                            for (i=0; i<4; i++)
                                vectorBloques[i].x--;
                            vector->setColorMatriz((vectorBloques[0].x)+1, (vectorBloques[0].y), -1);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), -1);
                        }
                        break;

                    }
        }


}

void Pieza::derechaPieza0(Matriz *vector, int pos)
{
   int i;
    if (vectorBloques[3].x < 9)
        switch (pos)
        {
            case 1: {   if ((vector->getColorMatriz(vectorBloques[0].x+1,vectorBloques[0].y) ==-1)
                    && (vector->getColorMatriz(vectorBloques[1].x+1,vectorBloques[1].y) ==-1)
                    && (vector->getColorMatriz(vectorBloques[2].x+1,vectorBloques[2].y) ==-1)
                    && (vector->getColorMatriz(vectorBloques[3].x+1,vectorBloques[3].y) ==-1))
                        {
                            for (i=0; i<4; i++)
                            {
                                vector->setColorMatriz((vectorBloques[i].x)+1, (vectorBloques[i].y), 1);
                                vectorBloques[i].x++;
                            }
                            for (i=0; i<4; i++)
                                vector->setColorMatriz((vectorBloques[i].x)-1, (vectorBloques[i].y), -1);
                        }
                        break;
                    }

            case 2: {   if  (vector->getColorMatriz(vectorBloques[3].x+1,vectorBloques[3].y) ==-1)
                         {
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), 1);
                            for (i=0; i<4; i++)
                                vectorBloques[i].x++;
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), -1);
                         }
                        break;
                    }
        }

}
void Pieza::derechaPieza1(Matriz *vector, int pos)
{
    int i;
    if ((vectorBloques[1].x < 9)&&
        (vector->getColorMatriz(vectorBloques[1].x+1,vectorBloques[1].y) ==-1) &&
       (vector->getColorMatriz(vectorBloques[3].x+1,vectorBloques[3].y) ==-1))
    {
                        vector->setColorMatriz((vectorBloques[1].x)+1, (vectorBloques[1].y), 2);
                        vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), 2);
                        for (i=0; i<4; i++)
                           vectorBloques[i].x++;
                        vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), -1);
                        vector->setColorMatriz((vectorBloques[2].x)-1, (vectorBloques[2].y), -1);
    }


}
void Pieza::derechaPieza2(Matriz *vector, int pos)
{
    int i;
    if ( vectorBloques[0].x < 9 && vectorBloques[1].x < 9 && vectorBloques[3].x < 9)
        switch (pos)
        {
            case 1: {   if ((vector->getColorMatriz(vectorBloques[0].x+1,vectorBloques[0].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[3].x+1,vectorBloques[0].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[0].x)+1, (vectorBloques[0].y), 3);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), 3);
                            for (i=0; i<4; i++)
                               vectorBloques[i].x++;
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), -1);
                            vector->setColorMatriz((vectorBloques[1].x)-1, (vectorBloques[1].y), -1);
                        }
                        break;
                    }
            case 2: {   if ((vector->getColorMatriz(vectorBloques[0].x+1,vectorBloques[0].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[2].x+1,vectorBloques[2].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[3].x+1,vectorBloques[3].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[0].x)+1, (vectorBloques[0].y), 3);
                            vector->setColorMatriz((vectorBloques[2].x)+1, (vectorBloques[2].y), 3);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), 3);
                            for (i=0; i<4; i++)
                               vectorBloques[i].x++;
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), -1);
                            vector->setColorMatriz((vectorBloques[1].x)-1, (vectorBloques[1].y), -1);
                            vector->setColorMatriz((vectorBloques[3].x)-1, (vectorBloques[3].y), -1);
                        }
                        break;
                        }
            case 3: {   if((vector->getColorMatriz(vectorBloques[0].x+1,vectorBloques[0].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[3].x+1,vectorBloques[3].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[0].x)+1, (vectorBloques[0].y), 3);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), 3);
                            for (i=0; i<4; i++)
                               vectorBloques[i].x++;
                            vector->setColorMatriz((vectorBloques[1].x)-1, (vectorBloques[1].y), -1);
                            vector->setColorMatriz((vectorBloques[3].x)-1, (vectorBloques[3].y), -1);
                        }
                        break;
                    }
            case 4: {   if((vector->getColorMatriz(vectorBloques[0].x+1,vectorBloques[0].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[1].x+1,vectorBloques[1].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[3].x+1,vectorBloques[3].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[0].x)+1, (vectorBloques[0].y), 3);
                            vector->setColorMatriz((vectorBloques[1].x)+1, (vectorBloques[1].y), 3);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), 3);
                            for (i=0; i<4; i++)
                               vectorBloques[i].x++;
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), -1);
                            vector->setColorMatriz((vectorBloques[2].x)-1, (vectorBloques[2].y), -1);
                            vector->setColorMatriz((vectorBloques[3].x)-1, (vectorBloques[3].y), -1);
                        }
                        break;

                    }
        }

}
void Pieza::derechaPieza3(Matriz *vector, int pos)
{
    int i;
    if (vectorBloques[2].x < 9 && vectorBloques[3].x < 9)
        switch (pos)
        {
            case 1: {   if((vector->getColorMatriz(vectorBloques[0].x+1,vectorBloques[0].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[1].x+1,vectorBloques[1].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[3].x+1,vectorBloques[3].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[0].x)+1, (vectorBloques[0].y), 4);
                            vector->setColorMatriz((vectorBloques[1].x)+1, (vectorBloques[1].y), 4);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), 4);
                            for (i=0; i<4; i++)
                               vectorBloques[i].x++;
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), -1);
                            vector->setColorMatriz((vectorBloques[1].x)-1, (vectorBloques[1].y), -1);
                            vector->setColorMatriz((vectorBloques[2].x)-1, (vectorBloques[2].y), -1);
                        }
                        break;

                    }
            case 2: {   if((vector->getColorMatriz(vectorBloques[2].x+1,vectorBloques[2].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[3].x+1,vectorBloques[3].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[2].x)+1, (vectorBloques[2].y), 4);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), 4);
                            for (i=0; i<4; i++)
                               vectorBloques[i].x++;
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), -1);
                            vector->setColorMatriz((vectorBloques[3].x)-1, (vectorBloques[3].y), -1);
                        }
                        break;
                    }
            case 3: {   if((vector->getColorMatriz(vectorBloques[2].x+1,vectorBloques[2].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[1].x+1,vectorBloques[1].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[3].x+1,vectorBloques[3].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), 4);
                            vector->setColorMatriz((vectorBloques[1].x)+1, (vectorBloques[1].y), 4);
                            vector->setColorMatriz((vectorBloques[2].x)+1, (vectorBloques[2].y), 4);
                            for (i=0; i<4; i++)
                               vectorBloques[i].x++;
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), -1);
                            vector->setColorMatriz((vectorBloques[1].x)-1, (vectorBloques[1].y), -1);
                            vector->setColorMatriz((vectorBloques[3].x)-1, (vectorBloques[3].y), -1);
                        }
                        break;

                    }
            case 4: {   if((vector->getColorMatriz(vectorBloques[0].x+1,vectorBloques[0].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[3].x+1,vectorBloques[3].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[0].x)+1, (vectorBloques[0].y), 4);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), 4);
                            for (i=0; i<4; i++)
                               vectorBloques[i].x++;
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), -1);
                            vector->setColorMatriz((vectorBloques[2].x)-1, (vectorBloques[2].y), -1);
                        }
                        break;
                    }
        }

}
void Pieza::derechaPieza4(Matriz *vector, int pos)
{
    int i;
    if (vectorBloques[3].x < 9 && vectorBloques[2].x < 9)
        switch (pos)
        {
            case 1: {   if((vector->getColorMatriz(vectorBloques[0].x+1,vectorBloques[0].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[1].x+1,vectorBloques[1].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[3].x+1,vectorBloques[3].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[0].x)+1, (vectorBloques[0].y), 5);
                            vector->setColorMatriz((vectorBloques[1].x)+1, (vectorBloques[1].y), 5);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), 5);
                            for (i=0; i<4; i++)
                               vectorBloques[i].x++;
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), -1);
                            vector->setColorMatriz((vectorBloques[1].x)-1, (vectorBloques[1].y), -1);
                            vector->setColorMatriz((vectorBloques[2].x)-1, (vectorBloques[2].y), -1);
                        }
                        break;

                    }
            case 2: {   if((vector->getColorMatriz(vectorBloques[0].x+1,vectorBloques[0].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[3].x+1,vectorBloques[3].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[0].x)+1, (vectorBloques[0].y), 5);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), 5);
                            for (i=0; i<4; i++)
                               vectorBloques[i].x++;
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), -1);
                            vector->setColorMatriz((vectorBloques[2].x)-1, (vectorBloques[2].y), -1);
                        }
                        break;

                    }
            case 3: {   if((vector->getColorMatriz(vectorBloques[2].x+1,vectorBloques[2].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[1].x+1,vectorBloques[1].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[3].x+1,vectorBloques[3].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[2].x)+1, (vectorBloques[2].y), 5);
                            vector->setColorMatriz((vectorBloques[1].x)+1, (vectorBloques[1].y), 5);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), 5);
                            for (i=0; i<4; i++)
                               vectorBloques[i].x++;
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), -1);
                            vector->setColorMatriz((vectorBloques[1].x)-1, (vectorBloques[1].y), -1);
                            vector->setColorMatriz((vectorBloques[3].x)-1, (vectorBloques[3].y), -1);
                        }
                        break;

                    }
            case 4: {   if((vector->getColorMatriz(vectorBloques[2].x+1,vectorBloques[2].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[3].x+1,vectorBloques[3].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[2].x)+1, (vectorBloques[2].y), 5);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), 5);
                            for (i=0; i<4; i++)
                               vectorBloques[i].x++;
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), -1);
                            vector->setColorMatriz((vectorBloques[3].x)-1, (vectorBloques[3].y), -1);
                        }
                        break;
                    }
        }
}
void Pieza::derechaPieza5(Matriz *vector, int pos)
{
    int i;
    if (vectorBloques[2].x < 9)
        switch (pos)
        {
            case 1: {   if((vector->getColorMatriz(vectorBloques[0].x+1,vectorBloques[0].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[2].x+1,vectorBloques[2].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[3].x+1,vectorBloques[3].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[0].x)+1, (vectorBloques[0].y), 6);
                            vector->setColorMatriz((vectorBloques[2].x)+1, (vectorBloques[2].y), 6);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), 6);
                            for (i=0; i<4; i++)
                               vectorBloques[i].x++;
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), -1);
                            vector->setColorMatriz((vectorBloques[1].x)-1, (vectorBloques[1].y), -1);
                            vector->setColorMatriz((vectorBloques[3].x)-1, (vectorBloques[3].y), -1);
                        }
                        break;
                    }
            case 2: {
                        if((vector->getColorMatriz(vectorBloques[1].x+1,vectorBloques[1].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[2].x+1,vectorBloques[2].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[2].x)+1, (vectorBloques[2].y), 6);
                            vector->setColorMatriz((vectorBloques[1].x)+1, (vectorBloques[1].y), 6);
                            for (i=0; i<4; i++)
                               vectorBloques[i].x++;
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), -1);
                            vector->setColorMatriz((vectorBloques[3].x)-1, (vectorBloques[3].y), -1);
                        }
                        break;
                    }
        }
}
void Pieza::derechaPieza6(Matriz *vector, int pos)
{
       int i;
    if (vectorBloques[3].x < 9 && vectorBloques[2].x < 9)
        switch (pos)
        {
            case 1: {    if((vector->getColorMatriz(vectorBloques[0].x+1,vectorBloques[0].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[2].x+1,vectorBloques[2].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[3].x+1,vectorBloques[3].y) ==-1))
                         {
                            vector->setColorMatriz((vectorBloques[0].x)+1, (vectorBloques[0].y), 7);
                            vector->setColorMatriz((vectorBloques[2].x)+1, (vectorBloques[2].y), 7);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), 7);
                            for (i=0; i<4; i++)
                               vectorBloques[i].x++;
                            vector->setColorMatriz((vectorBloques[0].x)-1, (vectorBloques[0].y), -1);
                            vector->setColorMatriz((vectorBloques[1].x)-1, (vectorBloques[1].y), -1);
                            vector->setColorMatriz((vectorBloques[3].x)-1, (vectorBloques[3].y), -1);
                         }
                        break;
                    }
            case 2: {   if((vector->getColorMatriz(vectorBloques[0].x+1,vectorBloques[0].y) ==-1) &&
                            (vector->getColorMatriz(vectorBloques[3].x+1,vectorBloques[3].y) ==-1))
                        {
                            vector->setColorMatriz((vectorBloques[0].x)+1, (vectorBloques[0].y), 7);
                            vector->setColorMatriz((vectorBloques[3].x)+1, (vectorBloques[3].y), 7);
                            for (i=0; i<4; i++)
                               vectorBloques[i].x++;
                            vector->setColorMatriz((vectorBloques[1].x)-1, (vectorBloques[1].y), -1);
                            vector->setColorMatriz((vectorBloques[2].x)-1, (vectorBloques[2].y), -1);
                        }
                        break;
                    }
        }

}
bool Pieza::hayDebajo0(Matriz *vector, int pos)
{
    bool flag=0;
    switch (pos)
    {
        case 1: {
                    if (vector->getColorMatriz(vectorBloques[3].x,vectorBloques[3].y+1)!=-1)
                        flag = 1;
                    else
                        flag = 0;
                    break;
                }
        case 2: {
                    if ((vector->getColorMatriz(vectorBloques[0].x,vectorBloques[0].y+1)!=-1)  ||
                        (vector->getColorMatriz(vectorBloques[1].x,vectorBloques[1].y+1)!=-1) ||
                        (vector->getColorMatriz(vectorBloques[2].x,vectorBloques[2].y+1)!=-1) ||
                        (vector->getColorMatriz(vectorBloques[3].x,vectorBloques[3].y+1)!=-1) )
                        flag = 1;
                    else
                        flag =0;
                    break;
                }
        default:    break;
    }
    return flag;
}
bool Pieza::hayDebajo1(Matriz *vector, int pos)
{
     bool flag=0;

        if ((vector->getColorMatriz(vectorBloques[3].x,vectorBloques[3].y+1)!=-1) ||
            (vector->getColorMatriz(vectorBloques[2].x,vectorBloques[2].y+1)!=-1))
            flag = 1;
        return flag;

}
bool Pieza::hayDebajo2(Matriz *vector, int pos)
{
     bool flag=0;
    switch (pos)
    {
        case 1: {
                    if ((vector->getColorMatriz(vectorBloques[1].x,vectorBloques[1].y+1)!=-1) ||
                        (vector->getColorMatriz(vectorBloques[2].x,vectorBloques[2].y+1)!=-1) ||
                        (vector->getColorMatriz(vectorBloques[3].x,vectorBloques[3].y+1)!=-1))
                        flag = 1;break;
                }
        case 2: {    if ((vector->getColorMatriz(vectorBloques[3].x,vectorBloques[3].y+1)!=-1) ||
                         (vector->getColorMatriz(vectorBloques[1].x,vectorBloques[1].y+1)!=-1))
                        flag = 1;break;

                }
        case 3: {
                     if ((vector->getColorMatriz(vectorBloques[1].x,vectorBloques[1].y+1)!=-1) ||
                        (vector->getColorMatriz(vectorBloques[0].x,vectorBloques[0].y+1)!=-1) ||
                        (vector->getColorMatriz(vectorBloques[3].x,vectorBloques[3].y+1)!=-1))
                        flag = 1;break;

                }
        case 4: {
                    if ((vector->getColorMatriz(vectorBloques[3].x,vectorBloques[3].y+1)!=-1) ||
                         (vector->getColorMatriz(vectorBloques[1].x,vectorBloques[1].y+1)!=-1))
                        flag = 1;break;
                }

    }return flag;

}
bool Pieza::hayDebajo3(Matriz *vector, int pos)
{
    bool flag=0;
    switch (pos)
    {
        case 1: {
                    if ((vector->getColorMatriz(vectorBloques[3].x,vectorBloques[3].y+1)!=-1) ||
                        (vector->getColorMatriz(vectorBloques[2].x,vectorBloques[2].y+1)!=-1))
                        flag = 1;break;
                }
        case 2: {
                    if ((vector->getColorMatriz(vectorBloques[0].x,vectorBloques[0].y+1)!=-1) ||
                        (vector->getColorMatriz(vectorBloques[1].x,vectorBloques[1].y+1)!=-1) ||
                        (vector->getColorMatriz(vectorBloques[3].x,vectorBloques[3].y+1)!=-1))
                        flag = 1;break;
                }
        case 3: {
                    if ((vector->getColorMatriz(vectorBloques[3].x,vectorBloques[3].y+1)!=-1) ||
                        (vector->getColorMatriz(vectorBloques[2].x,vectorBloques[2].y+1)!=-1))
                        flag = 1;break;
                }
        case 4: {

                    if ((vector->getColorMatriz(vectorBloques[2].x,vectorBloques[2].y+1)!=-1) ||
                        (vector->getColorMatriz(vectorBloques[1].x,vectorBloques[1].y+1)!=-1) ||
                        (vector->getColorMatriz(vectorBloques[3].x,vectorBloques[3].y+1)!=-1))
                        flag = 1;break;
                }
    }return flag;

}
bool Pieza::hayDebajo4(Matriz *vector, int pos)
{
    bool flag=0;
    switch (pos)
    {
        case 1: {
                    if ((vector->getColorMatriz(vectorBloques[3].x,vectorBloques[3].y+1)!=-1) ||
                        (vector->getColorMatriz(vectorBloques[2].x,vectorBloques[2].y+1)!=-1))
                        flag = 1;break;
                }
        case 2: {
                    if ((vector->getColorMatriz(vectorBloques[2].x,vectorBloques[2].y+1)!=-1) ||
                        (vector->getColorMatriz(vectorBloques[1].x,vectorBloques[1].y+1)!=-1) ||
                        (vector->getColorMatriz(vectorBloques[3].x,vectorBloques[3].y+1)!=-1))
                        flag = 1;break;
                }
        case 3: {
                    if ((vector->getColorMatriz(vectorBloques[3].x,vectorBloques[3].y+1)!=-1) ||
                        (vector->getColorMatriz(vectorBloques[0].x,vectorBloques[0].y+1)!=-1))
                        flag = 1;break;
                }
        case 4: {

                    if ((vector->getColorMatriz(vectorBloques[2].x,vectorBloques[2].y+1)!=-1) ||
                        (vector->getColorMatriz(vectorBloques[1].x,vectorBloques[1].y+1)!=-1) ||
                        (vector->getColorMatriz(vectorBloques[3].x,vectorBloques[3].y+1)!=-1))
                        flag = 1;break;
                }
    }return flag;


}
bool Pieza::hayDebajo5(Matriz *vector, int pos)
{
    bool flag=0;
    switch (pos)
    {
        case 1: {
                    if ((vector->getColorMatriz(vectorBloques[1].x,vectorBloques[1].y+1)!=-1) ||
                        (vector->getColorMatriz(vectorBloques[3].x,vectorBloques[3].y+1)!=-1))
                        flag = 1;break;
                }
        case 2: {  if ((vector->getColorMatriz(vectorBloques[2].x,vectorBloques[2].y+1)!=-1) ||
                        (vector->getColorMatriz(vectorBloques[1].x,vectorBloques[1].y+1)!=-1) ||
                        (vector->getColorMatriz(vectorBloques[3].x,vectorBloques[3].y+1)!=-1))
                        flag = 1;break;
                }
    }return flag;
}
bool Pieza::hayDebajo6(Matriz *vector, int pos)
{
    bool flag=0;
    switch (pos)
    {
        case 1: {
                    if ((vector->getColorMatriz(vectorBloques[2].x,vectorBloques[2].y+1)!=-1) ||
                        (vector->getColorMatriz(vectorBloques[3].x,vectorBloques[3].y+1)!=-1))
                        flag = 1;break;
                }
        case 2: {  if ((vector->getColorMatriz(vectorBloques[2].x,vectorBloques[2].y+1)!=-1) ||
                        (vector->getColorMatriz(vectorBloques[1].x,vectorBloques[1].y+1)!=-1) ||
                        (vector->getColorMatriz(vectorBloques[3].x,vectorBloques[3].y+1)!=-1))
                        flag = 1;break;
                }
    }return flag;

}


Pieza::Pieza(Matriz *vector, int color)
{

    switch (color)
    {
        case 1: {
                    vector->setColorMatriz(4,0,1);vectorBloques[0].x = 4;vectorBloques[0].y = 0;
                    vector->setColorMatriz(4,1,1);vectorBloques[1].x = 4;vectorBloques[1].y = 1;
                    vector->setColorMatriz(4,2,1);vectorBloques[2].x = 4;vectorBloques[2].y = 2;
                    vector->setColorMatriz(4,3,1);vectorBloques[3].x = 4;vectorBloques[3].y = 3;
                    posRot = 1;
                    quieta = 0;
                    break;
                }

        case 2: {
                    vector->setColorMatriz(4,0,2);vectorBloques[0].x = 4;vectorBloques[0].y = 0;
                    vector->setColorMatriz(5,0,2);vectorBloques[1].x = 5;vectorBloques[1].y = 0;
                    vector->setColorMatriz(4,1,2);vectorBloques[2].x = 4;vectorBloques[2].y = 1;
                    vector->setColorMatriz(5,1,2);vectorBloques[3].x = 5;vectorBloques[3].y = 1;
                    posRot = 1;
                    quieta = 0;
                    break;
                }
        case 3: {
                    vector->setColorMatriz(4,0,3);vectorBloques[0].x = 4;vectorBloques[0].y = 0;
                    vector->setColorMatriz(3,1,3);vectorBloques[1].x = 3;vectorBloques[1].y = 1;
                    vector->setColorMatriz(4,1,3);vectorBloques[2].x = 4;vectorBloques[2].y = 1;
                    vector->setColorMatriz(5,1,3);vectorBloques[3].x = 5;vectorBloques[3].y = 1;
                    posRot = 1;
                    quieta = 0;
                    break;
                }
        case 4: {
                    vector->setColorMatriz(4,0,4);vectorBloques[0].x = 4;vectorBloques[0].y = 0;
                    vector->setColorMatriz(4,1,4);vectorBloques[1].x = 4;vectorBloques[1].y = 1;
                    vector->setColorMatriz(3,2,4);vectorBloques[2].x = 3;vectorBloques[2].y = 2;
                    vector->setColorMatriz(4,2,4);vectorBloques[3].x = 4;vectorBloques[3].y = 2;
                    posRot = 1;
                    quieta = 0;
                    break;
                }
        case 5: {
                    vector->setColorMatriz(4,0,5);vectorBloques[0].x = 4;vectorBloques[0].y = 0;
                    vector->setColorMatriz(4,1,5);vectorBloques[1].x = 4;vectorBloques[1].y = 1;
                    vector->setColorMatriz(4,2,5);vectorBloques[2].x = 4;vectorBloques[2].y = 2;
                    vector->setColorMatriz(5,2,5);vectorBloques[3].x = 5;vectorBloques[3].y = 2;
                    posRot = 1;
                    quieta = 0;
                    break;
                }
        case 6: {
                    vector->setColorMatriz(4,0,6);vectorBloques[0].x = 4;vectorBloques[0].y = 0;
                    vector->setColorMatriz(4,1,6);vectorBloques[1].x = 4;vectorBloques[1].y = 1;
                    vector->setColorMatriz(5,1,6);vectorBloques[2].x = 5;vectorBloques[2].y = 1;
                    vector->setColorMatriz(5,2,6);vectorBloques[3].x = 5;vectorBloques[3].y = 2;
                    posRot = 1;
                    quieta = 0;
                    break;
                }
        case 7: {
                    vector->setColorMatriz(5,0,7);vectorBloques[0].x = 5;vectorBloques[0].y = 0;
                    vector->setColorMatriz(4,1,7);vectorBloques[1].x = 4;vectorBloques[1].y = 1;
                    vector->setColorMatriz(5,1,7);vectorBloques[2].x = 5;vectorBloques[2].y = 1;
                    vector->setColorMatriz(4,2,7);vectorBloques[3].x = 4;vectorBloques[3].y = 2;
                    posRot = 1;
                    quieta = 0;
                    break;
                }
        default: break;
    }

}
Pieza::~Pieza()
{
}

void Pieza::rotarPieza(Matriz *vector)
{
    int color=-1;
    color = vector->getColorMatriz(vectorBloques[0].x, vectorBloques[0].y);
    switch (color)
    {
        case 1:{rotarPieza0(vector, posRot); break;}
        case 2:break;
        case 3:{rotarPieza2(vector, posRot); break;}
        case 4:{rotarPieza3(vector, posRot); break;}
        case 5:{rotarPieza4(vector, posRot); break;}
        case 6:{rotarPieza5(vector, posRot); break;}
        case 7:{rotarPieza6(vector, posRot); break;}
        default: break;

    }
}
void Pieza::bajarPieza(Matriz *vector)
{
    int color=-1;
    color = vector->getColorMatriz(vectorBloques[0].x, vectorBloques[0].y);
    switch (color)
    {
        case 1: {bajarPieza0(vector, posRot);break;}
        case 2: {bajarPieza1(vector, posRot);break;}
        case 3: {bajarPieza2(vector, posRot);break;}
        case 4: {bajarPieza3(vector, posRot);break;}
        case 5: {bajarPieza4(vector, posRot);break;}
        case 6: {bajarPieza5(vector, posRot);break;}
        case 7: {bajarPieza6(vector, posRot);break;}
    }

}
void Pieza::izquierdaPieza(Matriz *vector)
{
    int color=-1;
    color = vector->getColorMatriz(vectorBloques[0].x, vectorBloques[0].y);
    switch (color)
    {
        case 1: {izquierdaPieza0(vector, posRot);break;}
        case 2: {izquierdaPieza1(vector, posRot);break;}
        case 3: {izquierdaPieza2(vector, posRot);break;}
        case 4: {izquierdaPieza3(vector, posRot);break;}
        case 5: {izquierdaPieza4(vector, posRot);break;}
        case 6: {izquierdaPieza5(vector, posRot);break;}
        case 7: {izquierdaPieza6(vector, posRot);break;}
    }

}
void Pieza::derechaPieza(Matriz *vector)
{
    int color=-1;
    color = vector->getColorMatriz(vectorBloques[0].x, vectorBloques[0].y);
    switch (color)
    {
        case 1: {derechaPieza0(vector, posRot);break;}
        case 2: {derechaPieza1(vector, posRot);break;}
        case 3: {derechaPieza2(vector, posRot);break;}
        case 4: {derechaPieza3(vector, posRot);break;}
        case 5: {derechaPieza4(vector, posRot);break;}
        case 6: {derechaPieza5(vector, posRot);break;}
        case 7: {derechaPieza6(vector, posRot);break;}
    }

}

bool Pieza::hayDebajo(Matriz *vector)
{
    int color=-1;
    bool hay=0;
    color = vector->getColorMatriz(vectorBloques[0].x, vectorBloques[0].y);
    switch (color)
    {
        case 1:{hay = hayDebajo0(vector, posRot);break;}
        case 2:{hay = hayDebajo1(vector, posRot);break;}
        case 3:{hay = hayDebajo2(vector, posRot);break;}
        case 4:{hay = hayDebajo3(vector, posRot);break;}
        case 5:{hay = hayDebajo4(vector, posRot);break;}
        case 6:{hay = hayDebajo5(vector, posRot);break;}
        case 7:{hay = hayDebajo6(vector, posRot);break;}
    }
    return hay;
}
bool Pieza::tocarTecho(Matriz *vector)
{
    if ((this->hayDebajo(vector)) && (vectorBloques[0].y==0))
        return 1;
    else
        return 0;
}
bool Pieza::final(void)
{
   if (vectorBloques[3].y == 19)
        return 1;
    else
        return 0;
}
