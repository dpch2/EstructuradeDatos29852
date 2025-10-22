#ifndef __MultiplicarFracciones_IOperacionesFraccion_h
#define __MultiplicarFracciones_IOperacionesFraccion_h

class Fraccion; 

class IOperacionesFraccion {
public:
    virtual Fraccion multiplicar(const Fraccion& otra) = 0;
};

#endif 
