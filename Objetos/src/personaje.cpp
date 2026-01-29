#include "personaje.hpp"

Personaje::Personaje(const int id, std::string nombre) : id{id}, nombre{nombre} {};

std::string Personaje::detalles() {
    return "ID: " + std::to_string(id) + ", Nombre: " + nombre;
};