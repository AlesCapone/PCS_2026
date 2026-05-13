#pragma once
#include <map>
#include <set>
#include <list>
#include <cassert>
#include "unidirected_edge.hpp"

template<typename T>
class unidirected_graph {
private:
    std::map<T, std::set<T>> La;
    std::list<unidirected_edge<T>> edges;

public:

    // costruttore default
    unidirected_graph() = default;

    // costruttore copia
    unidirected_graph(const unidirected_graph&) = default;

		
   // aggiungi arco
    void add_edge(const unidirected_edge<T>& e) {

        if (La.count(e.from()) && La.at(e.from()).contains(e.to()))
			return;

        La[e.from()].insert(e.to());
        La[e.to()].insert(e.from());

        edges.push_back(e);
    }
	
// vicini 
    std::set<T> neighbours(const T& node) const {

        auto it = La.find(node);

        if (it == La.end())
            return {};

        auto const& [n, neigh] = *it;
		
		return neigh;
		}
		 
    // tutti gli archi
    std::list<unidirected_edge<T>> all_edges() const {
		return edges;
	}
	
	// tutti i nodi
    std::set<T> all_nodes() const {

        std::set<T> all;

        for (auto const& [node, _] : La)
            all.insert(node);

        return all;
    }

    // numero dell’arco
    std::size_t edge_number(const unidirected_edge<T>& e) const {
    std::size_t i = 0;

    for (const auto& edge : edges) {
        if (edge == e)
            return i;
        ++i;
    }

    assert(false && "arco non trovato");
    return 0;
}

    // arco dato numero
    unidirected_edge<T> edge_at(std::size_t i) const {

    assert(i < edges.size());

    auto it = edges.begin();
    std::advance(it, i);

    return *it;
	}


    // differenza tra grafi
    unidirected_graph operator-(const unidirected_graph& other) const {

        unidirected_graph result;

        for (auto const& e : edges) {
            bool found = false;

            for (auto const& x : other.edges) {
                if (e == x) {
                    found = true;
                    break;
                }
            }

            if (!found)
                result.add_edge(e);
        }

        return result;
    }
};