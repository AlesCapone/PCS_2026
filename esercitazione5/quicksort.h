#pragma once

#include <vector>
#include <algorithm>

template <typename T>

void insertion_sort(std::vector<T>& A, int p, int r) {
	
    for (int i = p+1; i <= r; i++) {
        T value = A[i];
        int j = i-1;

        while (j >= p && A[j] > value) {
            std::swap(A[j+1], A[j]);
            j=j-1;
        }

        A[j+1] = value;
    }
}

template <typename T>

int partition(std::vector<T>& A, int p, int r) {
    T x = A[r];
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            std::swap(A[i], A[j]);
        }
    }

    std::swap(A[i + 1], A[r]);
    return i + 1;
}

template<typename T>

void quick_sort(std::vector<T>& A, int p, int r) {
	
	const int LIMITE= 20;
	
    if (p < r) {
		
		if (r - p + 1 <= LIMITE) {
		
        insertion_sort(A, p, r);
		
        return;
		}
	
        int q = partition(A, p, r);
		
        quick_sort(A, p, q - 1);
		
        quick_sort(A, q + 1, r);
    }
}