
#include <math.h>
#include <iostream>
#include <vector>
#include "nr3.h"


class Theory {
 public:
  Theory();
  double Dimension0(double a);
  void testMinuit();
  void gauleg(const Doub x1, const Doub x2, std::vector<double> &x, std::vector<double> &w);
  Doub qgauss(const Doub a, const Doub b);
};
