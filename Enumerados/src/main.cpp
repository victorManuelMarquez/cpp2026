#include <iostream>
#include <string>
#include <array>
#include <cstdio>
#include <ctime>

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

// enumerado tipo clase
enum class meses {
    Enero = 1,
    Febrero,
    Marzo,
    Abril,
    Mayo,
    Junio,
    Julio,
    Agosto,
    Septiembre,
    Octubre,
    Noviembre,
    Diciembre
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

// retornar el valor de cada mes
std::string nombre(meses mes) {
    switch(mes) {
        case meses::Enero: return "Enero";
        case meses::Febrero: return "Febrero";
        case meses::Marzo: return "Marzo";
        case meses::Abril: return "Abril";
        case meses::Mayo: return "Mayo";
        case meses::Junio: return "Junio";
        case meses::Julio: return "Julio";
        case meses::Agosto: return "Agosto";
        case meses::Septiembre: return "Septiembre";
        case meses::Octubre: return "Octubre";
        case meses::Noviembre: return "Noviembre";
        case meses::Diciembre: return "Diciembre";
        default: return "Desconocido";
    }
}

inline int randomIndex(int value) {
    return std::rand() % value;
};

int main() {
    // semilla random
    std::srand(std::time({}));
    // muestro todos los valores
    for (auto dia : semana) {
        std::cout << "Día: " << aTexto(dia) << std::endl;
    }
    // Primer cuatrimestre
    std::array<meses, 3> trimestre = { meses::Enero, meses::Febrero, meses::Marzo };
    auto mes = trimestre[randomIndex(trimestre.size())];
    std::cout << "Mes aleatorio (primer cuatrimestre): " << nombre(mes) << std::endl;

    std::cout << "Fin del programa." << std::endl;
    return 0;
}