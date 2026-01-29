#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP

#include <string>

class Personaje {
    private:
        int id;
        std::string nombre;
    public:
        Personaje(const int id, std::string nombre);
        virtual ~Personaje() = default;
        virtual std::string detalles();
};

#endif