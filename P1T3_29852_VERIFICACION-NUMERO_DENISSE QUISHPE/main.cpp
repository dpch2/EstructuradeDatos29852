#include <iostream>
#include "ControladorNumero.h" 

using namespace std;

int main() {
    cout << "--- Sistema de Validacion de Datos (MVC) ---" << endl;
    
    // 1. Inicializa el Controlador
    ControladorNumero appController;
    
    // 2. Ejecuta la logica principal
    appController.crearNumeros(); 

    cout << "\n--- FIN DE PROCESO ---" << endl;
    return 0;
}