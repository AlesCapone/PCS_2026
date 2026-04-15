#pragma once

#include <vector>
#include <algorithm>

template <typename T>

void bubble_sort(std::vector<T>& v) {
	
	int n = v.size();
	
    for (int i = 0; i < n-1; i++) {
		 for (int j = n-1; j > i; j--) {

			 if (v[j] < v[j - 1]) {
				
                std::swap(v[j], v[j - 1]);
            }
        }
    }
}