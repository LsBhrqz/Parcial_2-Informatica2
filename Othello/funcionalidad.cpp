#include "funcionalidad.h"

using namespace std;
bool esNumero(string str)
{
    for(char c : str){
        if((c < '1') || (c > '8')){
            return false;
        }
    }
    return true;
}

int RecibirRespuesta(string dato)
{
    #define WHITE   "\033[37m"
    #define GREEN   "\033[32m"
    #define YELLOW  "\033[33m"

    string entrada;
    bool entradaValida = false;
    int numero = 0;

    while(!entradaValida){
        if(dato=="fila"){
            cout <<WHITE<< "\tIngrese el numero de la "<<GREEN<<dato<<": "<<WHITE;
        }else{
            cout <<WHITE<< "\tIngrese el numero de la "<<YELLOW<<dato<<": "<<WHITE;
        }
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
            cout << "\tEntrada invalida. Por favor, ingrese solo numeros entre el 1 y el 8" << endl;
        }
    }

    return numero;
}

bool juego()
{
    #define RED     "\033[31m"
    #define WHITE   "\033[37m"
    #define BLUE    "\033[34m"
    #define YELLOW  "\033[33m"

    tablero Tablero;
    cout<<RED<<"\n\tJugador con las X's"<<endl;
    jugador jugadorX;
    jugadorX.setFicha('X');
    cout <<BLUE<< "\n\tJugador con las O's"<<endl;
    jugador jugadorO;
    jugadorO.setFicha('O');
    bool validar_continuacion=true;
    bool posible_movimientoX=false;
    bool posible_movimientoO=false;
    Tablero.ContarFichas();
    Tablero.imprimirTablero();
    while(validar_continuacion){
        //validar_continuacion= Tablero.EstadoTablero();
        posible_movimientoX= Tablero.PosibleMovimiento(jugadorX.getFicha());
        posible_movimientoO= Tablero.PosibleMovimiento(jugadorO.getFicha());
        if(posible_movimientoO==false && posible_movimientoX==false){
            cout<<"\tNinguno de los jugadores tiene posibles movimientos"<<endl;
            validar_continuacion=false;
        }else if(validar_continuacion){
            if(!posible_movimientoX){
                cout<<RED<<"\n\t"<<jugadorX.getNombre()<<" no tienes posibles movimientos"<<endl;
            }else{
                while(posible_movimientoX){
                    cout<<RED<<"\n\tTurno de "<<jugadorX.getNombre()<<endl;
                    posible_movimientoX=Tablero.Movimiento(jugadorX.getFicha());
                }
            }
            validar_continuacion= Tablero.EstadoTablero();
            posible_movimientoO= Tablero.PosibleMovimiento(jugadorO.getFicha());
            if(validar_continuacion){
                if(!posible_movimientoO){
                    cout<<BLUE<<"\n\t"<<jugadorO.getNombre()<<" no tienes posibles movimientos"<<endl;
                }else{
                    while(posible_movimientoO){
                        cout<<BLUE<<"\n\tTurno de "<<jugadorO.getNombre()<<endl;
                        posible_movimientoO= Tablero.Movimiento(jugadorO.getFicha());
                    }
                }
                validar_continuacion= Tablero.EstadoTablero();
            }
        }
    }
    Tablero.ContarFichas();
    Tablero.Resultado(jugadorX.getNombre(), jugadorO.getNombre());
    while(true){
        string continuacion;
        cout<<YELLOW<<"\n\tDesea jugar de nuevo? s(si)/n(no): "<<WHITE;cin>>continuacion;
        validar_continuacion= RespuestaValida(continuacion);
        if(validar_continuacion){
            if(continuacion=="s"){
                return true;
            }else{
                return false;
            }
        }
    }
}
