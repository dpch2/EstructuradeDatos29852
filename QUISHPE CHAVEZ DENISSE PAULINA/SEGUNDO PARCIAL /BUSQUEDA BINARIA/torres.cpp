#include <iostream>
#include <cmath>
using namespace std;

// ESTRUCTURA DE DATOS: ARREGLOS DINÁMICOS (Dynamic Arrays)
// Usamos punteros y memoria dinámica con new/delete

// Función para encontrar el mínimo entre dos números
long long minimo(long long a, long long b) {
    return (a < b) ? a : b;
}

// Función para verificar si con radio r todas las ciudades tienen cobertura
bool canCover(long long* cities, int n, long long* towers, int m, long long r) {
    if (cities == NULL || towers == NULL) {
        return false;
    }
    
    for (int i = 0; i < n; i++) {
        // Encontrar la torre más cercana a esta ciudad
        long long minDist = 2000000000LL;
        bool foundTower = false;
        
        // Buscar en todas las torres
        for (int j = 0; j < m; j++) {
            long long diff = cities[i] - towers[j];
            long long dist = (diff < 0) ? -diff : diff; // valor absoluto
            
            if (dist < minDist) {
                minDist = dist;
                foundTower = true;
            }
        }
        
        // Si la torre más cercana está a más de r de distancia, no funciona
        if (!foundTower || minDist > r) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n, m;
    
    // Validación de entrada
    cout << "Ingrese n (ciudades) y m (torres): ";
    cin >> n >> m;
    
    if (n <= 0 || m <= 0 || n > 100000 || m > 100000) {
        cout << "Error: n y m deben estar entre 1 y 100000" << endl;
        return 1;
    }
    
    // MEMORIA DINÁMICA: Reservar espacio para arreglos
    long long* cities = new long long[n];
    long long* towers = new long long[m];
    
    // Validar que la memoria se asignó correctamente
    if (cities == NULL || towers == NULL) {
        cout << "Error: No se pudo asignar memoria" << endl;
        if (cities != NULL) delete[] cities;
        if (towers != NULL) delete[] towers;
        return 1;
    }
    
    // Leer coordenadas de ciudades
    cout << "Ingrese " << n << " coordenadas de ciudades: ";
    for (int i = 0; i < n; i++) {
        cin >> cities[i];
        if (cities[i] < -1000000000 || cities[i] > 1000000000) {
            cout << "Error: Coordenadas fuera de rango" << endl;
            delete[] cities;
            delete[] towers;
            return 1;
        }
    }
    
    // Leer coordenadas de torres
    cout << "Ingrese " << m << " coordenadas de torres: ";
    for (int i = 0; i < m; i++) {
        cin >> towers[i];
        if (towers[i] < -1000000000 || towers[i] > 1000000000) {
            cout << "Error: Coordenadas fuera de rango" << endl;
            delete[] cities;
            delete[] towers;
            return 1;
        }
    }
    
    // Binary search sobre el radio r
    long long left = 0;
    long long right = 2000000000LL; // Radio máximo posible
    long long answer = right;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        
        if (canCover(cities, n, towers, m, mid)) {
            answer = mid;
            right = mid - 1; // Intentar con un radio menor
        } else {
            left = mid + 1; // Necesitamos un radio mayor
        }
    }
    
    cout << "Radio minimo: " << answer << endl;
    
    // LIBERAR MEMORIA DINÁMICA
    delete[] cities;
    delete[] towers;
    
    return 0;
}

/*
ESTRUCTURA DE DATOS UTILIZADA: ARREGLOS DINÁMICOS (Dynamic Arrays)

- Se reserva memoria en tiempo de ejecución usando 'new'
- Se liberan usando 'delete[]'
- Acceso O(1) por índice
- Tamaño fijo una vez creado
- Memoria contigua en el heap

ALGORITMO: Binary Search (Búsqueda Binaria)
- Complejidad: O(n * m * log(max_coord))
- Busca el radio mínimo óptimo
*/

// cd torre
// g++ -std=c++11 -o torres.exe torres.cpp
// .\torres.exe