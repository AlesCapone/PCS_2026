#include <iostream>
#include <cmath>
#include "gradiente.hpp"

int main()
{
    Eigen::MatrixXd A(2,2);

    A << 4,1,
         1,3;

    Eigen::VectorXd x_ex(2);
    x_ex << 1,1;

    Eigen::VectorXd b = A * x_ex;

    Eigen::VectorXd x_0 = Eigen::VectorXd::Zero(2);

    Eigen::VectorXd x = gradiente_coniugato(A, b, x_0);

    std::cout << "Soluzione trovata:\n";
    std::cout << x << "\n\n";

    double err =
        (x - x_ex).norm();

    std::cout << "Errore: " << err << std::endl;

    if (err < 1e-8)
    {
        std::cout << "Test superato\n";
        return EXIT_SUCCESS;
    }

    std::cerr << "Test fallito\n";
    return EXIT_FAILURE;
}