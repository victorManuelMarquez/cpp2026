#include <iostream>
#include <cstdlib>
#include <ctime>

struct Nodo {
    int dato;
    Nodo* siguiente;
};

struct Lista {
    int totalItems;
    Nodo* cabeza;
};

void insertar(Lista*& lista, int dato);
int quitar(Nodo*& elemento);
void mostrar(Lista*& lista);
void vaciar(Lista*& lista);
inline int generar(int min=5, int max=20) { return (rand() % (max - min + 1)) + min; };

int main() {
    std::srand(std::time({}));
    Lista* lista = new Lista();
    lista->cabeza = nullptr;
    lista->totalItems = 0;
    for (int i=0; i<generar(); i++) {
        insertar(lista, generar(1, 100));
    }
    mostrar(lista);
    vaciar(lista);
    delete lista;
    return 0;
}

void insertar(Lista*& lista, int dato) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = dato;
    nuevo->siguiente = nullptr;
    if (lista) {
        Nodo* nodo = lista->cabeza;
        lista->totalItems++;
        if (!nodo) {
            lista->cabeza = nuevo;
            return;
        } else {
            while (nodo->siguiente) {
                nodo = nodo->siguiente;
            }
            nodo->siguiente = nuevo;
        }
    }
}

int quitar(Nodo*& elemento) {
    if (elemento == nullptr) {
        std::cout << elemento->dato << " quitado de la lista." << std::endl;
        return -1;
    }
    Nodo* temp = elemento;
    int valor = temp->dato;
    elemento = temp->siguiente;
    delete temp;
    return valor;
}

void mostrar(Lista*& lista) {
    if (!lista) {
        std::cout << "Lista sin iniciar!" << std::endl;
        return;
    }
    if (!lista->cabeza) {
        std::cout << "Lista vacía. ( " << lista->totalItems << " ) elementos." << std::endl;
        return;
    }
    Nodo* nodo = lista->cabeza;
    std::cout << "Lista: [ ";
    do {
        std::cout << nodo->dato;
        nodo = nodo->siguiente;
        if (nodo) {
            std::cout << ", ";
        }
    } while (nodo);
    std::cout << " ] ( " << lista->totalItems << " ) elementos." << std::endl;
}

void vaciar(Lista*& lista) {
    while(lista->cabeza) {
        int valor = quitar(lista->cabeza);
        std::cout << valor << " eliminado de la lista." << std::endl;
    }
    mostrar(lista);
}