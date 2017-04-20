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


double Aleph::VAmom(double s0,
                    std::complex<double> (*weightFunc)(std::complex<double>)) {
  int NData = 80;
  double sbin[80], dsbin[80], sfm2[80], derr[80], corerr[80][80];
  aleph_vplusa_(sbin, dsbin, sfm2, derr, corerr);

  // Renormalization ?
  for (int i = 0; i < NData; i++) {
    sfm2[i] *= 0.99363;
  }
  
  int Nmax = 0;
  
  // Set Nmax to next bigger sbin
  for (int i = 80; i > 0; i--) {
    if (fabs(s0-sbin[i]) < dsbin[i]/2.) {
      Nmax = i;
      break;
    }
  }
  // std::cout << "NMax : " << Nmax << std::endl;
  Numeric num;
  // Integrate momenta up to s0
  double mom = 0.;
    // std::cout << "weight 3\t" << weightFunc(15.) << std::endl;
    //  std::cout << "weightTau 3\t" << constants.wTau(3) << std::endl;
  for (int i=0; i < Nmax; i++) {

    std::complex<double> intBegin = sbin[i]-dsbin[i]/2.;
    std::complex<double> intEnd = sbin[i]+dsbin[i]/2.;

    double wratio = s0/constants.stau*(weightFunc(intBegin/s0).real()
                                       -weightFunc(intEnd/s0).real())/
        (constants.wTau((sbin[i]-dsbin[i]/2.)/constants.stau)-constants.wTau((sbin[i]+dsbin[i]/2.)/constants.stau));

    std::cout << i << "\t" << sbin[i] << "\t" << dsbin[i] << "\t" << s0 << std::endl;
    double weightInt = (num.integrate(weightFunc, 1./s0,
                                      intBegin, intEnd)).real();
    double weightTauInt = num.integrate(constants.wTau, 1./s0,
                                        sbin[i]-dsbin[i]/2., sbin[i]+dsbin[i]/2.);
    //std::cout << "weightInt \t" << i << "\t" << weightInt << std::endl;
    //std::cout << "wratio : " << i << "\t" << weightInt/weightTauInt << std::endl;
    mom += constants.stau/s0/constants.Be*wratio*sfm2[i];
  }

  //  mom *= pow(constants.mtau, 2)/constants.Be/s0;
  //  std::cout << "factor : \t" << constants.stau/s0/constants.Be << std::endl;
  return mom;
}

double Aleph::Constants::wTau(double x) {
  return std::pow(1.-x, 3)*(1+x);
  //  return pow((1.-x), 2)*(1.+2*x);
}


double Aleph::Weights::w1(double x) {
  return x*x*x;
}

std::complex<double> Aleph::Weights::w2(std::complex<double> x) {
  return std::pow(1.-x, 2)*(1.+2.*x);
}
