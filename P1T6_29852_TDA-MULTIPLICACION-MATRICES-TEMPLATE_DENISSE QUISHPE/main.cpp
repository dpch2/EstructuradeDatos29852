#include <iostream>
#include <string>
#include "controladorMatriz.h" 

using namespace std;

int main() {
    VistaMatriz<float> vista;
    ControladorMatriz<float> controlador;

    int cantidad;
    vista.mostrarMensaje("Cuantas matrices desea ingresar?");
    if (!(cin >> cantidad) || cantidad < 1) {
        vista.mostrarMensaje("Error: Cantidad invalida.");
        return 1;
    }

    for (int i = 0; i < cantidad; i++) {
        try {
            vista.mostrarMensaje("--- Matriz " + to_string(i + 1) + " ---");
            Matriz<float> matriz = vista.solicitarDatos();
            controlador.agregarMatriz(matriz);
        } catch (const exception& e) {
            vista.mostrarMensaje(string("Error al ingresar matriz: ") + e.what());
            cin.clear();
            cin.ignore(10000, '\n');
            i--; 
        }
    }

    try {
        controlador.multiplicarTodas();
        controlador.mostrarResultado(vista);
    } catch (const exception& e) {
        vista.mostrarMensaje(string("Error en la multiplicacion: ") + e.what());
    }

    return 0;
}