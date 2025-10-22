#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "modelo.h"
#include "vista.h"

class Controlador {
private:
    Vista vista;

public:
    void ejecutar();
    Complejo sumar(const Complejo& a, const Complejo& b);
    Complejo restar(const Complejo& a, const Complejo& b);
    Complejo multiplicar(const Complejo& a, const Complejo& b);
    bool comparar(const Complejo& a, const Complejo& b);
};

#endif