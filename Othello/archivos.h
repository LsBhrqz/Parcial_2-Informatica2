#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <iostream>
#include <fstream>

using namespace std;

void ImprimirNombre(string nombre_archivo);

bool comprobarLectura( string nombredelarchivo);

void CambiarNombreArchivo(string& nombre_archivo);

bool RespuestaValida(string respuesta);

bool intro(string& othello);

bool menu();

#endif // ARCHIVOS_H
