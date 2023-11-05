#include "jugador.h"

void jugador::setFicha(char nueva_ficha)
{
/* Esta función modica el atributo ficha con el caracter que reciba
 * Parametro: char :: nueva_ficha
 * Retorna: void
*/
    ficha = nueva_ficha;
}

char jugador::getFicha() const
{
/* Esta función retorna el valor del atributo ficha
 * Parametro: void
 * Retorna: char :: ficha
*/
    return ficha;
}

string jugador::getNombre() const
{
/* Esta función retorna el valor del atributo nombre
 * Parametro: void
 * Retorna: char :: ficha
*/
    return nombre;
}

jugador::jugador()
{
/* El constructor al momento de invocarse le solicita al usuario que le de
 * un valor al atributo nombre
 * Parametro: void
 * Retorna: void
*/
    #define WHITE   "\033[37m"
    cout<<"\tIngrese su nombre: "<<WHITE; cin>> nombre;
}
