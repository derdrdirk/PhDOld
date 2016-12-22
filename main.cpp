// Copyright 2016 <Dirk Hornung>
#include <iostream>
#include "Experiment/experiment.h"
#include "Theory/theory.h"

int main() {

  // Experiment exp(0.1, 3.0, 10000);
  // exp.exportData();
  // exp.plot();
  // std::cout << "Integral: " << exp.integrate() << std::endl;

  Theory th;
  double var = th.Dimension0(1);
  std::cout << var << std::endl;
  
  std::cout << "The End" << std::endl;
  
  return 0;
}

