#include "Numero.h"
#include <iostream>
#include <stdexcept>

using namespace std; 

Numero::Numero(int n) {
    setNumero(n); 
}

int Numero::getNumero() const {
    return numero;
}

// LOGICA DE EXCEPCION: LANZAR (THROW)
void Numero::setNumero(int n) {
    if (n <= 0) {
       
        throw invalid_argument("ERROR: Valor de dato no valido. El numero debe ser positivo (> 0).");
    }
    this->numero = n;
}