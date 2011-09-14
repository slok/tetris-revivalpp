
#include "cPuntuacion.h"

Puntuacion::Puntuacion(string nom, int pun)
{
    nombre = nom;
    puntos = pun;
}
Puntuacion::~Puntuacion(void)
{
}
int Puntuacion::getPuntos(void)
{
    return puntos;
}
string Puntuacion::getNombre(void)
{
    return nombre;
}
void Puntuacion::setPuntos(int pun)
{
    puntos = pun;
}
void Puntuacion::setNombre(string nom)
{
    nombre = nom;
}
bool Puntuacion::operator<(const Puntuacion &p2) const
{
    return (puntos < p2.puntos);
}
