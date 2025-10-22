#ifndef __MultiplicarFracciones_Fraccion_h
#define __MultiplicarFracciones_Fraccion_h

#include "IOperacionesFraccion.h"

class Fraccion : public IOperacionesFraccion {
public:
    Fraccion(int n, int d);
    int getNumerador(void) const;
    int getDenominador(void) const;
    Fraccion multiplicar(const Fraccion& otra);
    void simplificar(void);
    void mostrar(void);

private:
    int mcd(int a, int b);
    int numerador;
    int denominador;
};

#endif 