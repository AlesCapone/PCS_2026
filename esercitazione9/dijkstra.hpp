#pragma once
#include <map>
#include <queue>
#include <vector>
#include <limits>
#include "unidirected_graph.hpp"

template<typename T>
std::map<T,int>
dijkstra(const unidirected_graph<T>& G,const T& source){
    std::map<T,int> dist;

    for (const auto& n : G.all_nodes())
        dist[n] = std::numeric_limits<int>::max();

    dist[source] = 0;

    std::priority_queue<std::pair<int,T>, std::vector<std::pair<int,T>>, std::greater<>> pq;

    pq.push({0, source});

    while (!pq.empty()) {

        auto [d,u] = pq.top();
        pq.pop();

        for (auto v : G.neighbours(u)) {

            if (dist[v] > d + 1) {

                dist[v] = d + 1;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}