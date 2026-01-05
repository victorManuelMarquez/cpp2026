#include <iostream>
#include <string>
#include <random>
#include <iomanip>

struct Personaje {
    // atributos
    std::string nombre;
    int nivel;
    float* salud;
    
    // constructor
    Personaje(std::string n, int lvl, float h) {
        nombre = n;
        nivel = lvl;
        salud = new float(h);
    }

    // destructor
    ~Personaje() {
        delete salud;
        std::cout << "Destructor llamado para " << nombre << std::endl;
    }

    void mostrarInfo() {
        std::cout << "Nombre: " << nombre << ", Nivel: " << nivel << ", Salud: " << *salud << std::endl;
    }

    void subirNivel() {
        nivel++;
    }
};

void curar(Personaje* p) {
    if (p) {
        *(p->salud) = 100.0f;
        std::cout << p->nombre << " ha sido curado a plena salud." << std::endl;
    }
}

void herir(Personaje* p, float d) {
    if (p) {
        *(p->salud) -= d;
        // Asegurar que la salud no sea negativa
        if (*(p->salud) < 0) {
            *(p->salud) = 0;
            std::cout << p->nombre << " ha muerto." << std::endl;
        } else {
            std::cout << p->nombre << " ha recibido " << std::fixed << std::setprecision(1) << d << " de daño." << std::endl;
        }
    }
}

int main() {
    std::random_device random;
    std::mt19937 generator(random());
    std::uniform_real_distribution<float> distribution(5.0f, 100.0f);
    auto d = distribution(generator);
    Personaje heroe("Ragnar", 5, 100.0f);
    heroe.mostrarInfo();
    herir(&heroe, d);
    heroe.subirNivel();
    curar(&heroe);
    heroe.mostrarInfo();
    return 0;
}