#pragma once
#include <set>
#include "unidirected_graph.hpp"

template<typename T>
void dfs_helper(const unidirected_graph<T>& G, const T& node, std::set<T>& visited, unidirected_graph<T>& result){
    visited.insert(node);

    for (const auto& neigh : G.neighbours(node)) {

        if (!visited.contains(neigh)) {

            result.add_edge(
                unidirected_edge<T>(node, neigh)
            );

            dfs_helper(G, neigh, visited, result);
        }
    }
}

template<typename T>
unidirected_graph<T>
recursive_dfs(const unidirected_graph<T>& G, const T& source){
    std::set<T> visited;
    unidirected_graph<T> result;

    dfs_helper(G, source, visited, result);

    return result;
}