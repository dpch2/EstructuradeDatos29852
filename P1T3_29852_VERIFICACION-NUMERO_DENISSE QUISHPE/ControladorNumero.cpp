#include "ControladorNumero.h"
#include <iostream>
#include <stdexcept>

using namespace std; 

ControladorNumero::ControladorNumero() {
    
    cout << ">>> Modulo de Control inicializado." << endl;
}

// METODO CON INTERACCION DE USUARIO (CIN) Y MANEJO DE EXCEPCIONES
void ControladorNumero::crearNumeros() {
    int valorIngresado;
    
    // Creamos un objeto Modelo inicial
    Numero nPrueba(1); 
    cout << "\n--- Inicio de Transacciones ---" << endl;
    
    while (true) {
        cout << "\nIngrese un numero entero positivo para actualizar el Objeto: ";
        
        // Verifica la entrada. Si falla (ej. letra o EOF), sale.
        if (!(cin >> valorIngresado)) {
            break; 
        }
        
        // El Controlador usa try-catch para gestionar el flujo de la aplicacion
        try {
            cout << "   Procesando ..." << endl;
            // 1. Llama al Modelo (setNumero)
            nPrueba.setNumero(valorIngresado); 
            
            // 2. Llama a la Vista (si no hubo excepcion)
            VistaNumero vista;
            vista.mostrarNumero(nPrueba);
            
        } catch (const invalid_argument& e) {
            // 3. Capturamos la excepcion del Modelo
            cerr << "\n  [ERROR] Transaccion RECHAZADA: " << e.what() << endl;
            cerr << "  [ERROR] El valor actual (" << nPrueba.getNumero() << ") se mantiene." << endl;
        }
    }
}