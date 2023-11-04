#ifndef TABLERO_H
#define TABLERO_H
#include "archivos.h"

class tablero{
private:
    int puntacion[2]= {0,0};
    char matriz[8][8];
    //char** matriz= new char*[8];
    bool direccionValida[8];
public:
    tablero();
    void ActualizarTablero(int fila, int columna, char Ficha);
    bool EstadoTablero();
    void imprimirTablero();
    void ContarFichas();
    bool CasillaVacia(int i, int j);
    //char **getMatriz() const;
    bool PosibleMovimiento(char ficha);
    bool MovimientoValido(int fila, int columna, char Ficha);
    void Resultado(string n_jugadorX, string n_jugadorO);
    bool Movimiento(char ficha);
    int GetPuntacion(int indice) const;
    void actualizarDirecciones();

    ~tablero();
};

#endif // TABLERO_H
