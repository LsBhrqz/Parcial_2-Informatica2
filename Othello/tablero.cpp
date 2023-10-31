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

    matriz[4][4]='O'; matriz[5][5]='O';
    matriz[4][5]= 'X'; matriz[5][4]= 'X';


}

tablero::~tablero(){
    for(int i=0; i<8;i++){
        delete matriz[i];
    }
    delete[] matriz;
}
