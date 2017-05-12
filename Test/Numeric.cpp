
#include <typeinfo>
#include <iostream>
#include "gtest/gtest.h"
#include "Numeric.h"
#include "Constants.h"

Numeric num;
Constants c;
double numPrecision = 1e-6;

// double rungeKutta1(double x, double y) {
//   return -2.*x*x*x + 12.*x*x - 20.*x + 8.5;
// }
// double betaFkt(double mu, double as) {
//   return -std::pow(as, 2)*7./2./mu;
// }
// TEST(NumericTest, RungeKutta) {
//   EXPECT_NEAR(num.RungeKutta(0., 4., 1., rungeKutta1), 3., numPrecision);
// }
// TEST(NumericTest, BetaFkt) {
//   EXPECT_NEAR(num.RungeKutta(1., 91.188, 1.570796327, betaFkt),
//               0.1187, numPrecision);
// }

double newtonRaphson1(double x) {
  return 3*x*x*x + 2*x*x + x -5;
}
double dNewtonRaphson1(double x) {
  return 9*x*x + 4*x + 1;
}
// double alphaIntegral(double y1, double y2, double x1, double x2) {
//   return 0.285714285714/y1 + 0.26530612245*log(y1)
//       -0.39808698771*log(1.0*y1 + 0.295977658225)
//       +0.066390432633*log(1.0*y2 + 0.295977658225)
//       -0.066390432633*log(y2*(y2 - 0.306730010103) + 0.1251927561073)
//       +0.46266488467*atan(0.480978580804-3.13616904092*y2);
// }
// double dAlphaIntegral(double y1, double y2) {
//   return -0.066390432633*(2.0*y2 - 0.306730010103)
//       /(y2*(y2 - 0.306730010103) + 0.1251927561073)
//       -1.4509952876/(std::pow(0.480978580804-3.13616904092*y2, 2) + 1)
//       -0.26530612245/y2
//       +0.39808698771/(y2 + 0.295977658225)
//       + 0.285714285714/ std::pow(y2, 2);
// }
// double alphaIntegralRootFunc(double y2) {
//   double x1 = 91.188;
//   double y1 = 0.1187/3.14159265358979;
//   double x2 = 1.;
//   return alphaIntegral(y1, y2, x1, x2) - log(x1/x2);
// }
// double dAlphaIntegralRootFunc(double y2) {
//   double x1 = 91.188;
//   double y1 = 0.1187/3.14159265358979;
//   double x2 = 1.;
//   return dAlphaIntegral(y1, y2);
// }
// TEST(NumericTest, NewtonRaphson) {
//   EXPECT_NEAR(num.NewtonRaphson(0., newtonRaphson1, dNewtonRaphson1),
//               0.924144, numPrecision);
//   std::cout << "fking alphas "
//             << 3.14159265358979*num.NewtonRaphson(0.1, alphaIntegralRootFunc, dAlphaIntegralRootFunc) << std::endl;
// }

double vx1 = 91.188;
double vx2 = 1;
double vpi = 3.14159265358979;
double vy1 = 0.1187/vpi;
double vb1 = 27./6.;

double intAlpha1(double b1, double y1, double y2, double x1, double x2) {
  return (1./y1 - 1./y2)/b1-log(x1/x2);
}
double dIntAlpha1(double b1, double y2) {
  return 1/(b1*y2*y2);
}
double intAlpha1Go(double y2) {
  return intAlpha1(vb1, vy1, y2, vx1, vx2);
}
double dIntAlpha1Go(double y2) {
  return dIntAlpha1(vb1, y2);
}
      

TEST(NumericTest, NewtonRaphson) {
  std::cout << vpi*num.NewtonRaphson(0.1, intAlpha1Go, dIntAlpha1Go) << std::endl;
}
  
