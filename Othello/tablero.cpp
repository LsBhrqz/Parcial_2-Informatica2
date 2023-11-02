#include "tablero.h"
#include <iostream>
tablero::tablero()
{
    //char* puntero_arreglo = new char[8];

    for(int i=0; i<8; i++){
        matriz[i]= new char[8];
    }
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            matriz[i][j]= '1';
        }
    }

    matriz[3][3]='O'; matriz[4][4]='O';
    matriz[3][4]= 'X'; matriz[4][3]= 'X';

}



void tablero::imprimirTablero(){
    string margen = "| ";
    string margen2 = " ---";

    for(int l=0; l<8; l++){
        cout << "  " << l + 1 << " ";}

    cout << endl;

    for(int i=0; i<8; i++){

        for(int l=0; l<8; l++){
            cout << margen2;}
        cout << endl;
        for(int j=0; j<8; j++){
            cout << margen << matriz[i][j] << " ";
        }
        cout << margen << i + 1 << endl;
    }

    for(int l=0; l<8; l++){
        cout << margen2;
    }
    cout << endl;
}

tablero::~tablero(){
    for(int i=0; i<8;i++){
        delete matriz[i];
    }
    delete[] matriz;
}

