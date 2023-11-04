#include "funcionalidad.h"


tablero::tablero()
{
    //char* puntero_arreglo = new char[8];

    /*for(int i=0; i<8; i++){
        matriz[i]= new char[8];
    }
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            matriz[i][j]= ' ';
        }
    }*/
    for(int i=0; i<8;i++){
        for(int j=0; j<8; j++){
            matriz[i][j]= ' ';
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


    cout<<"X's: "<<puntacion[0]<<endl;
    cout<<"O's: "<<puntacion[1]<<endl;

    for(int l=0; l<8; l++){
        cout << "  " << l +1  << " ";}

    cout << endl;

    for(int i=0; i<8; i++){

        for(int l=0; l<8; l++){
            cout << margen2;}
        cout << endl;
        for(int j=0; j<8; j++){
            cout << margen << matriz[i][j] << " ";
        }
        cout << margen << i +1 << endl;
    }

    for(int l=0; l<8; l++){
        cout << margen2;
    }
    cout << endl;
}

bool tablero::MovimientoValido(int x, int y, char ficha)
{
    actualizarDirecciones();

    if(y > 1){
        //izquierda
        if(matriz[x][y - 1] != ' ' && matriz[x][y - 1] != ficha){
            for(int a = y - 2; a >= 0 ; a--){
                if(matriz[x][a] == ' '){
                    break;
                }
                else if(matriz[x][a] == ficha){
                    direccionValida[0] = true;
                    break;
                }
            }
        }
    }

    if(y < 6){
        //derecha
        if(matriz[x][y + 1] != ' ' && matriz[x][y + 1] != ficha){
            for(int a = y + 2; a < 8 ; a++){
                if(matriz[x][a] == ' '){
                    break;
                }
                else if(matriz[x][a] == ficha){
                    direccionValida[1] = true;
                    break;
                }
            }
        }
    }

    if((y > 1) && (x > 1)){
        //diagonal superior izquierda
        if(matriz[x - 1][y - 1] != ' ' && matriz[x - 1][y - 1] != ficha){
            int b = x - 2;
            for(int a = y - 2; a >= 0 ; a--){
                if(matriz[b][a] == ' '){
                    break;
                }
                else if(matriz[b][a] == ficha){
                    direccionValida[4] = true;
                    break;
                }
                b--;
            }
        }
    }

    if(x > 1){
        //arriba
        if(matriz[x - 1][y] != ' ' && matriz[x - 1][y] != ficha){
            for(int a = x - 2; a >= 0 ; a--){
                if(matriz[a][y] == ' '){
                    break;
                }
                else if(matriz[a][y] == ficha){
                    direccionValida[2] = true;
                    break;
                }
            }
        }
    }

    if(x < 6){
        //abajo
        if(matriz[x + 1][y] != ' ' && matriz[x + 1][y] != ficha){
            for(int a = x + 2; a < 8 ; a++){
                if(matriz[a][y] == ' '){
                    break;
                }
                else if(matriz[a][y] == ficha){
                    direccionValida[3] = true;
                    break;
                }
            }
        }
    }

    if((x < 6) && (y < 6)){
        //diagonal inferior derecha
        if(matriz[x + 1][y + 1] != ' ' && matriz[x + 1][y + 1] != ficha){
            int b = x + 2;
            for(int a = y + 2; a < 8; a++){
                if(matriz[b][a] == ' '){
                    break;
                }
                else if(matriz[b][a] == ficha){
                    direccionValida[7] = true;
                    break;
                }
                b++;
            }
        }
    }

    if((x > 1) && (y < 6)){
        //diagonal superior derecha
        if(matriz[x - 1][y + 1] != ' ' && matriz[x - 1][y + 1] != ficha){
            int b = x - 2;
            for(int a = y + 2; a < 8; a++){
                if(matriz[b][a] == ' '){
                    break;
                }
                else if(matriz[b][a] == ficha){
                    direccionValida[5] = true;
                    break;
                }
                b--;
            }
        }
    }

    if((x < 6) && (y > 1)){
        //diagonal inferior izquierda
        if(matriz[x + 1][y - 1] != ' ' && matriz[x + 1][y - 1] != ficha){
            int b = x + 2;
            for(int a = y - 2; a >= 0 ; a--){
                if(matriz[b][a] == ' '){
                    break;
                }
                else if(matriz[b][a] == ficha){
                    direccionValida[6] = true;
                    break;
                }
                b++;
            }
        }
    }

    for(int i=0; i<8; i++){
        if(direccionValida[i]==true){
            return true;
        }
    }
    return false;
}

bool tablero::PosibleMovimiento(char ficha)
{
    bool posibilidad=false;
    for(int i=0; i<8; i++){
        for (int j = 0; j < 8; j++) {
            if(matriz[i][j]==' '){
                posibilidad= MovimientoValido(i, j, ficha);
                if(posibilidad){
                    return posibilidad;
                }
            }
        }
    }
    return posibilidad;
}

int tablero::GetPuntacion( int indice) const{
    return puntacion[indice];
}

bool tablero::CasillaVacia(int i, int j){
    if(matriz[i][j]==' '){
        return true;
    }else{
        return false;
    }
}

void tablero::ActualizarTablero(int x, int y, char ficha){
    int a=0,b=0;
    //izquierda
    a = y - 1;
    while(direccionValida[0]){
        if(matriz[x][a] != ficha){
            matriz[x][a] = ficha;
            a--;
        }
        else{
            direccionValida[0] = false;
        }
    }
    //derecha
    a = y + 1;
    while(direccionValida[1]){
        if(matriz[x][a] != ficha){
            matriz[x][a] = ficha;
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
            matriz[a][y] = ficha;
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
            matriz[a][y] = ficha;
            a++;
        }
        else{
            direccionValida[3] = false;
        }
    }
    //diagonal superior izquierda
    a = y - 1;
    b = x - 1;
    while(direccionValida[4]){
        if(matriz[b][a] != ficha){
            matriz[b][a] = ficha;
            a--;
            b--;
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
            matriz[b][a] = ficha;
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
            matriz[b][a] = ficha;
            b++;
            a--;
        }
        else{
            direccionValida[6] = false;
        }
    }
    //diagonal inferior derecha
    b = x + 1;
    a = y + 1;
    while(direccionValida[7]){
        if(matriz[b][a] != ficha){
            matriz[b][a] = ficha;
            b++;
            a++;
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

bool tablero::Movimiento(char ficha)
{
    bool verificar_celda=false;
    //Funcion que no está implementada y todavía no estoy segura de si la voy a usar
    int fila= RecibirRespuesta("fila");
    int columna= RecibirRespuesta("columna");
    verificar_celda=CasillaVacia(fila-1, columna-1);
    if(verificar_celda){
        verificar_celda= MovimientoValido(fila-1, columna-1, ficha);
        if(verificar_celda){
            matriz[fila-1][columna-1]=ficha;
            ActualizarTablero(fila-1, columna-1, ficha);
        }else{
            cout<<"Este movimiento es invalido"<<endl;
            return true;
        }
        ContarFichas();
        imprimirTablero();
        return false;
    }else{
        cout<<"Esta casilla está ocupada, ingrese una nueva coordenada"<<endl;
        return true;
    }

}

void tablero::ContarFichas(){
    int contadorX=0;
    int contadorO=0;
    for (int i = 0; i < 8; i++) {
        for(int j=0; j<8; j++){
            if(matriz[i][j]=='X'){
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
        GuardarPartida(jugadorX, puntacion[0]);
    }else if(puntacion[0]< puntacion[1]){
        cout<<"Felicidades"<<jugadorO<<"! GANASTE!"<<endl;
        GuardarPartida(jugadorO, puntacion[1]);
    }else{
        cout<<"EMPATE!"<<endl;
        GuardarPartida(puntacion[0]);
    }
    cout<<"Puntacion: "<<endl;
    cout<<"X:" <<puntacion[0]<<endl;
    cout<<"0: "<<puntacion[1]<<endl;


    //Esta funcion llama a contar fichas e imprime quién ganó y la cantidad de fichas
    //que tuvo cada uno
}

void tablero::actualizarDirecciones(){
    for(int i = 0; i<8 ; i++){
        direccionValida[i] = false;
    }
}

tablero::~tablero(){
   /* for(int i=0; i<8;i++){
        delete matriz[i];
    }
    delete[] matriz;*/
}
