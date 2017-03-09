
#include "Numeric.h"
#include <iostream>
#include <math.h>
#include <complex>


// 3rd Numerical Recpies p.184 gauleg
// Gauss Quadratur
std::complex<double>  Numeric::integrate(
                    std::complex<double> (*func)(std::complex<double>),
                    double scale, std::complex<double> a, std::complex<double> b
                ) {
  std::vector<std::complex<double> > x(10);
  std::vector<std::complex<double> > w(10);

  std::complex<double> x1 = a;
  std::complex<double> x2 = b;


  // GAULEG weights and abciss nodes
  // initialise integration
  // find abscissas + weights
  const double EPS = 1.0e-14;
  std::complex<double> z1, z, xm, xl, pp, p3, p2, p1;
  int n = x.size();
  int m = (n+1.)/2.;
  xm = 0.5*(x2+x1);
  xl = 0.5*(x2-x1);
  for (int i = 0; i < m; i++) {
    z = cos(3.141592654*(i+0.75)/(n+0.5));
    do {
      p1 = 1.0;
      p2 = 0.0;
      for (int j = 0; j < n; j++) {
        p3 = p2;
        p2 = p1;
        std::complex<double> jComplx(j, 0.);
        p1 = ((2.0*j+1.0)*z*p2-jComplx*p3) / (jComplx+1.);
      }
      std::complex<double> nComplx(n, 0.);
      pp = nComplx*(z*p1-p2)/(z*z-1.0);
      z1 = z;
      z = z1 - p1/pp;
    } while (std::abs(z-z1) > EPS);
    x[i] = xm - xl*z;
    x[n-1-i] = xm+xl*z;
    w[i] = 2.0*xl/((1.0-z*z)*pp*pp);
    w[n-1-i] = w[i];
  }


  // qgauss Integrate
  std::complex<double> s = 0;
  for (int i = 0; i < x.size(); i++) {
    s += w[i]*func(x[i]*scale);
  }
    
  return s;
}
