#ifndef JUGADOR_H
#define JUGADOR_H
#include <archivos.h>


class jugador{
private:
    std::string nombre;
    char ficha;

public:
    jugador();
    void setFicha(char nueva_ficha);
};

#endif // JUGADOR_H
