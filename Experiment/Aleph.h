#include <vector>

class Aleph {
 public:
  explicit Aleph(double x);

  class Weights {
   public:
    double w1(double x);
  };

  class Factors {
   public:
    double wTau(double x);
  };
 private:
  Weights weights;
  Factors factors;
};
