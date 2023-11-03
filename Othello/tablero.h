#ifndef TABLERO_H
#define TABLERO_H
#include "archivos.h"

class tablero{
private:
    int puntacion[2]= {0,0};
    char** matriz= new char*[8];
    bool direccionCambio[8];
public:
    tablero();
    void ActualizarTablero(int fila, int columna, char Ficha);
    bool EstadoTablero();
    void imprimirTablero();
    int ContarFichas();
    //char **getMatriz() const;
    bool PosibleMovimiento(char ficha);
    void MovimientoValido(int fila, int columna, char Ficha);
    void Resultado(string n_jugadorX, string n_jugadorO);
    void Movimiento(char ficha, tablero Tablero);
    int GetPuntacion(int indice) const;
    ~tablero();
};

#endif // TABLERO_H
