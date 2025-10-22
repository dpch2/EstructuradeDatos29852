#include "vista.h"
#include <iostream>
using namespace std;

void Vista::mostrarMensaje(string msg) {
    cout << msg << endl;
}

void Vista::mostrarResultado(float resultado) {
    cout << "Resultado de la multiplicacion: " << resultado << endl;
}