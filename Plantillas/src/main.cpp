#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
T suma(const T x, const T y) {
    return x + y;
};

template <typename T>
T generar(const T min, const T max) {
    return min + (rand() % (max - min + 1));
};

int main() {
    std::srand(std::time({}));
    auto x = generar(1, 5);
    auto y = generar(0, 42);
    std::cout << x << " + " << y << " = " << suma(x, y) << std::endl;
    return 0;
}