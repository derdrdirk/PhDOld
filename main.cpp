// Copyright 2016 <Dirk Hornung>
#include <iostream>
#include "Experiment/Experiment.h"
#include "Theory/theory.h"
#include "Experiment/Aleph.h"
#include "Numeric.h"
// #include "Test.h"
#include "Constants.h"


double func(double x, double y) {
  return -2.*x*x*x + 12.*x*x - 20.*x + 8.5;
}

std::complex<double> func2(std::complex<double> x) {
  return 2.0*(1.-x);
}

double func3(double x) {
  return 4. - x;
}

int main(int argc, char **argv) {
  // Experiment exp(0.1, 3.0, 10000);
  // exp.VAmomAleph();
  // exp.exportData();
  // // exp.plot();
  // std::cout << "Integral: " << exp.integratpe(2.) << std::endl;

  // Aleph aleph(1.0);
  // Aleph::Weights weights;

  // std::cout << "VpA mom: \t" << aleph.VAmom(3., func2) << std::endl;

  Numeric num;
  std::cout << num.RungeKutta(0., 4.0, 1., func) << std::endl;
  //  std::cout << num.integrate(func, 2,  -21.0, 3.0) << std::endl;
  
  std::cout << "The End" << std::endl;
  
  return 0;
}






