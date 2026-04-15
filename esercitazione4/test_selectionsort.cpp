
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "selection.h"
#include "is_sorted.h"
#include "randfiller.h"

int main() {
    randfiller rf;
	std::srand(std::time(0));

    for (int k = 0; k < 100; k++) {
        int size = std::rand() % 100;

        std::vector<int> v(size);
        rf.fill(v, -1000, 1000);

        selection_sort(v);
        if(!is_sorted(v)){
			std::cout << "errore"<< "\n";
			return EXIT_FAILURE;
		}
    }

    std::vector<std::string> vs =  {"carlo", "alessandro", "PCS", "marta", "giovanna", "barbara", "marcello", "francesca"};

    selection_sort(vs);
	
  if(!is_sorted(vs)){
		std::cout << "errore"<< "\n";
			return EXIT_FAILURE;
		}
		
		std::cout << "test funzionante" << "\n";
    return EXIT_SUCCESS;
}
