#ifndef MODELO_H
#define MODELO_H

#include <iostream>
using namespace std;

class Complejo {
private:
    float real;
    float imag;

public:
    // Constructor
    Complejo(float r = 0, float i = 0);

    // Metodos set/get
    void setReal(float r);
    void setImag(float i);
    float getReal() const;
    float getImag() const;

    // Sobrecarga de operadores
    Complejo operator+(const Complejo& c) const;
    Complejo operator-(const Complejo& c) const;
    Complejo operator*(const Complejo& c) const;
    bool operator==(const Complejo& c) const;

    // Sobrecarga del operador de salida <<
    friend ostream& operator<<(ostream& salida, const Complejo& c);
};

#endif
