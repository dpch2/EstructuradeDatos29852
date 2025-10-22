#include "matriz_Modelo.h"
#include <iostream>
using namespace std;

Matriz::Matriz(int f, int c) : filas(f), columnas(c) {
    matriz1 = new float*[filas];
    matriz2 = new float*[filas];
    matriz3 = new float*[filas];
    for (int i = 0; i < filas; i++) {
        matriz1[i] = new float[columnas];
        matriz2[i] = new float[columnas];
        matriz3[i] = new float[columnas];
    }
    enserar = new float[filas * columnas * 3];
}

void Matriz::ingresarDatos() {
    cout << "Ingrese datos para matriz1:\n";
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            cin >> matriz1[i][j];

    cout << "Ingrese datos para matriz2:\n";
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            cin >> matriz2[i][j];

    cout << "Ingrese datos para matriz3:\n";
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            cin >> matriz3[i][j];
}

void Matriz::enserarMatrices() {
    int index = 0;
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            enserar[index++] = matriz1[i][j];
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            enserar[index++] = matriz2[i][j];
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            enserar[index++] = matriz3[i][j];
}

void Matriz::imprimirMatrices() {
    for (int i = 0; i < filas * columnas * 3; i++)
        cout << enserar[i] << " ";
    cout << endl;
}

void Matriz::procesar() {
    for (int i = 0; i < filas * columnas * 3; i++)
        enserar[i] *= 2; 
}

float Matriz::multiplicar() {
    float resultado = 1;
    for (int i = 0; i < filas * columnas * 3; i++)
        resultado *= enserar[i];
    return resultado;
}

void Matriz::liberarMemoria() {
    for (int i = 0; i < filas; i++) {
        delete[] matriz1[i];
        delete[] matriz2[i];
        delete[] matriz3[i];
    }
    delete[] matriz1;
    delete[] matriz2;
    delete[] matriz3;
    delete[] enserar;
}