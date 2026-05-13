#include <iostream>
#include <cstdlib>
#include "unidirected_graph.hpp"

int main() {

    unidirected_graph<int> g;

    g.add_edge({1,2});
    g.add_edge({2,3});
    g.add_edge({1,3});
	
	// test costruttore copia
    unidirected_graph<int> g2(g);
    if (g2.all_edges().size() != 3) {
        std::cerr << "Errore: costruttore copia\n";
        return EXIT_FAILURE;
    }

    // test vicini
    auto n = g.neighbours(1);
    if (!(n.contains(2) && n.contains(3))) {
        std::cerr << "Errore: neighbours\n";
        return EXIT_FAILURE;
    }

    // test nodi
    auto nodes = g.all_nodes();
    if (nodes.size() != 3) {
        std::cerr << "Errore: all_nodes\n";
        return EXIT_FAILURE;
    }

    // test archi
    auto edges = g.all_edges();
    if (edges.size() != 3) {
        std::cerr << "Errore: all_edges\n";
        return EXIT_FAILURE;
    }

    // test numero dell'arco
    if (g.edge_number({1,2}) != 0) {
        std::cerr << "Errore: edge_number\n";
        return EXIT_FAILURE;
    }

    // test arco dal numero
    if (!(g.edge_at(1) == unidirected_edge<int>(2,3))) {
        std::cerr << "Errore: edge_at\n";
        return EXIT_FAILURE;
    }

    
    // test differenza
    unidirected_graph<int> h;
    h.add_edge({1,2});

    auto diff = g - h;

    if (diff.all_edges().size() != 2) {
        std::cerr << "Errore: operator-\n";
        return EXIT_FAILURE;
    }

    std::cout << "Tutti i test passati\n";
    return EXIT_SUCCESS;
}