// Copyright 2016 <Dirk Hornung>
#include <iostream>
#include "Experiment/experiment.h"
#include "Theory/theory.h"
#include "Experiment/Aleph.h"


  double func(double x) {
    return x;
  }

int main() {

  // Experiment exp(0.1, 3.0, 10000);
  // exp.VAmomAleph();
  // exp.exportData();
  // // exp.plot();
  // std::cout << "Integral: " << exp.integrate(2.) << std::endl;

  Aleph aleph(1.0);
  

  // th.qgauss(-23.0, 17.0);
  // double var = th.Dimension0(1);
  // std::cout << var << std::endl;

  
  
  std::cout << "The End" << std::endl;
  
  return 0;
}






