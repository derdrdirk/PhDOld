#pragma once

#include <vector>
#include <iostream>
#include <math.h>
#include "Constants.h"

class OPE: public Constants {
 public:
  double AlphaS(double x);
  double Dimension0(double s);

  double Adler(double s);
  double AdlerInt(double s);

  void test();
  
 private:
  // OPE Dimension contributions. Default activated (true);
  std::vector<bool> dimension = {true};
};
