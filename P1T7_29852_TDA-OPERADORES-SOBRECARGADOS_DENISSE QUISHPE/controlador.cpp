#include "controlador.h"

Complejo Controlador::sumar(const Complejo& a, const Complejo& b) {
    return a + b;
}

Complejo Controlador::restar(const Complejo& a, const Complejo& b) {
    return a - b;
}

Complejo Controlador::multiplicar(const Complejo& a, const Complejo& b) {
    return a * b;
}

bool Controlador::comparar(const Complejo& a, const Complejo& b) {
    return a == b;
}

void Controlador::ejecutar() {
    float r1, i1, r2, i2;

    vista.mostrarMensaje("=== Operaciones con Numeros Complejos ===");
    vista.mostrarMensaje("Ingrese el primer numero complejo:");
    vista.mostrarMensaje("Parte real: ");
    cin >> r1;
    vista.mostrarMensaje("Parte imaginaria: ");
    cin >> i1;

    vista.mostrarMensaje("Ingrese el segundo numero complejo:");
    vista.mostrarMensaje("Parte real: ");
    cin >> r2;
    vista.mostrarMensaje("Parte imaginaria: ");
    cin >> i2;

    Complejo a(r1, i1);
    Complejo b(r2, i2);

    Complejo suma = sumar(a, b);
    Complejo resta = restar(a, b);
    Complejo mult = multiplicar(a, b);
    bool iguales = comparar(a, b);

    vista.mostrarMensaje("\nResultados:");
    vista.mostrarResultados("a = " + to_string(a.getReal()) + " + " + to_string(a.getImag()) + "i");
    vista.mostrarResultados("b = " + to_string(b.getReal()) + " + " + to_string(b.getImag()) + "i");
    vista.mostrarResultados("Suma: " + to_string(suma.getReal()) + " + " + to_string(suma.getImag()) + "i");
    vista.mostrarResultados("Resta: " + to_string(resta.getReal()) + " + " + to_string(resta.getImag()) + "i");
    vista.mostrarResultados("Multiplicacion: " + to_string(mult.getReal()) + " + " + to_string(mult.getImag()) + "i");

    if (iguales)
        vista.mostrarMensaje("Los numeros complejos son iguales");
    else
        vista.mostrarMensaje("Los numeros complejos son diferentes");
}