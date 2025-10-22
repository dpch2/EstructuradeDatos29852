#include "Modelo.h"
#include <cstdlib>

using namespace std;

template <typename T>
Modelo<T>::Modelo() : mat1(nullptr), mat2(nullptr), matResultado(nullptr), 
                      profundidad(0), filas(0), columnas(0) {}

template <typename T>
Modelo<T>::~Modelo() {
    liberarTodasLasMatrices();
}

template <typename T>
T*** Modelo<T>::reservarMemoria(int p, int f, int c) {
    // Reserva T***
    T*** matriz = new T**[p];
    for (int i = 0; i < p; ++i) {
        // Reserva T**
        matriz[i] = new T*[f]; 
        for (int j = 0; j < f; ++j) {
            // Reserva T*
            matriz[i][j] = new T[c];
        }
    }
    return matriz;
}

template <typename T>
void Modelo<T>::liberarMemoria(T*** matriz, int p, int f, int c) {
    if (matriz) {
        for (int i = 0; i < p; ++i) {
            if (matriz[i]) {
                for (int j = 0; j < f; ++j) {
                    delete[] matriz[i][j];
                }
                delete[] matriz[i];
            }
        }
        delete[] matriz;
    }
}

template <typename T>
void Modelo<T>::encerar(T*** matriz, int p, int f, int c) {
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < f; ++j) {
            for (int k = 0; k < c; ++k) {
                matriz[i][j][k] = 0;
            }
        }
    }
}

template <typename T>
void Modelo<T>::ingresar(T*** matriz, int p, int f, int c) {
    cout << "\nIngreso de Matriz (" << p << "x" << f << "x" << c << "):\n";
    for (int i = 0; i < p; ++i) {
        cout << "  Capa " << i + 1 << ":\n";
        for (int j = 0; j < f; ++j) {
            for (int k = 0; k < c; ++k) {
                cout << "    [" << j + 1 << "][" << k + 1 << "]: ";
                cin >> matriz[i][j][k];
            }
        }
    }
}

template <typename T>
void Modelo<T>::imprimir(T*** matriz, int p, int f, int c) {
    for (int i = 0; i < p; ++i) {
        cout << "\n--- Capa " << i + 1 << " ---\n";
        for (int j = 0; j < f; ++j) {
            for (int k = 0; k < c; ++k) {
                cout << matriz[i][j][k] << "\t";
            }
            cout << endl;
        }
    }
}

template <typename T>
void Modelo<T>::configurarMatrices(int p, int f, int c) {
    liberarTodasLasMatrices();
    
    this->profundidad = p;
    this->filas = f;
    this->columnas = c;

    mat1 = reservarMemoria(p, f, c);
    mat2 = reservarMemoria(p, f, c);
    matResultado = reservarMemoria(p, f, c);
    
    encerar(matResultado, p, f, c);
}

template <typename T>
void Modelo<T>::liberarTodasLasMatrices() {
    liberarMemoria(mat1, profundidad, filas, columnas);
    liberarMemoria(mat2, profundidad, filas, columnas);
    liberarMemoria(matResultado, profundidad, filas, columnas);
    mat1 = mat2 = matResultado = nullptr;
    profundidad = filas = columnas = 0;
}

// Funcion recursiva. La recursividad opera sobre la dimension 'profundidad' (p).
template <typename T>
void Modelo<T>::sumarRecursivo(T*** matA, T*** matB, T*** matC, int p, int f, int c) {
    if (p == 0) return; // Caso base: todas las capas procesadas

    int current_p = p - 1; // Indice de la capa actual (0-based)

    // Se suman los elementos de la capa actual
    for (int i = 0; i < this->filas; ++i) {
        for (int j = 0; j < this->columnas; ++j) {
            matC[current_p][i][j] = matA[current_p][i][j] + matB[current_p][i][j];
        }
    }
    
    // Paso recursivo: procesar la siguiente capa
    sumarRecursivo(matA, matB, matC, current_p, f, c);
}

// Instanciacion explicita para el tipo int (necesario cuando la implementacion es separada)
template class Modelo<int>;