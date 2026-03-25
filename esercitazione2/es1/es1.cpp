#include <iostream> 

int main() { 

double ad[4] = {0.0, 1.1, 2.2, 3.3}; 
float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7}; 
int ai[3] = {0, 1, 2};

int x = 1; 
float y = 1.1; 

(&y)[1] = 0; 
/*
int lad = sizeof(ad)/sizeof(ad[0]);
int laf = sizeof(af)/sizeof(af[0]);
int lai = sizeof(ai)/sizeof(ai[0]);

std::cout << sizeof(ad) << " " << sizeof(ad[0]) << " " << sizeof(af) << " " << sizeof(af[0]) << " " <<  sizeof(ai) << " " << sizeof(ai[0]) << "\n"; 

std::cout << "Indirizzi array double: \n"; 

for(int i=0; i< lad; i++){
	
	std::cout << &ad[i] << "\n"; 
}

std::cout << "Indirizzi array float: \n"; 

for(int i=0; i< laf; i++){
	
	std::cout << &af[i] << "\n"; 
}

std::cout << "Indirizzi array int: \n"; 

for(int i=0; i< lai; i++){
	
	std::cout << &ai[i] << "\n"; 
}
*/

std::cout << x << "\n"; 

std::cout << "indirizzo variabile x: "<< &x << "\n"; 

std::cout << "indirizzo variabile y: " << &y << "\n"; 

return 0; 
}