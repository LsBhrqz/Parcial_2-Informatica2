#include "funcionalidad.h"
#include "tablero.h"
#include "jugador.h"

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

bool juego()
{

    tablero Tablero;
    cout<<"Jugador con las X's"<<endl;
    jugador jugadorX;
    jugadorX.setFicha('X');
    cout << "Jugador con las O's"<<endl;
    jugador jugadorO;
    jugadorO.setFicha('O');
    bool validar_continuacion=true;
    bool posible_movimientoX=false;
    bool posible_movimientoO=false;
    while(validar_continuacion){
        validar_continuacion= Tablero.EstadoTablero();
        posible_movimientoX= Tablero.PosibleMovimiento(jugadorX.getFicha());
        posible_movimientoO= Tablero.PosibleMovimiento(jugadorO.getFicha());
        if(posible_movimientoO==false && posible_movimientoX==false){
            cout<<"Ninguno de los jugadores tiene posibles movimientos"<<endl;
            validar_continuacion=false;
        }else if(validar_continuacion){
            if(!posible_movimientoX){
                cout<<"No tienes posibles movimientos"<<endl;
            }else{
                while(posible_movimientoX){
                    int fila= RecibirRespuesta("fila");
                    int columna= RecibirRespuesta("columna");
                    Tablero.MovimientoValido(fila, columna, jugadorX.getFicha());
                    Tablero.ActualizarTablero(fila, columna, jugadorX.getFicha());
                }
            }
            validar_continuacion= Tablero.EstadoTablero();
            if(validar_continuacion){
                if(!posible_movimientoO){
                    cout<<"No tienes posibles movimientos"<<endl;
                }else{
                    while(posible_movimientoO){
                        int fila= RecibirRespuesta("fila");
                        int columna= RecibirRespuesta("columna");
                        Tablero.MovimientoValido(fila, columna, jugadorO.getFicha());
                        Tablero.ActualizarTablero(fila, columna, jugadorO.getFicha());
                    }
                }
                validar_continuacion= Tablero.EstadoTablero();
            }
        }
    }
    Tablero.ContarFichas();
    if(Tablero.GetPuntacion(0)< Tablero.GetPuntacion(1)){
        //GuardarPartida();
    }
    return false;
}
