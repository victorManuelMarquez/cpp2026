#include <iostream>
#include <cstdlib>
#include <ctime>

struct Nodo {
    int dato;
    Nodo* siguiente;
};

void insertar(Nodo*& elemento, int dato);
int quitar(Nodo*& elemento);
void mostrar(Nodo*& lista);
void vaciar(Nodo*& lista);
inline int generar(int min=5, int max=20) { return (rand() % (max - min + 1)) + min; };

int main() {
    std::srand(std::time({}));
    Nodo* lista = nullptr;
    for (int i=0; i<generar(); i++) {
        insertar(lista, generar(1, 100));
    }
    mostrar(lista);
    vaciar(lista);
    return 0;
}

void insertar(Nodo*& lista, int dato) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = dato;
    nuevo->siguiente = nullptr;
    if (lista == nullptr) {
        lista = nuevo;
    } else {
        Nodo* nodo = lista;
        while (nodo->siguiente != nullptr) {
            nodo = nodo->siguiente;
        }
        nodo->siguiente = nuevo;
    }
}

int quitar(Nodo*& elemento) {
    if (elemento == nullptr) {
        mostrar(elemento);
        return -1;
    }
    Nodo* temp = elemento;
    int valor = temp->dato;
    elemento = temp->siguiente;
    delete temp;
    return valor;
}

void mostrar(Nodo*& lista) {
    int total = 0;
    if (!lista) {
        std::cout << "Lista vacía. ( " << total << " ) elementos." << std::endl;
        return;
    }
    Nodo* nodo = lista;
    std::cout << "Lista: [ ";
    do {
        std::cout << nodo->dato;
        nodo = nodo->siguiente;
        total++;
        if (nodo) {
            std::cout << ", ";
        }
    } while (nodo);
    std::cout << " ] ( " << total << " ) elementos." << std::endl;
}

void vaciar(Nodo*& lista) {
    while(lista) {
        int valor = quitar(lista);
        std::cout << valor << " eliminado de la lista." << std::endl;
    }
    mostrar(lista);
}