#include <iostream>
#include "aritmetica.hpp"

// alias para simplificar o describir los módulos importados
namespace calculo = Aritmetica;

int main() {
    std::cout << "suma: 10 + 23 = " << calculo::suma(10, 23) << std::endl;
    return 0;
}