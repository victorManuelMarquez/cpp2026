#include <iostream>
#include <string>
#include <array>

// enumerado
enum dias {
    Lunes = 1,
    Martes,
    Miercoles,
    Jueves,
    Viernes,
    Sabado,
    Domingo
};

// debido a que iterar un enum no es posible, se emplea un array
std::array<dias, 7> semana = { dias::Lunes, dias::Martes, dias::Miercoles, dias::Jueves, dias::Viernes, dias::Sabado, dias::Domingo };

// conversor del valor entero a cadena
std::string aTexto(dias valor) {
    switch (valor) {
        case dias::Lunes: return "Lunes";
        case dias::Martes: return "Martes";
        case dias::Miercoles: return "Miercoles";
        case dias::Jueves: return "Jueves";
        case dias::Viernes: return "Viernes";
        case dias::Sabado: return "Sabado";
        case dias::Domingo: return "Domingo";
        default: return "Desconocido";
    }
}

int main() {
    // muestro todos los valores
    for (auto dia : semana) {
        std::cout << "Día: " << aTexto(dia) << std::endl;
    }
    std::cout << "Fin del programa." << std::endl;
    return 0;
}