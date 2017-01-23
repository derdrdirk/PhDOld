
#include "FCN.h"

double FCN::operator()(const std::vector<double>& par) const {
  double x = par[0];

  OPE ope;
  return ope.Adler(x);
}
