#include "tablero.h"
#include "funcionalidad.h"
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
/*
char **tablero::getMatriz() const
{
    return matriz;
}*/

void tablero::imprimirTablero()
{
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

void tablero::MovimientoValido(int x, int y, char ficha)
{
 //Funcion que hay que completar
}

bool tablero::PosibleMovimiento(char ficha)
{
    for(int i=0; i<8; i++){
        for (int j = 0; j < 8; j++) {
            if(matriz[i][j]==' '){
                MovimientoValido(i, j, ficha);
                for(int i=0; i<8; i++){
                    if(direccionCambio[i]==true){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int tablero::GetPuntacion( int indice) const{
    return puntacion[indice];
}

void tablero::ActualizarTablero(int x, int y, char ficha){
    int a,b;
    //izquierda
    a = y - 1;
    while(direccionValida[0]){
        if(matriz[x][a] != ficha){
            matriz[x][a] == ficha;
            a--;
        }
        else{
            direccionValida[0] = false;
        }
    }
    //derecha
    a = y + 1;
    while(direccionValida[2]){
        if(matriz[x][a] != ficha){
            matriz[x][a] == ficha;
            a++;
        }
        else{
            direccionValida[1] = false;
        }
    }
    //arriba
    a = x - 1;
    while(direccionValida[2]){
        if(matriz[a][y] != ficha){
            matriz[a][y] == ficha;
            a--;
        }
        else{
            direccionValida[2] = false;
        }
    }
    //abajo
    a = x + 1;
    while(direccionValida[3]){
        if(matriz[a][y] != ficha){
            matriz[a][y] == ficha;
            a++;
        }
        else{
            direccionValida[3] = false;
        }
    }
    //diagonal superior izquierda
    a = y - 1;
    while(direccionValida[4]){
        if(matriz[a][a] != ficha){
            matriz[a][a] == ficha;
            a--;
        }
        else{
            direccionValida[4] = false;
        }
    }
    //diagonal superior derecha
    a = y + 1;
    b = x - 1;
    while(direccionValida[5]){
        if(matriz[b][a] != ficha){
            matriz[b][a] == ficha;
            b--;
            a++;
        }
        else{
            direccionValida[5] = false;
        }
    }
    //diagonal inferior izquierda
    a = y - 1;
    b = x + 1;
    while(direccionValida[6]){
        if(matriz[b][a] != ficha){
            matriz[b][a] == ficha;
            b++;
            a--;
        }
        else{
            direccionValida[6] = false;
        }
    }
    //diagonal inferior derecha
    b = x + 1;
    while(direccionValida[7]){
        if(matriz[b][b] != ficha){
            matriz[b][b] == ficha;
            b++;
        }
        else{
            direccionValida[7] = false;
        }
    }
}

bool tablero::EstadoTablero(){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(matriz[i][j]== ' '){
                return true;
            }
        }
    }
    return false;
}

void tablero::Movimiento(char ficha, tablero Tablero)
{
    //Funcion que no está implementada y todavía no estoy segura de si la voy a usar
    int fila= RecibirRespuesta("fila");
    int columna= RecibirRespuesta("columna");
    Tablero.MovimientoValido(fila, columna, ficha);
    Tablero.ActualizarTablero(fila, columna, ficha);
}

int tablero::ContarFichas(){
    int contadorX=0;
    int contadorO=0;
    for (int i = 0; i < 8; i++) {
        for(int j=0; j<8; j++){
            if(matriz[i][j]=='x'){
                contadorX+=1;
            }else if(matriz[i][j]=='O'){
                contadorO+=1;
            }
        }
    }
    puntacion[0]= contadorX;
    puntacion[1]= contadorO;
}

void tablero::Resultado(string jugadorX, string jugadorO){

    if(puntacion[0]>puntacion[1]){
        cout<<"Felicidades" << jugadorX<<"! GANASTE!"<<endl;
    }else if(puntacion[0]< puntacion[1]){
        cout<<"Felicidades"<<jugadorO<<"! GANASTE!"<<endl;
    }else{
        cout<<"EMPATE!"<<endl;
    }
    cout<<"Puntacion: "<<endl;
    cout<<"X:" <<puntacion[0]<<endl;
    cout<<"0: "<<puntacion[1]<<endl;
    //Esta funcion llama a contar fichas e imprime quién ganó y la cantidad de fichas
    //que tuvo cada uno
}

tablero::~tablero(){
    for(int i=0; i<8;i++){
        delete matriz[i];
    }
    delete[] matriz;
}

