#ifndef FRACCION_H
#define FRACCION_H

#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
class Fraccion {
private:
    T numerador;
    T denominador;

    // Metodo privado para calcular el MCD
    T mcd(T a, T b) const {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            T temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    // Constructor
    Fraccion(T n = 0, T d = 1) {
        if (d == 0) {
            cout << "Error: El denominador no puede ser 0. Se asignara 1." << endl;
            d = 1;
        }
        numerador = n;
        denominador = d;
        simplificar();
    }

    // Getters
    T getNumerador() const { return numerador; }
    T getDenominador() const { return denominador; }

    // Setters
    void setNumerador(T n) { numerador = n; simplificar(); }
    void setDenominador(T d) {
        if (d == 0) {
            cout << "Error: El denominador no puede ser 0. Se asignara 1." << endl;
            d = 1;
        }
        denominador = d;
        simplificar();
    }

    // Metodo para simplificar la fraccion
    void simplificar() {
        T divisor = mcd(numerador, denominador);
        if (divisor != 0) {
            numerador /= divisor;
            denominador /= divisor;
        }
        if (denominador < 0) {
            numerador = -numerador;
            denominador = -denominador;
        }
    }

    // Mostrar fraccion
    void mostrar() const {
        cout << numerador << "/" << denominador;
    }
};

#endif