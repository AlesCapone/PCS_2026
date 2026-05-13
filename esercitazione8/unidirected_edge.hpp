#pragma once
#include <iostream>
#include <algorithm>

template<typename T>
class unidirected_edge {
private:
    T from_;
    T to_;

public:
    unidirected_edge(const T& a, const T& b) {
        if (a < b) {
            from_ = a;
            to_ = b;
        } else {
            from_ = b;
            to_ = a;
        }
    }

    T from() const {
        return from_;
    }

    T to() const {
        return to_;
    }

    bool operator<(const unidirected_edge& other) const {
        if (from_ != other.from_)
            return from_ < other.from_;
        return to_ < other.to_;
    }

    bool operator==(const unidirected_edge& other) const {
        return from_ == other.from_ && to_ == other.to_;
    }

    friend std::ostream& operator<<(std::ostream& ost, const unidirected_edge& e) {
        ost << "(" << e.from_ << ";" << e.to_ << ")";
        return ost;
    }
};