#include "tablero.h"

tablero::tablero()
{
    //char* puntero_arreglo = new char[8];

    for(int i=0; i<8; i++){
        matriz[i]= new char[8];
    }
    for(int i=0; i<8; i++){
        for(int j=0; j<0; j++){
            matriz[i][j]= ' ';
        }
    }

    for(int i=0; i<8;i++){
        delete matriz[i];
    }
    delete[] matriz;
}
