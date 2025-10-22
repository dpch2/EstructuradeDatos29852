#include "Controlador.h"
#include "Modelo.h"
#include <iostream>
#include <typeinfo>

using namespace std;

int main() {
    // Define el tipo de dato para las matrices
    using MatrixType = int; 

    cout << "Iniciando aplicacion MVC con Matrices 3D (Tipo: " << typeid(MatrixType).name() << ")\n";

    // 1. Crea el Modelo
    Modelo<MatrixType> modelo;

    // 2. Crea el Controlador
    Controlador<MatrixType> controlador(&modelo);

    // 3. Inicia el flujo de la aplicacion
    controlador.ejecutar();

    return 0;
}