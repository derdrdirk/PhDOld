
#include <iostream>
#include <cmath>
#include "gtest/gtest.h"
#include "Constants.h"


TEST(EquationTest, Zero) {
  EXPECT_EQ(0, 0);
}

// The fixture for testing class Project1. From google test primer.
class ConstantsTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  ConstantsTest() {
    // You can do set-up work for each test here.
  }

  virtual ~ConstantsTest() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:
  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  // Objects declared here can be used by all tests in the test case
  // for Project1.
  Constants c;
};

// Precision to 10^-13 (normal DOUBLE 10^-15)
double precision = std::pow(10, -13);

// compare with Mathematica/Constants.nb
TEST_F(ConstantsTest, Adler) {
  EXPECT_EQ(c.c(11), 1);
  EXPECT_EQ(c.c(21), 1.640);
  EXPECT_EQ(c.c(31), 6.371);
  EXPECT_EQ(c.c(41), 49.076);
}

TEST_F(ConstantsTest, Beta) {
  EXPECT_EQ(c.beta(1), 7./2);
  EXPECT_EQ(c.beta(2), 13./4);
  EXPECT_NEAR(c.beta(3), -1.01562500000000000, precision);
  EXPECT_NEAR(c.beta(4), 94.4560791469040, precision);
}

TEST_F(ConstantsTest, Gamma) {
  EXPECT_NEAR(c.gamma(1), 2., precision);
  EXPECT_NEAR(c.gamma(2), 6.75, precision);
  EXPECT_NEAR(c.gamma(3), 9.67734763507072381, precision);
}


