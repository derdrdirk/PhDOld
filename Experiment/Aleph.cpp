#include "Aleph.h"
#include <vector>
#include <iostream>
#include <cmath>
#include "Numeric.h"


extern"C" {
  void aleph_vplusa_(double *sbin, double *dsbin, double *sfm2, double *derr, double (*corerr)[80]);
}


double func2(double x) {
  return x;
}

Aleph::Aleph(double x) {
  std::cout << "ALEPH INIT" << std::endl;
  std::cout << factors.wTau(4.) << std::endl;
}


double Aleph::VAmom(double s0) {
  double sbin[80], dsbin[80], sfm2[80], derr[80], corerr[80][80];
  aleph_vplusa_(sbin, dsbin, sfm2, derr, corerr);

  int Nmax = 0;
  
  // Set Nmax to next bigger sbin
  for (int i = 80; i > 0; i--) {
    if (fabs(s0-sbin[i]) < dsbin[i]/2.) {
      Nmax = i;
      break;
    }
  }

  Numeric num;
  std::cout << "int test: "  << num.integrate(func2, 0, 5) << std::endl;
  // Integrate momenta up to s0
  double mom = 0.;
  for (int i=1; i < Nmax; i++) {
    mom += sfm2[i];
  }

  mom *= pow(factors.mtau, 2)/factors.Be/s0;
  std::cout << "mom: " << mom << std::endl;
  return mom;
}

double Aleph::Factors::wTau(double x) {
  return pow((1-x), 2)*(1+2*x);
}


double Aleph::Weights::w1(double x) {
  return 1.;
}
