#include <iostream>
#include <persona.hpp>

int main() {
    Persona persona("Juan", "Perez");
    std::cout << persona.info() << std::endl;
    return 0;
}