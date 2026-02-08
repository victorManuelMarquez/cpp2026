#include <iostream>
#include "Grafo.hpp"

namespace listaAdyacente {

    Grafo::Grafo(int n) {
        this->n = n;
        grafo.resize(n);
    };

    void Grafo::agregarArista(int i, int n) {
        grafo[i].push_back(n);
    }

    void Grafo::imprimir() {
        for (int i = 0; i < n; i++) {
            std::cout << "Nodo: " << i << " conectado con: ";
            for (int v : grafo[i]) {
                std::cout << v << " ";
            }
            std::cout << std::endl;
        }
    }

}