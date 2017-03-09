#include "Aleph.h"
#include <vector>
#include <iostream>
#include <cmath>
#include "Numeric.h"
#include <complex>
using namespace std::complex_literals;


extern"C" {
  void aleph_vplusa_(double *sbin, double *dsbin, double *sfm2, double *derr, double (*corerr)[80]);
}


double func2(double x) {
  return x;
}

Aleph::Aleph(double x) {
  std::cout << "ALEPH INIT" << std::endl;
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
   // Integrate momenta up to s0
  double mom = 0.;
  for (int i=1; i < Nmax; i++) {
    // double weightInt = num.integrate(weights.w1, s0,
    //                                  sbin[i]-dsbin[i]/2., sbin[i]+dsbin[i]/2.);
    // double weightTauInt = num.integrate(constants.wTau, s0,
    //                                   sbin[i]-dsbin[i]/2., sbin[i]+dsbin[i]/2.);
    // mom += weightInt/weightTauInt*sfm2[i];
  }

  //  mom *= pow(constants.mtau, 2)/100/constants.Be/s0;

  std::complex<double> x = 1. + 1i;
  std::cout << "complx" << num.integrate(weights.w2, 1., 3.+1i, 7.+3i) << std::endl;
  std::cout << "real " << num.integrate(weights.w1, 1., 5., 9.) << std::endl;
  
  return mom;
}

double Aleph::Constants::wTau(double x) {
  return pow((1-x), 2)*(1+2*x);
}


double Aleph::Weights::w1(double x) {
  return x*x*x;
}

std::complex<double> Aleph::Weights::w2(std::complex<double> x) {
  return std::pow(1.-x, 3)*(1.+x);
}
