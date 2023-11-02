#include "jugador.h"

void jugador::setFicha(char nuevaficha)
{
    ficha = nueva_ficha;
}

jugador::jugador()
{
    cout<<"Ingrese su nombre: "; cin>> nombre;
}
