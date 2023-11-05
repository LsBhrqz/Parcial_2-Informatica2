#include "archivos.h"

void ImprimirNombre(string nombre_archivo)
{
/* Esta funcion recibo el nombre de un archivo e imprime linea por linea lo que hay en él de color amarillo
 * Parametros: string :: nombre_archivo
 * Retorna: void
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
 * Parametros: string :: nombredelarchivo
 * Retorna: bool:: true or false
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
 * Parametros: &string :: nombre_archivo
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
 * Parametros: &string:: respuesta
 * Retorna: bool :: true o false
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
 * Parametros: string& :: othello
 * Retorna: bool :: bandera_titulo
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
/* Llama a una función que imprime la presentación y en caso de poder hacerlo despliega el
 * menu principal del juego, en caso de que quiera jugar retorna true, si quiere salir del sistema
 * retorna false
 * Parametros: void
 * Retorna: bool :: true o false
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
/*En el momento en que se invoque la función ella invoca la función time para obtener el timepo
 * en ese momento en segundos(es el tiempo transcurrido desde el Epoch (1 de enero de 1970)
 * hasta ese momento), despupes invoca a la fucnión localtime para que convierta esa información
 * en componentes de tiempo. Para guadar la información agrupo la información como un string
 * que finalmente es lo que retorna la función
 * Parametros: void
 * Retorna: string :: fechayhora
*/
    time_t tiempo = time(&tiempo); //time_t es un tipo de variable que representa
    // mediciones de tiempo, normalmente se trata como un entero

    // tm en cambia es una estructura de datos (parecido a una clase pero sus atributos
   // son públicos por defecto) que permite deglosar en "unidades" el tiempo que se
    //obtuvo en la variable tipo time_t
    tm* fecha_hora = localtime(&tiempo);

    string fechayhora= "Fecha y hora: ";
    fechayhora+= to_string(fecha_hora->tm_year +1900) +"-"; //le suma 1900 porque mide el tiempo desde ese año
    fechayhora+= to_string(fecha_hora->tm_mon + 1)+"-" + to_string(fecha_hora->tm_mday)+" ";
    fechayhora+= to_string(fecha_hora->tm_hour)+":" + to_string(fecha_hora->tm_min)+":";
    fechayhora+= to_string(fecha_hora->tm_sec);

    return fechayhora;
}

void CrearArchivoHistorial(string& nombre_archivo){
/* Esta función llama a tra función para que modifique un string que es el nombre del archivo
 * donde se guardan las partidas, abre el archivo en caso de que exista y si no existe lo crea
 * le coloca el título ("OTHELLO") y finalmente lo cierra
 * Parametro: string& :: nombre_archivo
 * Retorna: void
*/
    CambiarNombreArchivo(nombre_archivo);
    ofstream archivo;
    archivo.open(nombre_archivo);
    archivo<<"OTHELLO\n"<<endl;
    archivo.close();
}

bool VerificarArchivo(string& nombreArchivo){
/* Verifica que un archivo exista, en caso de que no exista le pregunta al usuario si quiere
 * salir del programa, si no quiere hacerlo crea el archivo
 * Parametro: string& :: nombreArchivo
 * Retorna: bool :: bandera_titulo
*/
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
/* Esta función llama a otra para verificar si se sencuentra el archivo, en caso de que lo haga
 * Guardo el nombre del jugador que ganó con la cantidad de fichas, la fecha y la hora
 * Parametros: string :: nombre_jugador, int :: num_fichas
 * Retorna: void
*/
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
/* Esta es una versión sobrecargada de GuardarPartida, la diferencia es que esta función solo
 * recibe un número entero porque se llama cuando ha ocurrido un empate
 * Parametro: int :: num_fichas
 * Retorna: void
*/
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
