#ifndef TABLERO_H
#define TABLERO_H
#include "archivos.h"

class tablero{
private:
    int puntacion[2]= {0,0};
    char** matriz= new char*[8];
public:
    tablero();
    void ActualizarTablero();
    bool EstadoTablero();
    void imprimirTablero();
    int ContarFichas();
    ~tablero();
};

#endif // TABLERO_H
