#include <iostream>
#include <vector>
#include <persona.hpp>
#include <empleado.hpp>

int main() {
    // vector para almacenar la colección de Persona
    std::vector<Persona*> gente;

    // instancio las clases
    gente.push_back(new Persona("Juan", "Perez"));
    gente.push_back(new Empleado("Ana", "Lopez", "Ejecutivo"));
    gente.push_back(new Empleado("Lucía", "Cruz", "Secretaria"));

    // Polimorfismo en acción
    for (Persona* p : gente) {
        std::cout << p->info() << std::endl;
    }

    // elimino las instancias
    for (Persona* p : gente) {
        delete p;
    }
    std::cout << "Fin del programa." << std::endl;
    return 0;
}