#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>


int main (){
	
	static const int N=5;
	
	double num[N]= {0.34, -7.2, 1e-7, 52.44, 2.754};
	
	double minimo = *std::min_element(num,num+N);
	
	double massimo = *std::max_element(num,num+N);
	
	double somma =0.0;
	double sommaquadrati= 0.0;
	
	for (int i =0; i<N; i++){
		
		somma += num[i];
	}
		double media = somma/N;
		
		for (int i =0; i<N; i++){
			
			sommaquadrati += std::pow (num[i]- media, 2);
		}
			double ds = std::sqrt(sommaquadrati/N);
		
		
	std::cout << "il valore minimo è: "<< minimo << "\n" << "il valore massimo è: " << massimo << "\n" << "la media è: " << media << "\n" << "la deviazione standard è: " << ds << std::endl;
	return 0;
}