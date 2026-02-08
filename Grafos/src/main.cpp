#include "Grafo.hpp"

int main() {
    listaAdyacente::Grafo listaAdyacente(4);
    listaAdyacente.agregarArista(0, 1);
    listaAdyacente.agregarArista(0, 2);
    listaAdyacente.agregarArista(1, 2);
    listaAdyacente.agregarArista(2, 0);
    listaAdyacente.agregarArista(2, 3);
    listaAdyacente.agregarArista(3, 3);
    listaAdyacente.imprimir();
    return 0;
}