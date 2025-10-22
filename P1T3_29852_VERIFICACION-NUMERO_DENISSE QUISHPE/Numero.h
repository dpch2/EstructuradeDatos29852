#ifndef NUMERO_H
#define NUMERO_H

#include <stdexcept> 

class Numero {
private:
    int numero;
public:
    Numero(int n); 
    int getNumero() const;
    void setNumero(int n); // Lanza la excepción
};

#endif