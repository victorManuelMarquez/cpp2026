#include <iostream>
#include <memory>
#include <string>

class Demo {
    private:
        std::string nombre;
    public:
        Demo(std::string nombre) {
            this->nombre = nombre;
            std::cout << "Objeto " << nombre << " creado!" << std::endl;
        };
        ~Demo() {
            std::cout << "Objeto " << nombre << " destruído automáticamente!" << std::endl;
        };
        void info() {
            std::cout << nombre << " " << "(" << this << ")" << std::endl;
        };
};

int main() {
    // objeto único (no se puede copiar)
    std::unique_ptr<Demo> demoPtr = std::make_unique<Demo>("único");
    demoPtr->info();
    // varios punteros apuntarán al objeto (se liberan de la memoria al salir del bloque).
    std::shared_ptr<Demo> sharedDemo = std::make_shared<Demo>("compartido");
    {
        std::shared_ptr<Demo> demoPlus = sharedDemo;
        std::cout << "puntero compartido dentro del bloque: ";
        demoPlus.get()->info();
        std::cout << "Referencias totales: " << demoPlus.use_count() << std::endl;
    }
    // el puntero observador permite "mirar" o comprobar sí el puntero compartido
    // aún existe sin crear otro puntero que preserve la refrencia en memoria (fuga de memoria)
    std::weak_ptr<Demo> weakDemo = sharedDemo;
    if (auto observador = weakDemo.lock()) {
        std::cout << "observador: ";
        observador->info();
    } else {
        std::cout << "El Objeto ha sido destruído." << std::endl;
    }
    return 0;
}