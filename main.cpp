// Copyright 2016 <Dirk Hornung>
#include <iostream>
#include "Experiment/experiment.h"
#include "Theory/theory.h"
#include "Experiment/Aleph.h"
#include "Numeric.h"
// #include "Test.h"
#include "Constants.h"


  double func(double x) {
    return x + x*x + 7*x*x*x*x;
  }

std::complex<double> func2(std::complex<double> x) {
  return 2.0*(1.-x);
}

int main(int argc, char **argv) {
  Theory th;
  th.test();

 
  
  // Test::Test();

  // ::testing::InitGoogleTest(&argc, argv);
  // return RUN_ALL_TESTS();
  
  // Experiment exp(0.1, 3.0, 10000);
  // exp.VAmomAleph();
  // exp.exportData();
  // // exp.plot();
  // std::cout << "Integral: " << exp.integratpe(2.) << std::endl;

  // Aleph aleph(1.0);
  // Aleph::Weights weights;

  // std::cout << "VpA mom: \t" << aleph.VAmom(3., func2) << std::endl;

  // Numeric num;
  // std::cout << num.integrate(func, -21, 3) << std::endl;
  

  // th.qgauss(-23.0, 17.0);
  // double var = th.Dimension0(1);
  // std::cout << var << std::endl;

  
  
  std::cout << "The End" << std::endl;
  
  return 0;
}






