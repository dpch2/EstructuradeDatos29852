#include "Fraccion.h"
#include <iostream>
#include <cmath>
using namespace std;

Fraccion::Fraccion(int n, int d) {
    if (d == 0) {
        cout << "Error: El denominador no puede ser 0. Se asignara 1." << endl;
        d = 1;
    }
    numerador = n;
    denominador = d;
    simplificar();
}

int Fraccion::getNumerador(void) const { return numerador; }
int Fraccion::getDenominador(void) const { return denominador; }

Fraccion Fraccion::multiplicar(const Fraccion& otra) {
    int num = numerador * otra.getNumerador();
    int den = denominador * otra.getDenominador();
    return Fraccion(num, den);
}

void Fraccion::simplificar(void) {
    int divisor = mcd(numerador, denominador);
    if (divisor != 0) {
        numerador /= divisor;
        denominador /= divisor;
    }
    if (denominador < 0) {
        numerador = -numerador;
        denominador = -denominador;
    }
}

void Fraccion::mostrar(void) {
    cout << numerador << "/" << denominador;
}

int Fraccion::mcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
