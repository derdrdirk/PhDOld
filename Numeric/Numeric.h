
#include <vector>

class Numeric {
 public:
  double integrate(double (*func)(double), double scale,  double a, double b);
};
