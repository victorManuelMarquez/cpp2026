#ifndef ARITMETICA_HPP
#define ARITMETICA_HPP

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
        return a / b;
    }

}
#endif