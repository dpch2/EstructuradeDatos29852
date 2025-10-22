#ifndef MATRIZ_MODELO_H
#define MATRIZ_MODELO_H

class Matriz {
private:
    float** matriz1;
    float** matriz2;
    float** matriz3;
    float* enserar;
    int filas;
    int columnas;

public:
    Matriz(int filas, int columnas);
    void ingresarDatos();
    void enserarMatrices();
    void imprimirMatrices();
    void procesar();
    float multiplicar();
    void liberarMemoria();
};

#endif