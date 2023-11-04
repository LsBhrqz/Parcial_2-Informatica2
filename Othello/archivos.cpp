#include "archivos.h"

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
/* Reemplaza el string que recibe por referencia por el nuevo que le ingresaron.
 * En este caso es el nombre de un arhivo por lo que le agrega el .txt
 * Parametros: nombre_archivo:&string
 * Retorna: void
*/
    cout<<"Ingrese el nombre del archivo que desea abrir: ";
    string nombre_nuevo_archivo; cin>> nombre_nuevo_archivo;
    nombre_nuevo_archivo+= ".txt";
    nombre_archivo= nombre_nuevo_archivo;
}

bool RespuestaValida(string respuesta)
{
 /* Verifica que el string que recibe sea de tamaño 1 e igual a la n o a la s.
 * En caso de serlo retorna true, si no lo es retorna false
 * Parametros: respuesta:&string
 * Retorna: true o false: bool
*/
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
/* Llama a una función para verificar que esté el archivo en caso de no estarlo despliega
 * un menu que le pregunta al usario si desea salirse del programa, si no quiere salirse
 * le da la opción de ingresar otro nombre para buscar ese archivo. En caso de que sí encuentre el
 * archivo llama a una función para que imprima el nombre. Si desea seguir en el programa
 * retorna true en caso contrario retorna false.
 * En este caso es el nombre de un arhivo por lo que le agrega el .txt
 * Parametros: nombre_archivo:&othello
 * Retorna: bandera_titulo: bool
*/
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
/* Llama a una función que imprime la presentación y de paso verifica si el usaurio
 * En este caso es el nombre de un arhivo por lo que le agrega el .txt
 * Parametros: void
 * Retorna: true o false: bool
*/
#define GREEN   "\033[32m"
#define WHITE   "\033[37m"
    string othello= "Othelo.txt";
    bool bandera_titulo = intro(othello);
    int eleccion_menu=0;
    if (bandera_titulo) {
        bool segunda_ban= true;
        while(segunda_ban){
            cout <<GREEN<< "\n\tBienvenido a Othello!\n" << endl;
            cout << "\t1. Jugar en modo multijugador" << endl;
            cout << "\t2. Salir del sistema" << endl;
            cout << "\tSeleccione la opcion que desea: "<<WHITE;
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
                    cout << "\tIngresate una opcion invalida. Solo puede ingresar numeros\n";
                } else if (error == 2) {
                    cout << "\tSolo puede seleccionar 1 o 2" << endl;

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
            CrearArchivoHistorial(nombreArchivo);
        }
    }
    return bandera_titulo;
}

void GuardarPartida(string nombre_jugador, int num_fichas){
    string historial= "Historial.txt";
    bool ban=VerificarArchivo(historial);
    if(ban){
        ofstream archivo;
        archivo.open(historial, ios::app);
        archivo<<SacarFechayHora()<<endl;
        archivo<<"El ganador fue "<<nombre_jugador<<" con "<<num_fichas<< " fichas"<<endl;
        archivo.close();
    }
}

void GuardarPartida(int num_fichas){
    string historial= "Historial.txt";
    bool ban=VerificarArchivo(historial);
    if(ban){
        ofstream archivo;
        archivo.open(historial, ios::app);
        archivo<<SacarFechayHora()<<endl;
        archivo<<"Hubo un empate con "<<num_fichas<< " fichas"<<endl;
        archivo.close();
    }
}
