#include <iostream>
#include "Operaciones.h" 
using namespace std; 

int main() {
    // 1. Declaracion de Modelos (Objetos de la clase Operaciones) y variables de entrada
    Operaciones n1, n2, n3;
    int v1, v2, v3;

    // 2. Vista pide valores
    Vista::pedirValores(v1, v2, v3);

    // 3. Modelo asigna valores
    n1.setValor(v1);
    n2.setValor(v2);
    n3.setValor(v3);

    // CASO 1: Suma explicita usando PUNTEROS
    // Se pasa la direccion de memoria para que el Controlador (Operaciones::sumarConPunteros)
    // acceda al valor mediante desreferencia (*p).
    int resultadoPunteros = Operaciones::sumarConPunteros(
        n1.getPointer(), // Puntero al valor interno de n1
        n2.getPointer(), // Puntero al valor interno de n2
        n3.getPointer()  // Puntero al valor interno de n3
    );

    // 4. Vista muestra el resultado
    Vista::mostrarResultado("Suma con Punteros ", resultadoPunteros);

    // CASO 2: Suma usando SOBRECARGA DEL OPERADOR +
    // El Controlador usa la sobrecarga del Modelo para sumar.
    Operaciones resultadoObjeto = Operaciones::sumarConSobrecarga(n1, n2, n3);

    // 5. Vista muestra el resultado
    Vista::mostrarResultado("Suma con Sobrecarga del Operador +", resultadoObjeto.getValor());
    
    cout << "\n--- FIN DE LA EJECUCION ---\n" << endl;
    return 0;
}
