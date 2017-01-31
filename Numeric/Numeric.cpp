
#include "Numeric.h"
#include <iostream>
#include <math.h>


// 3rd Numerical Recpies p.184 gauleg
// Gauss Quadratur
double  Numeric::integrate(double (*func)(double), double a, double b) {
  // std::cout << "Gauss" << std::endl;

  std::vector<double> x(10);
  std::vector<double> w(10);

  double x1 = a;
  double x2 = b;


  // GAULEG weights and abciss nodes
  // initialise integration
  // find abscissas + weights
  const double EPS = 1.0e-14;
  double z1, z, xm, xl, pp, p3, p2, p1;
  int n = x.size();
  int m = (n+1)/2;
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
        p1 = ((2.0*j+1.0)*z*p2-j*p3) / (j+1);
      }
      pp = n*(z*p1-p2)/(z*z-1.0);
      z1 = z;
      z = z1 - p1/pp;
    } while (fabs(z-z1) > EPS);
    x[i] = xm - xl*z;
    x[n-1-i] = xm+xl*z;
    w[i] = 2.0*xl/((1.0-z*z)*pp*pp);
    w[n-1-i] = w[i];
  }


  // qgauss Integrate
  double s = 0;
  for (int i = 0; i < x.size(); i++) {
    s += w[i]*func(x[i]);
  }

  
  std::cout << "Integral value: " << s << std::endl;
  
  return s;
}
