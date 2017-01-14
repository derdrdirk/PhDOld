
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
  double Dimension0(double x);

  class OPE : public ROOT::Minuit2::FCNBase {
   public:
    OPE() {}

    ~OPE() {}

    double operator()(const std::vector<double>& par) const {
      double x = par[0];
      double y = par[1];
      double z = par[2];
      double w = par[3];

      return ( (1./70.)*(21*x*x + 20*y*y + 19*z*z - 14*x*z - 20*y*z) + w*w );
    }

    double Up() const {return 1.;}

   private:
  };
  
  void testMinuit();

  void gauleg(const Doub x1, const Doub x2, std::vector<double> &x, std::vector<double> &w);
  Doub qgauss(const Doub a, const Doub b);
};
