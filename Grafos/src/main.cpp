#include "Grafo.hpp"

int main() {
    Grafo g(4);
    g.agregarArista(0, 1);
    g.agregarArista(0, 2);
    g.agregarArista(1, 2);
    g.agregarArista(2, 0);
    g.agregarArista(2, 3);
    g.agregarArista(3, 3);
    g.imprimir();
    return 0;
}