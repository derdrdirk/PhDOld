
#include <math.h>
#include <iostream>
#include <vector>
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
  

};
