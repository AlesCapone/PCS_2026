#pragma once
#include <fstream>
#include "unidirected_graph.hpp"

template<typename T>
void to_dot(const unidirected_graph<T>& G, const std::string& filename){
    std::ofstream out(filename);

    out << "graph G {\n";

    for (auto e : G.all_edges()) {
        out << "  " << e.from() << " -- " << e.to() << ";\n";
    }

    out << "}\n";
}