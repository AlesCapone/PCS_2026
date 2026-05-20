#include <iostream>

#include "fifo.hpp"
#include "lifo.hpp"
#include "graph_visit.hpp"
#include "recursive_dfs.hpp"
#include "dijkstra.hpp"
#include "graphviz.hpp"

int main() {

    unidirected_graph<int> G;

    G.add_edge({1,2});
    G.add_edge({1,3});
    G.add_edge({2,4});
    G.add_edge({2,5});
    G.add_edge({3,6});

    fifo<int> q;
    auto bfs = graph_visit(G, 1, q);

    lifo<int> s;
    auto dfs = graph_visit(G, 1, s);

    auto rec = recursive_dfs(G, 1);

    auto dist = dijkstra(G, 1);

    std::cout << "Dijkstra:\n";
    for (auto [node,d] : dist)
        std::cout << node << ": " << d << "\n";

    to_dot(bfs, "bfs.dot");
    to_dot(dfs, "dfs.dot");
    to_dot(rec, "recursive_dfs.dot");

    std::cout << "Creati bfs.dot, dfs.dot, recursive_dfs.dot\n";

    return EXIT_SUCCESS;
}