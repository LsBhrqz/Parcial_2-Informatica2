#include "archivos.h"
#include <ctime>

void ImprimirNombre(string nombre_archivo)
{
    /* Esta funcion recibo el nombre de un archivo e imprime linea por linea lo que hay en él de color amarillo
 * Parametros: archivo : string
 * Retorna: void;
*/
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"
    ifstream archivo;
    string linea;
    archivo.open(nombre_archivo);

    // Bucle hasta el fin de archivo
    while (getline(archivo, linea)) {
        // Imprima lo que lee de color amarillo en la consola
        cout << YELLOW << linea << endl;
    }
    cout<<RESET;
}

bool comprobarLectura( string nombredelarchivo)
{
    /* Verifica si el archivo existe en caso de que lo haga retorna true y si no lo hace retorna false
 * Parametros: nombredelarchivo:string
 * Retorna: true or false: bool
*/
    ifstream archivo;
    archivo.open(nombredelarchivo);
    if(!archivo){
        cerr << "No se puede abrir el archivo. No se encuentra." << endl;
        return false;
    }else{
        archivo.close();
        return true;
    }
}

void CambiarNombreArchivo(string& nombre_archivo)
{
/* Aun no estoy segura si se va a usar
*/
    cout<<"Ingrese el nombre del nuevo archivo: ";
    string nombre_nuevo_archivo; cin>> nombre_nuevo_archivo;
    nombre_nuevo_archivo+= ".txt";
    nombre_archivo= nombre_nuevo_archivo;
}

bool RespuestaValida(string respuesta)
{
    if(respuesta.length()>1){
        cout<<"Solo puede ingresar una letra (s/n)"<<endl;
        return false;
    }else{
        if(respuesta != "s" && respuesta != "n"){
            cout<< "Ingresaste una respuesta invalida"<<endl;
            return false;
        }else{
            return true;
        }
    }
}

bool intro(string& othello)
{
    bool bandera_titulo= false;
    bool ban=true;
    string respuesta="";
    while(ban){
        bandera_titulo= comprobarLectura(othello);
        if(bandera_titulo){
            ImprimirNombre(othello);
            ban=false;
        }else{
            bool controlban= true;
            while(controlban){
                cout<<"Desea salir del programa? s(si)/n(no): ";
                cin >> respuesta;
                bool ban_interna= RespuestaValida(respuesta);
                if(ban_interna){
                    if(respuesta=="s"){
                        return bandera_titulo;
                    }else{
                        controlban=false;
                    }
                }
            }
            CambiarNombreArchivo(othello);
        }
    }
    return bandera_titulo;
}

bool menu()
{
#define GREEN   "\033[32m"
    string othello= "Othelo.txt";
    bool bandera_titulo = intro(othello);
    int eleccion_menu=0;
    if (bandera_titulo) {
        bool segunda_ban= true;
        while(segunda_ban){
            cout <<GREEN<< "\nBienvenido a Othello!\n" << endl;
            cout << "1. Jugar en modo multijugador" << endl;
            cout << "2. Salir del sistema" << endl;
            cout << "Seleccione la opcion que desea: ";
            try {
                if (!(cin >> eleccion_menu)) {
                    throw 1;
                } else if (eleccion_menu != 1 && eleccion_menu != 2) {
                    throw 2;
                } else {
                    if (eleccion_menu == 1) {
                        return true;

                    }else{
                        return false;
                    }
                }
            } catch (int error) {
                if (error == 1) {
                    cout << "Ingresate una opcion invalida. Solo puede ingresar numeros\n";
                } else if (error == 2) {
                    cout << "Seleccione 1 o 2 para ingresar" << endl;

                }
                cin.clear();
                cin.ignore(255, '\n');
            }
        }
    }else{
        return bandera_titulo;
    }
}

string SacarFechayHora(){
    // Obtener el tiempo actual en segundos desde el Epoch (1 de enero de 1970)
    time_t tiempo = time(&tiempo);

    // Convertir el tiempo a una estructura tm para obtener la hora y fecha
    tm* fecha_hora = localtime(&tiempo);

    string fechayhora= "Fecha y hora: ";
    fechayhora+= to_string(fecha_hora->tm_year +1900) +"-";
    fechayhora+= to_string(fecha_hora->tm_mon + 1)+"-" + to_string(fecha_hora->tm_mday)+" ";
    fechayhora+= to_string(fecha_hora->tm_hour)+":" + to_string(fecha_hora->tm_min)+":";
    fechayhora+= to_string(fecha_hora->tm_sec);

    return fechayhora;
}

void CrearArchivoHistorial(string& nombre_archivo){
    CambiarNombreArchivo(nombre_archivo);
    ofstream archivo;
    archivo.open(nombre_archivo);
    archivo<<"OTHELLO\n"<<endl;
    archivo.close();
}

bool VerificarArchivo(string& nombreArchivo){
    bool bandera_titulo= false;
    bool ban=true;
    string respuesta="";
    while(ban){
        bandera_titulo= comprobarLectura(nombreArchivo);
        if(bandera_titulo){
            ban=false;
        }else{
            bool controlban= true;
            while(controlban){
                cout<<"Desea salir del programa aunque no se guarde la partida? s(si)/n(no): ";
                cin >> respuesta;
                bool ban_interna= RespuestaValida(respuesta);
                if(ban_interna){
                    if(respuesta=="s"){
                        return bandera_titulo;
                    }else{
                        controlban=false;
                    }
                }
            }
            CrerArchivoHistorial(nombreArchivo);
        }
    }
    return bandera_titulo;
}

void GuardarPartida(string nombre_jugador, int num_fichas){
    string historial= "Historial.txt";
    bool ban=VerficarArchivo(historial);
    if(ban){
        ofstream archivo;
        archivo.open(historial, ios::app);
        archivo<<SacarFechayHora()<<endl;
        archivo<<"El ganador fue "<<nombre_jugador<<" con "<<num_fichas<< " fichas"<<endl;
        archivo.close();
    }
    return ban;
}
