#pragma once
#include <stack>

template<typename T>
class lifo {
private:
    std::stack<T> s;

public:
    lifo() = default;

    void put(const T& x) {
        s.push(x);
    }

    T get() {
        T x = s.top();
        s.pop();
        return x;
    }

    bool empty() const {
        return s.empty();
    }
};