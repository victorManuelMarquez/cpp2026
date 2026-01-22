#include <iostream>
#include "aritmetica.hpp"

// alias para simplificar o describir los módulos importados
namespace calculo = Aritmetica;

int main() {
    std::cout << "suma: 10 + 23 = " << calculo::suma(10, 23) << std::endl;
    std::cout << "División: 4 / 0 = ";
    try {
        std::cout << calculo::division(4, 0) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "Fin del programa." << std::endl;
    return 0;
}