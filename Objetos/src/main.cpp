#include <iostream>
#include <persona.hpp>
#include <empleado.hpp>

int main() {
    Persona persona("Juan", "Perez");
    std::cout << persona.info() << std::endl;
    Empleado empleado("Ana", "Sosa", "Secretaria");
    std::cout << empleado.info() << std::endl;
    return 0;
}