#ifndef MODELO_H
#define MODELO_H

#include "Interfaz.h"
#include <iostream>

using namespace std;

template <typename T>
class Modelo : public Interfaz<T> {
public: 
    T*** mat1;
    T*** mat2;
    T*** matResultado;
    int profundidad;
    int filas;
    int columnas;

public:
    Modelo();
    ~Modelo();

    // IMPLEMENTACION DE INTERFAZ
    void encerar(T*** matriz, int p, int f, int c) override;
    void ingresar(T*** matriz, int p, int f, int c) override;
    void imprimir(T*** matriz, int p, int f, int c) override;
    T*** reservarMemoria(int p, int f, int c) override;
    void liberarMemoria(T*** matriz, int p, int f, int c) override;

    // METODOS ESPECIFICOS DEL MODELO
    void configurarMatrices(int p, int f, int c);
    void liberarTodasLasMatrices();

    // Funcion recursiva para sumar las matrices
    void sumarRecursivo(T*** matA, T*** matB, T*** matC, int p, int f, int c);
};

#endif // MODELO_H