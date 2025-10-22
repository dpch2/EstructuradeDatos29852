#include "controlador.h"
#include <iostream>
using namespace std;

Controlador::Controlador() {
    modelo = nullptr;
}

void Controlador::ejecutar() {
    int filas, columnas;
    cout << "Ingrese numero de filas: ";
    if (!(cin >> filas)) {
        vista.mostrarMensaje("Entrada invalida para filas.");
        return;
    }
    cout << "Ingrese numero de columnas: ";
    if (!(cin >> columnas)) {
        vista.mostrarMensaje("Entrada invalida para columnas.");
        return;
    }

    modelo = new Matriz(filas, columnas);

    vista.mostrarMensaje("Ingresando datos...");
    modelo->ingresarDatos();

    modelo->enserarMatrices();
    modelo->procesar();

    float resultado = modelo->multiplicar();
    vista.mostrarResultado(resultado);

    vista.mostrarMensaje("Matriz unidimensional:");
    modelo->imprimirMatrices();

    modelo->liberarMemoria();
}