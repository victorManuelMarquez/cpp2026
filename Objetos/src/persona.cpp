#include <persona.hpp>
#include <iostream>

Persona::Persona(std::string arg1, std::string arg2) : nombre(arg1), apellido(arg2) {};

std::string Persona::info() {
    return nombre + " " + apellido;
};