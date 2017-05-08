
#include <typeinfo>
#include <iostream>
#include "gtest/gtest.h"
#include "Numeric.h"

Numeric num;

double rungeKutta1(double x, double y) {
  return -2.*x*x*x + 12.*x*x - 20.*x + 8.5;
}

double numPrecision = std::pow(10, -13);


TEST(NumericTest, RungeKutta) {
  EXPECT_NEAR(num.RungeKutta(0., 4., 1., rungeKutta1), 3., numPrecision);
}
