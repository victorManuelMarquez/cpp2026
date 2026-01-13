#include <iostream>
#include <cstdlib>
#include <ctime>

struct Nodo {
    int dato;
    Nodo* anterior;
    Nodo* siguiente;
};

struct ListaBidireccional {
    int totalItems;
    Nodo* cabeza;
    Nodo* cola;
};

ListaBidireccional* crearLista();
void insertar(ListaBidireccional*& lista, int valor, bool enCabecera = false);
Nodo* crearNodo(int valor);
void mostrar(ListaBidireccional*& lista, bool reversa = false);
void destruir(ListaBidireccional*& lista, bool reversa = false);
inline int generar(int min = 0, int max = 100) { return (rand() % (max - min + 1)) + min; };

int main() {
    std::srand(std::time({}));
    ListaBidireccional* lista = crearLista();
    for (int i = 0; i < generar(5, 10); i++) {
        insertar(lista, generar());
    }
    insertar(lista, generar(), true);
    mostrar(lista, true);
    destruir(lista);
    return 0;
}

ListaBidireccional* crearLista() {
    ListaBidireccional* lista = new ListaBidireccional();
    lista->totalItems = 0;
    lista->cabeza = lista->cola = nullptr;
    return lista;
}

void insertar(ListaBidireccional*& lista, int valor, bool enCabecera) {
    Nodo* nuevo = crearNodo(valor);
    if (!lista) {
        lista = crearLista();
    }
    if (!lista->cabeza) {
        lista->cabeza = nuevo;
    }
    if (!lista->cola) {
        lista->cola = nuevo;
    }
    std::cout << (enCabecera ? "HEAD " : "TAIL ") << " -> ";
    if (enCabecera) {
        Nodo* cabeza = lista->cabeza;
        if (cabeza != nuevo) {
            nuevo->siguiente = cabeza;
            cabeza->anterior = nuevo;
            lista->cabeza = nuevo;
        }
    } else {
        Nodo* cola = lista->cola;
        if (cola != nuevo) {
            nuevo->anterior = cola;
            cola->siguiente = nuevo;
            lista->cola = nuevo;
        }
    }
    lista->totalItems++;
    std::cout << nuevo->dato <<std::endl;
}

Nodo* crearNodo(int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->anterior = nullptr;
    nuevo->siguiente = nullptr;
    return nuevo;
}

void mostrar(ListaBidireccional*& lista, bool reversa) {
    if (!lista) {
        std::cout << "Lista vacía." << std::endl;
        return;
    }
    std::cout << (reversa ? "Lista en reversa: " : "");
    Nodo* nodo = reversa ? lista->cola : lista->cabeza;
    std::cout << "[";
    while (nodo) {
        std::cout << nodo->dato;
        if (reversa) {
            nodo = nodo->anterior;
        } else {
            nodo = nodo->siguiente;
        }
        if (nodo) {
            std::cout << ", ";
        }
    }
    std::cout << "] (" << lista->totalItems << ") elementos." << std::endl;
}

void destruir(ListaBidireccional*& lista, bool reversa) {
    Nodo* nodo = reversa ? lista->cola : lista->cabeza;
    std::cout << (reversa ? "Vaciando la lista en reversa..." : "Vaciando la lista...") << std::endl;
    while (nodo) {
        int valor = nodo->dato;
        Nodo* temp = nodo;
        std::cout << temp << " -> ";
        if (reversa) {
            nodo = temp->anterior;
            if (nodo) {
                nodo->siguiente = nullptr;
            } else {
                lista->cabeza = nodo;
            }
            lista->cola = nodo;
        } else {
            nodo = temp->siguiente;
            if (nodo) {
                nodo->anterior = nullptr;
            } else {
                lista->cola = nodo;
            }
            lista->cabeza = nodo;
        }
        delete temp;
        lista->totalItems--;
        std::cout << valor << " eliminado. (" << lista->totalItems << ") elementos restantes." << std::endl;
    }
    std::cout << lista << " -> ";
    delete lista;
    std::cout << "Lista eliminada!" << std::endl;
}