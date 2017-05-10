
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
TEST(NumericTest, NewtonRaphson) {
  EXPECT_NEAR(num.NewtonRaphson(0., newtonRaphson1, dNewtonRaphson1),
              0.924144, numPrecision);
}
  
