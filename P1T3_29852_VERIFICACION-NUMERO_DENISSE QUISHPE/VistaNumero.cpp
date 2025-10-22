#include "VistaNumero.h"
#include <iostream>

using namespace std;

void VistaNumero::mostrarNumero(const Numero& num) const {
    
    cout << " Nuevo valor de objeto: " << num.getNumero() << endl;
}