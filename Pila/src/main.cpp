#include <iostream>
#include <cstdlib>
#include <ctime>

// Definición de la estructura Nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
};

void poner(Nodo*& pila, int dato);
void sacar(Nodo*& pila);

int main() {
    std::srand(std::time({})); // Semilla para números aleatorios
    int total = 3 + (rand() % 8);
    Nodo* pila = nullptr; // Inicialización de la pila como vacía
    std::cout << "*** Pila Dinámica usando Punteros ***" << std::endl;
    std::cout << "______ Pila de " << total << " elementos  ______" << std::endl;
    for (int i = 0; i < total; i++) {
        int random = 1 + (rand() % 100); // Generar número aleatorio entre 1 y 100
        poner(pila, random); // Agregar el número a la pila
    }
    std::cout << ">>>>> VACIANDO LA PILA <<<<<" << std::endl;
    while (pila != nullptr) {
        sacar(pila); // Sacar elementos de la pila hasta que esté vacía
    }
    return 0;
}

void poner(Nodo*& pila, int dato) {
    Nodo* nuevo = new Nodo(); // Crear un nuevo nodo
    nuevo->dato = dato;       // Asignar el dato al nuevo nodo
    nuevo->siguiente = pila;  // Apuntar el nuevo nodo al tope actual
    pila = nuevo;             // Actualizar el tope de la pila
    std::cout << "Valor: " << dato << " agregado a la pila." << std::endl;
}

void sacar(Nodo*& pila) {
    if (pila == nullptr) {
        std::cout << "La pila está vacía, no se puede sacar ningún elemento." << std::endl;
        return;
    }
    Nodo* aux = pila;        // Guardar el nodo tope
    int dato = aux->dato;    // Obtener el dato del nodo tope
    pila = pila->siguiente;   // Actualizar el tope de la pila
    delete aux;              // Liberar la memoria del nodo sacado
    std::cout << "Valor: " << dato << " sacado de la pila." << std::endl;
}