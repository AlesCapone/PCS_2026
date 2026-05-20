#pragma once
#include <queue>

template<typename T>
class fifo {
private:
    std::queue<T> q;

public:
    fifo() = default;

    void put(const T& x) {
        q.push(x);
    }

    T get() {
        T x = q.front();
        q.pop();
        return x;
    }

    bool empty() const {
        return q.empty();
    }
};