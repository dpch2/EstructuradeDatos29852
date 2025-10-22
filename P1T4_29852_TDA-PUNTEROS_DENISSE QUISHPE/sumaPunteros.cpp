#include "Operaciones.h"
using namespace std; 
// IMPLEMENTACION DEL MODELO (Clase Operaciones)
Operaciones::Operaciones(int v) : valor(v) {}

void Operaciones::setValor(int v) {
    this->valor = v;
}

int Operaciones::getValor() const {
    return this->valor;
}

int* Operaciones::getPointer() {
    return &this->valor;
}

// Implementacion de la sobrecarga del operador +
Operaciones Operaciones::operator+(const Operaciones& otro) const {
    return Operaciones(this->valor + otro.valor);
}

// IMPLEMENTACION DEL CONTROLADOR (Metodos estaticos de Operaciones)
// Suma de tres valores desreferenciando punteros
int Operaciones::sumarConPunteros(int* p1, int* p2, int* p3) {
    // Uso explicito de punteros: obtiene el valor al que apunta la direccion
    return (*p1) + (*p2) + (*p3);
}

// Suma usando la logica de sobrecarga del Modelo
Operaciones Operaciones::sumarConSobrecarga(Operaciones& n1, Operaciones& n2, Operaciones& n3) {
    return n1 + n2 + n3;
}

// IMPLEMENTACION DE LA VISTA (Clase Vista)
void Vista::mostrarResultado(const string& titulo, int resultado) {
    cout << "\n--- " << titulo << " ---\n";
    cout << "Resultado: " << resultado << endl;
}

void Vista::pedirValores(int& v1, int& v2, int& v3) {
    cout << "Ingrese el primer valor: ";
    cin >> v1;
    cout << "Ingrese el segundo valor: ";
    cin >> v2;
    cout << "Ingrese el tercer valor: ";
    cin >> v3;
}