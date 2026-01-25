#ifndef PERSONA_HPP
#define PERSONA_HPP

#include <string>

class Persona {
    private:
        std::string nombre, apellido;
    
    public:
        Persona(std::string nombre, std::string apellido);
        virtual ~Persona() = default;
        virtual std::string info();
};

#endif