#ifndef ARITMETICA_HPP
#define ARITMETICA_HPP

#include <stdexcept>

namespace Aritmetica {

    template <typename T>
    T suma(T a, T b) {
        return a + b;
    }

    template <typename T>
    T resta(T a, T b) {
        return a - b;
    }
    
    template <typename T>
    T producto(T a, T b) {
        return a * b;
    }

    template <typename T>
    T division(T a, T b) {
        if (b == 0) {
            throw std::runtime_error("Error: división por 0");
        }
        return a / b;
    }

}
#endif