#include <iostream>
#include <cstdlib>
#include <ctime>

struct Nodo {
    int dato;
    Nodo* siguiente;
};

inline int generar(const int min = 0, const int max = 100) { return (rand() % (max - min + 1)) + min; };

void insertar(Nodo*& root, int valor);
void mostrar(Nodo*& root);
int quitar(Nodo*& nodo);
void destruir(Nodo*& root);

int main() {
    srand(time({}));
    Nodo* root = nullptr;
    for (int i = 0; i < generar(3, 6); i++) {
        insertar(root, generar());
    }
    mostrar(root);
    destruir(root);
    return 0;
}

void insertar(Nodo*& root, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    if (!root) {
        nuevo->siguiente = nuevo;
        root = nuevo;
    } else {
        Nodo* nodo = root;
        while (nodo->siguiente != root) {
            nodo = nodo->siguiente;
        }
        nuevo->siguiente = root;
        nodo->siguiente = nuevo;
    }
}

void mostrar(Nodo*& root) {
    Nodo* nodo = root;
    std::cout << "[ (";
    do {
        std::cout << nodo << ") -> " << nodo->dato;
        nodo = nodo->siguiente;
        if (nodo == root) {
            std::cout << " ";
        } else {
            std::cout << ", ";
        }
    } while (nodo != root);
    std::cout << "]" << std::endl;
}

int quitar(Nodo*& nodo) {
    if (!nodo) {
        std::cout << "Nada que eliminar!" << std::endl;
        return -1;
    }
    int valor = nodo->dato;
    Nodo* temp = nodo;
    nodo = nodo->siguiente;
    delete temp;
    return valor;
}

void destruir(Nodo*& root) {
    Nodo* temp = root;
    while (temp->siguiente != root) {
        temp = temp->siguiente;
    }
    temp->siguiente = nullptr; // deshago la lista circular
    while (root) {
        std::cout << root << " -> ";
        int valor = quitar(root);
        std::cout << valor << " eliminado." << std::endl;
    }
}