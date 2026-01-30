#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP

#include <string>

class Personaje {
    private:
        int id;
        std::string nombre;
        int salud;
        int nivel;
    public:
        Personaje(const int id, std::string nombre, int salud, int nivel);
        virtual ~Personaje() = default;
        virtual std::string detalles();
        std::string getNombre() const { return nombre; }
        int getSalud() const { return salud; }
        int getNivel() const { return nivel; }
};

#endif