#include <iostream>
#include <string>

// Declaración de funciones
// método (función que no devuelve nada)
void sumar(int a, int b); // usando paso por valor
// función recursiva
unsigned long long factorial(int &n); // usando paso por referencia
// función plantilla
template<typename T>
T minimo(T a, T b) {
    return (a < b) ? a : b;
}
// función inline
inline int cuadrado(int x) { return x * x; }

int main() {
    sumar(5, 7); // Llamada a la función
    int numero = 4;
    std::cout << "El factorial de " << numero << " es: " << factorial(numero) << std::endl;
    // Uso de una función lambda
    auto producto = [](int x, int y) { return x * y; };
    std::cout << "El producto de 3 y 4 es: " << producto(3, 4) << std::endl;
    // Uso de la función plantilla
    std::cout << "El mínimo entre 10 y 20 es: " << minimo(10, 20) << std::endl;
    // Uso de la función inline
    std::cout << "El cuadrado de 6 es: " << cuadrado(6) << std::endl;
    return 0;
}

// Definición de la función
void sumar(int a, int b) {
    int resultado = a + b;
    std::cout << "La suma de " << a << " y " << b << " es: " << resultado << std::endl;
}

unsigned long long factorial(int &n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(--n);
}