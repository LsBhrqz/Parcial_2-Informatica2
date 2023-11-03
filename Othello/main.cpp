#include <iostream>
#include "archivos.h"
#include "tablero.h"
#include "funcionalidad.h"
#include "jugador.h"
using namespace std;

int main()
{

    string TituloArchivo= "Othello";
    bool ban_inicio= intro(TituloArchivo);
    bool validar_jugar=false;
    if(ban_inicio){
        validar_jugar=menu();
        if(validar_jugar){
            juego();
        }else{
            ban_inicio;
        }
    }

    cout<<"Que lastima que te vayas"<<endl;
    cout<<"Vuelve pronto!"<<endl;


    return 0;
}
