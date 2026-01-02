#include <iostream>
#include <string>

// variable global
/* NO SE RECOMIENDA EN PROYECTOS GRANDES */
int contadorGlobal = 100;

// variable constante
const double PI = 3.14159;

int foo() {
    static int calls = 0; // variable estatica
    calls++;
    std::cout << "La funcion foo ha sido llamada " << calls << " veces." << std::endl;
    return calls;
}

int main() {
    // variable local
    int edad = 32;
    std::string nombre = "Victor";
    
    std::cout << "Variables en C++" << std::endl;
    std::cout << "================" << std::endl;
    std::cout << "Contador global inicial: " << contadorGlobal << std::endl;
    std::cout << "Valor de PI: " << PI << std::endl;
    std::cout << "Nombre: " << nombre << ", Edad: " << edad << std::endl;
    foo();
    foo();
    foo();
    /* Apartir de c++ 11 */
    auto valor = foo() * contadorGlobal / PI; // deduccion de tipo
    std::cout << "Valor deducido (auto): " << valor << std::endl;
    return 0;
}