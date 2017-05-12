
#include "Numeric.h"
#include <iostream>
#include <math.h>
#include <complex>

// Runge-Kutta Method to solve differential equation
double Numeric::RungeKutta(double x1, double x2, double y1,
                            double (*func)(double, double) ) {
  int NSteps = 5000;  // Number of steps
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
    //    std::cout << "xi : " << xi << ", yi : " << yi << std::endl;
  }
  
  return yi;
}


// Find Root - Newton-Raphson method
// repeat until precision: 1e-15 is reached
double Numeric::NewtonRaphson(double xi, double (*func)(double),
                               double (*Dfunc)(double)) {
  double y = 1;
  int i = 0;
  while ( std::abs(y) > 1e-15 ) {
    xi = xi - func(xi)/Dfunc(xi);
    y = func(xi);
    i++;
  }

  return xi;
}
