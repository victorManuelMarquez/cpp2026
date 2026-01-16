#include <iostream>
#include <string>

using std::string;

class Persona {
    public:
        string nombre, apellido;
    
    public:
        string info() {
            return nombre + " " + apellido;
        }
};

int main() {
    Persona persona;
    persona.nombre = "Juan";
    persona.apellido = "Perez";
    std::cout << persona.info() << std::endl;
    return 0;
}