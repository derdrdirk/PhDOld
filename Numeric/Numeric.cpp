
#include "Numeric.h"
#include <iostream>
#include <math.h>
#include <complex>


// 3rd Numerical Recpies p.184 gauleg
// Gauss Quadratur

double Numeric::RungeKutta(double x1, double x2, double y1,
                            double (*func)(double, double) ) {
  int NSteps = 50;  // Number of steps
  double h = (x2 - x1)/NSteps;  // Step size

  // Stepper
  double xi = x1;
  double yi = y1;
  double k1, k2, k3, k4;
  for (int i = 0; i < NSteps; i++) {
    k1 = func(xi, yi);
    k2 = func(xi + 1./2.*h, yi + 1./2.*k1*h);
    k3 = func(xi+1./2.*h, yi+1./2.*k2*h);
    k4 = func(xi+h, yi+k3*h);

    // x_{i+1} and y_{i+1}
    xi = xi + h;
    yi = yi + 1./6.*(k1 + 2.*k2 + 2.*k3 + k4)*h;
  }
  
  return yi;
}


