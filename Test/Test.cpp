
#include <iostream>
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

// Test case must be called the class above
// Also note: use TEST_F instead of TEST to access the test fixture (from google test primer)
TEST_F(ConstantsTest, Constants) {
  EXPECT_EQ(c.c(11), 1);
  EXPECT_EQ(c.c(21), 1.640);
  EXPECT_EQ(c.c(31), 6.371);
  EXPECT_EQ(c.c(41), 49.076);
}


