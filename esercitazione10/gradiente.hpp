#pragma once
#include <Eigen/Dense>

Eigen::VectorXd gradiente_coniugato(const Eigen::MatrixXd& A, const Eigen::VectorXd& b, const Eigen::VectorXd& x_0, double tol = 1e-12, unsigned int it_max = 10000){
	
	if (A.rows() != A.cols())
		throw std::invalid_argument("A non quadrata");
	
	if (A.rows() != b.size() || b.size() != x_0.size())
		throw std::invalid_argument("dimensioni incompatibili");
	
	if (!A.isApprox(A.transpose()))
		throw std::invalid_argument("A non simmetrica");
	
	 Eigen::VectorXd x = x_0;
	 Eigen::VectorXd r = b - A * x;
	 Eigen::VectorXd p = r;
	 unsigned int it = 0;
	 
	 while (it < it_max && r.norm() > tol){
		 
		  Eigen::VectorXd Ap = A * p;
		  
		  double alpha =  (p.transpose() * r).value() /(p.transpose() * Ap).value();
		  
		  x = x + alpha * p;
		  
		  Eigen::VectorXd r_new = b - A * x;
		  
		  double beta = (p.transpose() * A * r_new).value() / (p.transpose() * Ap).value();
		  
		  p = r_new - beta * p;
		  
		  r = r_new;
		  
		  it++;
    }

    return x;
}