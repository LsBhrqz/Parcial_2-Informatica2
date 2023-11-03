#include "jugador.h"
#include "tablero.h"

void jugador::setFicha(char nueva_ficha)
{
    ficha = nueva_ficha;
}

char jugador::getFicha() const
{
    return ficha;
}

std::string jugador::getNombre() const
{
    return nombre;
}

jugador::jugador()
{
    cout<<"Ingrese su nombre: "; cin>> nombre;
}

