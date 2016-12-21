// Copyright 2016 <Dirk Hornung>
#include <iostream>
#include "Experiment/experiment.h"

int main() {

  Experiment exp(0.1, 3.0, 10000);
  exp.exportData();
  exp.plot();
  std::cout << "Integral: " << exp.integrate() << std::endl;
  
  return 0;
}

