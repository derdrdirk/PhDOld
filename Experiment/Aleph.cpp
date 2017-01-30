#include "Aleph.h"
#include <vector>
#include <iostream>
#include <cmath>

Aleph::Aleph(double x) {
  std::cout << "ALEPH INIT" << std::endl;

  std::cout << factors.wTau(4.) << std::endl;
}

double Aleph::Factors::wTau(double x) {
  return pow((1-x), 2)*(1+2*x);
}


double Aleph::Weights::w1(double x) {
  return 1.;
}
