#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP

#include "persona.hpp"

class Empleado : public Persona {
    private: std::string puesto;

    public:
        Empleado(std::string nombre, std::string apellido, std::string puesto);
        std::string info() override;
};

#endif