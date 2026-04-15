#pragma once
#include <vector>
#include <algorithm>

template <typename T>
void insertion_sort(std::vector<T>& v) {
	int n=v.size();
    for (int i = 1; i < n; i++) {
        T value = v[i];
        int j = i-1;

        while (j >= 0 && v[j] > value) {
            std::swap(v[j+1], v[j]);
            j=j-1;
        }

        v[j+1] = value;
    }
}