#ifndef VISTA_H
#define VISTA_H

#include <iostream>
#include <limits> 

// Declaracion anticipada de Controlador
template <typename T>
class Controlador; 

using namespace std;

template <typename T>
class Vista {
private:
    Controlador<T>* controlador;

public:
    Vista(Controlador<T>* ctrl);
    void mostrarMenu();
    void ejecutarFlujo();
};

template <typename T>
Vista<T>::Vista(Controlador<T>* ctrl) : controlador(ctrl) {}

template <typename T>
void Vista<T>::mostrarMenu() {
    cout << "\n============================================\n";
    cout << "  Suma Recursiva de Matrices Tridimensionales\n";
    cout << "============================================\n";
    cout << "1. Ingresar dimensiones y datos de las matrices\n";
    cout << "2. Realizar suma y mostrar resultado\n";
    cout << "3. Salir\n";
    cout << "Seleccione una opcion: ";
}

template <typename T>
void Vista<T>::ejecutarFlujo() {
    int opcion;
    do {
        mostrarMenu();
        if (!(cin >> opcion)) {
            cout << "Error: Entrada no valida. Intente de nuevo.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (opcion) {
            case 1:
                controlador->ingresarDatos();
                break;
            case 2:
                controlador->procesarSuma();
                break;
            case 3:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opcion no reconocida. Intente de nuevo.\n";
        }
    } while (opcion != 3);
}

#endif // VISTA_H