
#include <math.h>
#include <iostream>
#include <vector>
#include "nr3.h"
#include "Minuit2/FCNBase.h"
#include "Minuit2/VariableMetricMinimizer.h"
#include "Minuit2/FunctionMinimizer.h"
#include "Minuit2/FunctionMinimum.h"
#include "Minuit2/MnMigrad.h"
#include "Minuit2/MnHesse.h"
#include "Minuit2/MnUserParameters.h"
#include "Minuit2/MnPrint.h"

class Theory {
 public:
  Theory();

  
  void testMinuit();

  void test() {
  }
  
  void gauleg(const Doub x1, const Doub x2, std::vector<double> &x, std::vector<double> &w);
  double qgauss(const double func, const Doub a, const Doub b);
};
