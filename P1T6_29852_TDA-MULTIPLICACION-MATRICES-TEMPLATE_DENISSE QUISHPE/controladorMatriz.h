#ifndef CONTROLADORMATRIZ_H
#define CONTROLADORMATRIZ_H

#include <vector>
#include <stdexcept>
#include "vistaMatriz.h" 

using namespace std;

template <typename T>
class ControladorMatriz {
private:
    vector<Matriz<T>> matrices;
    Matriz<T> resultado;

public:
    void agregarMatriz(const Matriz<T>& matriz) {
        matrices.push_back(matriz);
    }

    void multiplicarTodas() {
        if (matrices.empty()) {
            throw runtime_error("No se han ingresado matrices para multiplicar.");
        }

        resultado = matrices[0];

        for (size_t i = 1; i < matrices.size(); ++i) {
            resultado = resultado.multiplicar(matrices[i]);
        }
    }

    void mostrarResultado(const VistaMatriz<T>& vista) const {
        vista.mostrarResultado(resultado);
    }
};

#endif