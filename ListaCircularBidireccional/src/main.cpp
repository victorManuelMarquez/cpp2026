#include <iostream>
#include <cstdio>
#include <ctime>

struct Nodo {
    int dato;
    Nodo* anterior;
    Nodo* siguiente;
};

void insertar(Nodo*& nodo, int valor, bool frente = false);
void mostrar(Nodo*& origen, bool reversa = false);
int quitar(Nodo*& nodo, bool reversa = false);
inline int generar(const int min = 0, const int max = 100) { return min + (rand() % (max - min + 1)); }

int main() {
    std::srand(std::time({}));
    Nodo* lista = nullptr;
    for (int i = 0; i < generar(5, 10); i++) {
        insertar(lista, generar());
    }
    insertar(lista, generar(), true);
    mostrar(lista);
    mostrar(lista, true);
    while (lista) {
        std::cout << lista;
        int valor = quitar(lista);
        std::cout << " -> " << valor << " eliminado." << std::endl;
    }
    return 0;
}

void insertar(Nodo*& origen, int valor, bool frente) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->anterior = nuevo->siguiente = nullptr;
    if (!origen) {
        nuevo->anterior = nuevo->siguiente = nuevo;
        origen = nuevo;
        return;
    }
    if (frente) {
        nuevo->siguiente = origen;
        nuevo->anterior= origen->anterior;
        nuevo->anterior->siguiente = nuevo;
        nuevo->siguiente->anterior = nuevo;
        origen = nuevo;
        return;
    }
    Nodo* nodo = origen;
    while (nodo->siguiente != origen) {
        nodo = nodo->siguiente;
    }
    nuevo->anterior = nodo;
    nuevo->siguiente = nodo->siguiente;
    nuevo->anterior->siguiente = nuevo;
    nuevo->siguiente->anterior = nuevo;
}

void mostrar(Nodo*& origen, bool reversa) {
    Nodo* nodo = reversa ? origen->anterior : origen;
    Nodo* tope = nodo;
    std::cout << (reversa ? "En reversa: " : "") << "[ ";
    do {
        int valor = nodo->dato;
        printf("(%p <- %p (%d) -> %p)\n", (void*)nodo->anterior, (void*)nodo, valor, (void*)nodo->siguiente);
        nodo = reversa ? nodo->anterior : nodo->siguiente;
    } while (nodo != tope);
    std::cout << "]" << std::endl;
}

int quitar(Nodo*& nodo, bool reversa) {
    if (!nodo) {
        std::cout << "Lista vacía!" << std::endl;
        return -1;
    }
    int valor = nodo->dato;
    Nodo* ant = nodo->anterior;
    Nodo* sig = nodo->siguiente;
    if (ant == nodo && sig == nodo) {
        ant = nullptr;
        sig = nullptr;
        delete nodo;
        nodo = nullptr;
    } else {
        Nodo* temp = nodo;
        if (reversa) {
            nodo = nodo->anterior;
        } else {
            nodo = nodo->siguiente;
        }
        ant->siguiente = sig;
        sig->anterior = ant;
        delete temp;
    }
    return valor;
}