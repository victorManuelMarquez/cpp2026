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

namespace matrizAdyacente {

    Grafo::Grafo(int n) {
        this->n = n;
        grafo.resize(n, std::vector<int>(n, 0));
    };

    void Grafo::agregarArista(int i, int j) {
        grafo[i][j] = 1;
        grafo[j][i] = 1;
    }

    void Grafo::imprimir() {
        std::cout << "Matriz de Adyacencia: " << std::endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << grafo[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

}