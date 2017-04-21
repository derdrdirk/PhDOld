#pragma once

#include <cmath>

class Constants {
 public:
  double N_c = 3.;
  double N_f = 6.;

  double C_f = (std::pow(N_c, 2)-1)/2./N_c;

  double zeta(int i) {
    switch (i) {
      case 3: return 1.20205690315959429;
    }
    return 0;
  }

  double beta(int i) {
    switch (i) {
      case 1: return 1./6*(11*N_c-2*N_f);
      case 2: return 1./12*(17*std::pow(N_c, 2.)-5*N_c*N_f-3*C_f*N_f);
      case 3: return 1./32*(2857./54.*std::pow(N_c, 3.)
                            -1415./54.*std::pow(N_c, 2.)*N_f
                            +79./54.*N_c*std::pow(N_f, 2.)
                            -205./18.*N_c*C_f*N_f
                            +11./9.*C_f*std::pow(N_f, 2.)
                            +std::pow(C_f, 2.)*N_f);
      case 4: return 140599./2304. + 445./16.*zeta(3);
    }
    return 0;
  }

  double gamma(int i) {
    switch (i) {
      case 1: return 3./2.*C_f;
      case 2: return C_f/48.*(97*N_c+9*C_f-10*N_f);
      case 3: return C_f/32.*(11413./108.*std::pow(N_c, 2)-129./4.*N_c*C_f
                             -(278./27.+24*zeta(3))*N_c*N_f
                             +129./2.*std::pow(C_f, 2)
                             -(23-24*zeta(3))*C_f*N_f-35./27.*std::pow(N_f, 2));
    }
    return 0;
  }
  
  double c(int i) {
    switch (i) {
      case 11: return 1;
      case 21: return 1.640;
      case 31: return 6.371;
      case 41: return 49.076;
    }
    return 0;
  }
};
