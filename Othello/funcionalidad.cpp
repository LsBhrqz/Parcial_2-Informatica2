#include "funcionalidad.h"

using namespace std;
bool esNumero(string str)
{
 /* Recibe un string y verifica que este sea un número entre 1 y 8 versión char
 * Parametro: string :: str
 * Retorna: bool :: true o false
*/
    if(str.length()>1){
        cout<<"\tSolo puedes ingresar numeros entre el 1 y el 8"<<endl;
        return false;
    }else{
        for(char c : str){
            if((c < '1') || (c > '8')){
                cout<<"'\tSolo puedes ingresar numeros entre el 1 y el 8"<<endl;
                return false;
            }
        }
        return true;
    }
}

bool letraValida(string str)
{
 /* Esta función verifica que ingresen una letra entre la A y la H mayusculas
 * Parametro: string :: str
 * Retorna: bool :: true o false
*/
    if(str.length()>1){
        cout<<"\tSolo puedes ingresar una letra"<<endl;
        return false;
    }else{
        for(char c : str){
            if((c < 'A') || (c > 'H')){
                cout<<"\tSolo puedes ingresar letras entre la A y la H (mayusculas)"<<endl;
                return false;
            }
        }
    }
    return true;
}

int RecibirRespuesta(string dato)
{
 /* Recibe un string que definirá si le pide una fila o una columna, dependiendo del caso
  * lo imprime el mensaje de cierto color y retorna el valor numérico que le corresponde al
  * tablero desde el 1 al 8
 * Parametro: string :: dato
 * Retorna: int :: numero
*/
    #define WHITE   "\033[37m"
    #define GREEN   "\033[32m"
    #define YELLOW  "\033[33m"

    string entrada;
    bool entradaValida = false;
    int numero = 0;
    char caracter;

    while(!entradaValida){
        if(dato=="fila"){
            cout <<WHITE<< "\tIngrese el numero de la "<<GREEN<<dato<<": "<<WHITE;
        }else{
            cout <<WHITE<< "\tIngrese la letra de la "<<YELLOW<<dato<<": "<<WHITE;
        }
        cin >> entrada;

        if(dato=="fila"){
            entradaValida = esNumero(entrada);
            if(entradaValida){
                caracter = entrada[0];
                numero= caracter-48;
                return numero;
            }
        }else{
            entradaValida= letraValida(entrada);
            if(entradaValida){
                caracter = entrada[0];
                numero= caracter-64;
                return numero;
            }
        }
    }   
}

bool juego()
{
 /* Esta función se encarga de la continuidad del juego, instancia la clase tablero
  * y jugador, intercambia los turnos de la partida, verifica si es posible hacer jugadas y cuando
  * el juego termina invoca a la función Resultado, por último pregunta si quiere seguir jugando
  * en caso de hacerlo retorna true, en caso contrario retorna false
 * Parametro: void
 * Retorna: bool :: true o false
*/
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
