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

    matrizAdyacente::Grafo matrizAdyacente(5);
    matrizAdyacente.agregarArista(0, 1);
    matrizAdyacente.agregarArista(0, 4);
    matrizAdyacente.agregarArista(1, 2);
    matrizAdyacente.agregarArista(1, 3);
    matrizAdyacente.agregarArista(1, 4);
    matrizAdyacente.agregarArista(2, 3);
    matrizAdyacente.agregarArista(3, 4);
    matrizAdyacente.imprimir();
    
    return 0;
}