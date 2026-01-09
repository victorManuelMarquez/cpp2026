#include <iostream>
#include <cstdlib>
#include <ctime>

struct Nodo {
    int valor;
    Nodo* siguiente;
};

struct Cola {
    Nodo* inicio;
    Nodo* final;

    Cola() {
        inicio = nullptr;
        final = nullptr;
    }
};

void insertar(Cola &c, int valor);
void quitar(Cola &c);
void vaciar(Cola &c);
inline int generar(int min = 0, int max = 10) { return (rand() % (max - min + 1)) + min; };

int main() {
    std::srand(time({}));
    Cola cola;
    for (int i=0; i<generar(3, 15); i++) {
        insertar(cola, generar());
    }
    vaciar(cola);
    return 0;
}

void insertar(Cola &c, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->valor = valor;
    nuevo->siguiente = nullptr;
    if (c.inicio == nullptr) {
        c.inicio = nuevo;
    } else {
        c.final->siguiente = nuevo;
    }
    c.final = nuevo;
    std::cout << valor << " insertado." << std::endl;
}

void quitar(Cola &c) {
    if (c.inicio == nullptr) {
        std::cout << "La cola no tiene elementos.";
        return;
    }
    Nodo* temp = c.inicio;
    int valor = temp->valor;
    c.inicio = temp->siguiente;
    if (c.inicio == nullptr) {
        c.final == nullptr;
    }
    delete temp;
    std::cout << valor << " se ha quitado de la cola." << std::endl;
}

void vaciar(Cola &c) {
    while (c.inicio != nullptr) {
        quitar(c);
    }
    std::cout << "Cola vacía." << std::endl;
}