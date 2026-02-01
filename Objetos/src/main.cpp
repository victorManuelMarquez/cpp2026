#include <iostream>
#include <vector>
#include <persona.hpp>
#include <empleado.hpp>
#include <personaje.hpp>

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

    // Personajes
    Personaje heroe(1, "Heroe", 100, 1, 10);
    Personaje villano{ 2, "Villano", 110, 2, 11 }; // construcción uniforme

    std::cout << heroe.detalles() << std::endl;
    std::cout << villano.detalles() << std::endl;
    
    std::cout << heroe.getNombre() << " atacando a " << villano.getNombre() << std::endl;
    heroe.atacar(villano, heroe.getFuerza());
    std::cout << villano.detalles() << std::endl;

    std::cout << "Fin del programa." << std::endl;
    return 0;
}