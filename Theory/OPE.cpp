
#include "OPE.h"
#include "theory.h"


double OPE::AlphaS(double x) {
  return -12.*M_PI/(12*M_PI+2*3*log(x)-33*log(x));
}


double OPE::Dimension0(double s) {
  std::vector<double> K = {1., 1.};
  std::vector<double> KTilde = {K[0], K[1]};

  double sum = 0;
  int power = 0;
  for (auto i : KTilde) {
    sum += i*pow(AlphaS(s), power);
    power++;
  }
  return 1./4./M_PI/M_PI*sum;
}


double OPE::Adler(double s) {
  double function = 0;
  
  if (dimension[0]) {
    function += Dimension0(s);
  }

  return function;
}


void OPE::test() {
  double s = 3.0;
  Theory th;
  //  std::cout << "Int: " << th.qgauss(Adler(s), 0.1, 3.)<< std::endl;
}
