#include "modelo.h"

// Constructor
Complejo::Complejo(float r, float i) {
    real = r;
    imag = i;
}

// Metodos set/get
void Complejo::setReal(float r) { real = r; }
void Complejo::setImag(float i) { imag = i; }
float Complejo::getReal() const { return real; }
float Complejo::getImag() const { return imag; }

// Sobrecarga operador +
Complejo Complejo::operator+(const Complejo& c) const {
    return Complejo(real + c.real, imag + c.imag);
}

// Sobrecarga operador -
Complejo Complejo::operator-(const Complejo& c) const {
    return Complejo(real - c.real, imag - c.imag);
}

// Sobrecarga operador *
Complejo Complejo::operator*(const Complejo& c) const {
    return Complejo(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

// Sobrecarga operador ==
bool Complejo::operator==(const Complejo& c) const {
    return (real == c.real && imag == c.imag);
}

// Sobrecarga operador <<
ostream& operator<<(ostream& salida, const Complejo& c) {
    salida << c.real << " + " << c.imag << "i";
    return salida;
}
