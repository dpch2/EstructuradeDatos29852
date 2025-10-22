#include <iostream>
#include "Fraccion.h"
using namespace std;

int main() {
    int num1, den1, num2, den2;

    cout << "Ingrese el numerador de la primera fraccion: ";
    cin >> num1;
    cout << "Ingrese el denominador de la primera fraccion: ";
    cin >> den1;

    cout << "Ingrese el numerador de la segunda fraccion: ";
    cin >> num2;
    cout << "Ingrese el denominador de la segunda fraccion: ";
    cin >> den2;

    Fraccion f1(num1, den1);
    Fraccion f2(num2, den2);

    cout << "Fraccion 1: ";
    f1.mostrar();
    cout << "\nFraccion 2: ";
    f2.mostrar();

    Fraccion resultado = f1.multiplicar(f2);
    cout << "\nResultado de la multiplicacion: ";
    resultado.mostrar();
    cout << endl;

    return 0;
}
