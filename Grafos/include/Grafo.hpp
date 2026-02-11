#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <vector>
#include <list>

namespace listaAdyacente {

    class Grafo {

        private:
            int n;
            std::vector<std::list<int>> grafo;

        public:
            // Constructor
            Grafo(int n);
            // Destructor
            ~Grafo() = default;
            // Operaciones
            void agregarArista(int i, int n);
            void imprimir();
    };
    
}

namespace matrizAdyacente {

    class Grafo {

        private:
            int n;
            std::vector<std::vector<int>> grafo;
        
        public:
            Grafo(int n);
            ~Grafo() = default;
            void agregarArista(int i, int j);
            void imprimir();

    };

}

#endif