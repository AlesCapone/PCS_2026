#pragma once
#include <set>
#include "unidirected_graph.hpp"

template<typename T, typename Container>
unidirected_graph<T>
graph_visit(const unidirected_graph<T>& G, const T& source, Container c){
    std::set<T> visited;
    unidirected_graph<T> result;

    visited.insert(source);
    c.put(source);

    while (!c.empty()) {

        T current = c.get();

        for (const auto& neigh : G.neighbours(current)) {

            if (!visited.contains(neigh)) {

                visited.insert(neigh);

                result.add_edge(
                    unidirected_edge<T>(current, neigh)
                );

                c.put(neigh);
            }
        }
    }

    return result;
}