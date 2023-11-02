#include "funcionalidad.h"
#include "tablero.h"
#include "jugador.h"

using namespace std;
bool esNumero(string str){
    for(char c : str){
        if((c < '1') || (c > '8')){
            return false;
        }
    }
    return true;
}

int RecibirRespuesta(string dato){
    string entrada;
    bool entradaValida = false;
    int numero = 0;

    while(!entradaValida){
        cout << "Ingrese el numero de la "<<dato<<": ";
        cin >> entrada;

        entradaValida = esNumero(entrada);

        if(entradaValida){
            numero = 0;
            for (char c : entrada){
                numero = numero * 10 + (c - '0');
            }

            if(numero < 1){
                entradaValida = false;
            }
        }

        if(!entradaValida){
            cout << "Entrada inválida. Por favor, ingrese solo numeros entre el 1 y el 8" << endl;
        }
    }

    return numero;
}

bool juego(){

    tablero Tablero;
    cout<<"Jugador con las X's"<<endl;
    jugador jugadorX;
    cout << "Jugador con las O's"<<endl;
    jugador jugadorO;
    bool validar_continuacion=true;
    bool turnoX=false;
    bool turnoO=true;
    while(validar_continuacion){
        validar_continuacion= Tablero.EstadoTablero();
        if(validar_continuacion){
            while(turnoX){
                turnoO=true;
                turnoX=false;
                //Pirmero verifico si el jugador tiene algun movimiento posible
            }
        }
        validar_continuacion= Tablero.EstadoTablero();
        if(validar_continuacion){
            while(turnoO){

            }
            validar_continuacion= Tablero.EstadoTablero();
        }

    }



    return false;
}
