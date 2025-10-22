#ifndef OPERACIONESH
#define OPERACIONESH

#include <iostream>
using namespace std;
// LOGICA DE MODELO Y CONTROLADOR
class Operaciones {
private:
    int valor; // Dato que se maneja

public:
    // Constructor
    Operaciones(int v = 0);

    // Metodos de acceso (Getters y Setters)
    void setValor(int v);
    int getValor() const;

    // Obtener la direccion de memoria para el manejo con punteros
    int* getPointer();

    // Sobrecarga del operador + para sumar dos objetos Operaciones
    Operaciones operator+(const Operaciones& otro) const;

    // Metodo estatico para sumar tres valores usando sus punteros (Controlador)
    static int sumarConPunteros(int* p1, int* p2, int* p3);
    
    // Metodo estatico para realizar la suma usando la sobrecarga del operador (Controlador)
    static Operaciones sumarConSobrecarga(Operaciones& n1, Operaciones& n2, Operaciones& n3);
};

// LOGICA DE VISTA (Interaccion con el usuario)
class Vista {
public:
    // Muestra el resultado de la suma
    static void mostrarResultado(const string& titulo, int resultado);
    
    // Solicita tres valores por referencia
    static void pedirValores(int& v1, int& v2, int& v3);
};


#endif