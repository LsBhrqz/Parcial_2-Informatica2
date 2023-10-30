#ifndef TABLERO_H
#define TABLERO_H


class tablero{
private:
    int puntacion[2]= {0,0};
    char** matriz= new char*[8];
public:
    tablero();
    ActualizarTablero();
    EstadoTablero();

};

#endif // TABLERO_H
