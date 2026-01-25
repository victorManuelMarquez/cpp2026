#include "empleado.hpp"

Empleado::Empleado(std::string nombre, std::string apellido, std::string puesto)
    :Persona(nombre, apellido), puesto(puesto) {};
std::string Empleado::info() {
    return "Empleado: " + Persona::info() + " - Puesto: " + puesto;
};