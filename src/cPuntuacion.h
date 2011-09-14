#ifndef PUNTUACION_H
#define PUNTUACION_H

#include <string>
using namespace std;

class Puntuacion
{
private:

    string nombre;
    int puntos;

public:

    Puntuacion(string nom, int pun);
    ~Puntuacion(void);
    int getPuntos(void) ;
    string getNombre(void);
    void setPuntos(int pun);
    void setNombre(string nom);
    bool operator<(const Puntuacion &p2) const;
};

#endif
