#ifndef INTERFAZ_H
#define INTERFAZ_H

template <typename T>
class Interfaz {
public:
    virtual void encerar(T*** matriz, int profundidad, int filas, int columnas) = 0;
    virtual void ingresar(T*** matriz, int profundidad, int filas, int columnas) = 0;
    virtual void imprimir(T*** matriz, int profundidad, int filas, int columnas) = 0;
    virtual T*** reservarMemoria(int profundidad, int filas, int columnas) = 0;
    virtual void liberarMemoria(T*** matriz, int profundidad, int filas, int columnas) = 0;

    virtual ~Interfaz() {}
};

#endif 