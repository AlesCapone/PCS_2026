#pragma once
#include <vector>
#include <algorithm>

template <typename T>
void selection_sort(std::vector<T>& v) {
	int n = v.size();
    for (int i = 0; i < n-1; i++) {
        int min_index = i;

    for (int j= i+1; j < n; j++){
		if(v[j]< v[min_index]){
		
		min_index = j;
		}
		
    }
	if(min_index != i){
		std::swap(v[i],v[min_index]);
	}
}
}