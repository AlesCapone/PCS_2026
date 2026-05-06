#pragma once
#include <vector>

template<typename T>

bool is_sorted(const std::vector<T>& v){
	int n= v.size();
	  if (n <= 1) {
        return true;
	  }
	
	 for (int i = 0; i + 1 < n; i++) {
        if (v[i] > v[i + 1]) {
            return false;
        }
    }
    return true;

}

