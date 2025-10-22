#ifndef OPERACIONESFRACCION_H
#define OPERACIONESFRACCION_H

#include "Fraccion.h"

template <typename T>
class OperacionesFraccion {
public:
    Fraccion<T> multiplicar(const Fraccion<T>& f1, const Fraccion<T>& f2) {
        T num = f1.getNumerador() * f2.getNumerador();
        T den = f1.getDenominador() * f2.getDenominador();
        return Fraccion<T>(num, den);
    }
};

#endif