#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

// Definición de la estructura Nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
};

struct Pila {
    int totalElementos;
    Nodo* tope;
};

void poner(Pila*& pila, int dato);
void sacar(Pila*& pila);
void mostrar(Pila*& pila);
inline auto salida(int valor) { return (valor != 1) ? "elementos" : "elemento"; };

int main() {
    std::srand(std::time({})); // Semilla para números aleatorios
    int total = 3 + (rand() % 8);

    // Inicialización de la pila como vacía
    Pila* pila = new Pila();
    pila->tope = nullptr;
    pila->totalElementos = 0;

    std::cout << "*** Pila Dinámica usando Punteros ***" << std::endl;
    for (int i = 0; i < total; i++) {
        int random = 1 + (rand() % 100); // Generar número aleatorio entre 1 y 100
        poner(pila, random); // Agregar el número a la pila
    }
    mostrar(pila);
    std::cout << ">>>>> VACIANDO LA PILA <<<<<" << std::endl;
    while (pila->tope) {
        sacar(pila); // Sacar elementos de la pila hasta que esté vacía
    }
    mostrar(pila);
    delete pila;
    return 0;
}

void poner(Pila*& pila, int dato) {
    if (!pila) {
        std::cout << "Pila sin iniciar!" << std::endl;
        return;
    }
    Nodo* nuevo = new Nodo(); // Crear un nuevo nodo
    nuevo->dato = dato;       // Asignar el dato al nuevo nodo
    nuevo->siguiente = pila->tope;  // Apuntar el nuevo nodo al tope actual
    pila->tope = nuevo;             // Actualizar el tope de la pila
    pila->totalElementos++;
    std::cout << nuevo->dato << " agregado a la pila." << std::endl;
}

void sacar(Pila*& pila) {
    if (pila == nullptr) {
        mostrar(pila);
        return;
    }
    Nodo* aux = pila->tope;        // Guardar el nodo tope
    int dato = aux->dato;    // Obtener el dato del nodo tope
    pila->tope = aux->siguiente;   // Actualizar el tope de la pila
    pila->totalElementos--;
    delete aux;              // Liberar la memoria del nodo sacado
    std::cout << "Removido: " << dato << std::endl;
}

void mostrar(Pila*& pila) {
    if (!pila) {
        std::cout << "Pila sin iniciar!" << std::endl;
        return;
    }
    if (!pila->tope) {
        std::cout << "Pila vacía." << std::endl;
        return;
    }
    Nodo* tope = pila->tope;
    std::cout << "_______________TOPE_______________\n" << std::endl;
    do {
        std::cout << "\t\t" << tope->dato << std::endl;
        tope = tope->siguiente;
    } while (tope);
    std::cout << "__________________________________\n" << std::endl;
    std::cout << pila->totalElementos << " " << salida(pila->totalElementos) << "." << std::endl;
}