#include <iostream>
#include <string>

// Declaración de funciones
// método (función que no devuelve nada)
void sumar(int a, int b); // usando paso por valor
// función recursiva
unsigned long long factorial(int &n); // usando paso por referencia

int main() {
    sumar(5, 7); // Llamada a la función
    int numero = 4;
    std::cout << "El factorial de " << numero << " es: " << factorial(numero) << std::endl;
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