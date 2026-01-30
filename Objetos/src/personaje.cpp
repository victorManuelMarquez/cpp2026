#include "personaje.hpp"

Personaje::Personaje(const int id, std::string nombre, int salud, int nivel) : id{id}, nombre{nombre}, salud{salud}, nivel{nivel} {};

std::string Personaje::detalles() {
    return "ID: " + std::to_string(id) + ", Nombre: " + nombre + ", Salud: " + std::to_string(salud) + ", Nivel: " + std::to_string(nivel);
};