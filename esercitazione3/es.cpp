#include <iostream>
#include "rational.hpp"


int main (void){

    rational<int> r1(4,6);

    rational<int> r2(-3,4);


std::cout << r1 + r2 << "\n";

std::cout << r1 - r2 << "\n";

std::cout << r1 * r2 << "\n";

std::cout << r1 / r2 << "\n";



  return 0;

}
