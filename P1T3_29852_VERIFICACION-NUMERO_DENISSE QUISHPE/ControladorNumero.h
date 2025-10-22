#ifndef CONTROLADORNUMERO_H
#define CONTROLADORNUMERO_H

#include "Numero.h"
#include "VistaNumero.h"

class ControladorNumero {
private:
    VistaNumero vista; 
public:
    ControladorNumero();
    void crearNumeros(); 
};

#endif // CONTROLADORNUMERO_H