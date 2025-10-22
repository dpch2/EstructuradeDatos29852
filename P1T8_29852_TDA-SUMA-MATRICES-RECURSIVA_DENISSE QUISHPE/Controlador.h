#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Modelo.h"
#include "Vista.h" 
#include <iostream>
#include <limits>

using namespace std;

template <typename T>
class Controlador {
private:
    Modelo<T>* modelo;

public:
    Controlador(Modelo<T>* m);
    void ejecutar();
    void ingresarDatos();
    void procesarSuma();
};

template <typename T>
Controlador<T>::Controlador(Modelo<T>* m) : modelo(m) {}

template <typename T>
void Controlador<T>::ejecutar() {
    // La vista se inicializa aqui para empezar el flujo
    Vista<T> vista(this);
    vista.ejecutarFlujo();
}

template <typename T>
void Controlador<T>::ingresarDatos() {
    int p, f, c;
    cout << "\n--- Configuracion de Matrices ---\n";
    cout << "Profundidad (P): ";
    cin >> p;
    cout << "Filas (F): ";
    cin >> f;
    cout << "Columnas (C): ";
    cin >> c;

    if (p <= 0 || f <= 0 || c <= 0) {
        cout << "Error: Las dimensiones deben ser mayores que cero.\n";
        return;
    }

    modelo->configurarMatrices(p, f, c);

    cout << "\n*** Ingreso de Matriz A ***\n";
    modelo->ingresar(modelo->mat1, p, f, c);
    
    cout << "\n*** Ingreso de Matriz B ***\n";
    modelo->ingresar(modelo->mat2, p, f, c);
}

template <typename T>
void Controlador<T>::procesarSuma() {
    if (!modelo->mat1 || !modelo->mat2) {
        cout << "Error: Debe ingresar las matrices primero (Opcion 1).\n";
        return;
    }
    
    cout << "\n--- Realizando Suma Recursiva ---\n";
    
    // Llama a la funcion recursiva.
    modelo->sumarRecursivo(modelo->mat1, modelo->mat2, modelo->matResultado, 
                           modelo->profundidad, modelo->filas, modelo->columnas);

    cout << "\n============================================\n";
    cout << "           RESULTADOS COMPLETOS\n";
    cout << "============================================\n";
    
    // Imprime las 3 matrices
    cout << "\n--- Matriz A Original ---\n";
    modelo->imprimir(modelo->mat1, modelo->profundidad, modelo->filas, modelo->columnas);
    
    cout << "\n--- Matriz B Original ---\n";
    modelo->imprimir(modelo->mat2, modelo->profundidad, modelo->filas, modelo->columnas);

    cout << "\n--- Matriz RESULTADO (A + B) ---\n";
    modelo->imprimir(modelo->matResultado, modelo->profundidad, modelo->filas, modelo->columnas);
    
    cout << "\nSuma recursiva finalizada.\n";
}

#endif // CONTROLADOR_H