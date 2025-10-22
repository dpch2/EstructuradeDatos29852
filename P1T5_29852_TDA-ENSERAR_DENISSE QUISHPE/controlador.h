#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "matriz_Modelo.h"
#include "vista.h"

class Controlador {
private:
    Matriz* modelo;
    Vista vista;

public:
    Controlador();
    void ejecutar();
};

#endif