#ifndef JUGADOR_H
#define JUGADOR_H
#include <archivos.h>


class jugador{
private:
    string nombre;
    char ficha;

public:
    jugador();
    void setFicha(char nueva_ficha);
    char getFicha() const;

    string getNombre() const;
    void setNombre(const string &newNombre);
};

#endif // JUGADOR_H
