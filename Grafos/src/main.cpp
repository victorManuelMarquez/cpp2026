#include <iostream>
#include <vector>
#include <list>

class Grafo {

    private:
        int n;
        std::vector<std::list<int>> grafo;
    
    public:
        // Constructor
        Grafo(int n) {
            this->n = n;
            grafo.resize(n);
        }

        // Destructor
        ~Grafo() = default;

        void agregarArista(int i, int n) {
            grafo[i].push_back(n);
        }

        void imprimir() {
            for (int i = 0; i < n; i++) {
                std::cout << "Nodo: " << i << " conectado con: ";
                for (int v : grafo[i]) {
                    std::cout << v << " ";
                }
                std::cout << std::endl;
            }
        }
};

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