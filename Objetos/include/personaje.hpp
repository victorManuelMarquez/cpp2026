#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP

#include <string>

class Personaje {
    private:
        int id;
        std::string nombre;
        int salud;
        int nivel;
        int fuerza;
    public:
        Personaje(const int id, std::string nombre, int salud, int nivel, int fuerza);
        virtual ~Personaje() = default;
        virtual std::string detalles();
        std::string getNombre() const { return nombre; }
        int getSalud() const { return salud; }
        int getNivel() const { return nivel; }
        int getFuerza() const { return fuerza; }
        void setFuerza(int fuerza) { this->fuerza = fuerza; }
        void atacar(Personaje &objetivo, int danio);
};

#endif