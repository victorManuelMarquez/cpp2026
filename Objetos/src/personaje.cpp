#include "personaje.hpp"

Personaje::Personaje(const int id, std::string nombre, int salud, int nivel, int fuerza) : id{id}, nombre{nombre}, salud{salud}, nivel{nivel}, fuerza(fuerza) {};

std::string Personaje::detalles() {
    return "ID: " + std::to_string(id) + ", Nombre: " + nombre + ", Salud: " + std::to_string(salud) + ", Nivel: " + std::to_string(nivel) + ", Fuerza: " + std::to_string(fuerza);
};

void Personaje::atacar(Personaje &objetivo, int danio) {
    objetivo.salud -= danio;
};