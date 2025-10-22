#ifndef MODELOMATRIZ_H
#define MODELOMATRIZ_H

#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class Matriz {
private:
    vector<vector<T>> datos;
    int filas;
    int columnas;

public:
    Matriz(int f = 0, int c = 0) : filas(f), columnas(c) {
        if (f > 0 && c > 0) {
            datos.resize(f, vector<T>(c, T{}));
        }
    }

    int getFilas() const { return filas; }
    int getColumnas() const { return columnas; }
    const vector<vector<T>>& getDatos() const { return datos; }

    void setElemento(int f, int c, T valor) {
        if (f >= 0 && f < filas && c >= 0 && c < columnas) {
            datos[f][c] = valor;
        }
    }

    Matriz<T> multiplicar(const Matriz<T>& otra) const {
        if (this->columnas != otra.filas) {
            throw invalid_argument("El numero de columnas de la primera matriz debe ser igual al numero de filas de la segunda matriz.");
        }

        int R_filas = this->filas;
        int R_columnas = otra.columnas;
        Matriz<T> resultado(R_filas, R_columnas);

        for (int i = 0; i < R_filas; ++i) {
            for (int j = 0; j < R_columnas; ++j) {
                T suma = T{};
                for (int k = 0; k < this->columnas; ++k) {
                    suma += this->datos[i][k] * otra.datos[k][j];
                }
                resultado.setElemento(i, j, suma);
            }
        }
        return resultado;
    }
};

#endif