#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]){
	if (argc <2) {
		std::cerr  << "Nome del file non inserito" << std::endl;
		return 1;
		}
	std::ifstream temp(argv[1]);
	if (!temp.is_open()){
		std::cerr << "Errore nell'apertura del file " << argv[1] << std::endl;
		return 2;
	}
	else {
	while( !temp.eof()) {
		std::string luogo;
		double temp_00;
		double temp_06;
		double temp_12;
		double temp_18;
		temp >> luogo >> temp_00 >> temp_06 >> temp_12 >> temp_18;
		double media=(temp_00+temp_06+temp_12+temp_18)/4;
		std::cout << luogo << " " << media << std::endl;
	}
	}
	
	return 0;
}