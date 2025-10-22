#ifndef VISTAMATRIZ_H
#define VISTAMATRIZ_H

#include <iostream>
#include <string>
#include <iomanip>
#include "modeloMatriz.h" 

using namespace std;

template <typename T>
class VistaMatriz {
public:
    void mostrarMensaje(const string& mensaje) const {
        cout << mensaje << endl;
    }

    Matriz<T> solicitarDatos() {
        int filas, columnas;
        cout << "Ingrese numero de filas: ";
        cin >> filas;
        cout << "Ingrese numero de columnas: ";
        cin >> columnas;

        Matriz<T> matriz(filas, columnas);

        cout << "Ingrese valores para la matriz (" << filas << "x" << columnas << "):" << endl;
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                T valor;
                if (!(cin >> valor)) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    throw runtime_error("Entrada invalida para el valor de la matriz.");
                }
                matriz.setElemento(i, j, valor);
            }
        }
        return matriz;
    }

    void mostrarResultado(const Matriz<T>& resultado) const {
        cout << "\n--- Resultado de la Multiplicacion ---" << endl;
        int filas = resultado.getFilas();
        int columnas = resultado.getColumnas();
        const auto& datos = resultado.getDatos();

        for (int i = 0; i < filas; ++i) {
            cout << "| ";
            for (int j = 0; j < columnas; ++j) {
                cout << fixed << setprecision(2) << datos[i][j] << " ";
            }
            cout << "|" << endl;
        }
    }
};

#endif