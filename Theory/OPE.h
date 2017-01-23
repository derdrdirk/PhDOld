
#include <vector>
#include <iostream>
#include <math.h>

class OPE {
 public:
  double AlphaS(double x);
  double Dimension0(double s);

  double Adler(double s);
  double AdlerInt(double s);

  void test();
  
 private:
  // OPE Dimension contributions. Default activated (true);
  std::vector<bool> dimension = {true};
};
