#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "aritmetica.hpp"

// alias para simplificar o describir los módulos importados
namespace calculo = Aritmetica;

inline int generar(int max = 100) { return rand() % max + 1; };

int main() {
    std::srand(std::time({}));
    int x = generar();
    int y = generar();
    std::cout << "suma: " << x << " + " << y << " = " << calculo::suma(x, y) << std::endl;
    x = generar();
    y = generar();
    std::cout << "suma: " << x << " - " << y << " = " << calculo::resta(x, y) << std::endl;
    x = generar();
    y = generar();
    std::cout << "División: " << x << " / " << y << " = ";
    try {
        std::cout << std::fixed << std::setprecision(2) << calculo::division<float>(x, y) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    x = generar();
    y = generar();
    std::cout << "suma: " << x << " * " << y << " = " << calculo::producto(x, y) << std::endl;
    std::cout << "Fin del programa." << std::endl;
    return 0;
}