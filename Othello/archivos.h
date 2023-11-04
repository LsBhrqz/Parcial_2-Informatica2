#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

void ImprimirNombre(string nombre_archivo);

bool comprobarLectura( string nombredelarchivo);

void CambiarNombreArchivo(string& nombre_archivo);

bool RespuestaValida(string respuesta);

bool intro(string& othello);

bool menu();

string SacarFechayHora();

void CrearArchivoHistorial();

bool VerificarArchivo(string &nombreArchivo);

void GuardarPartida(string nombre_jugador1, int num_fichas_1);

void GuardarPartida(int num_fichas);

#endif // ARCHIVOS_H
