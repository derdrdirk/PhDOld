
#include <vector>
#include <complex>

class Numeric {
 public:
  std::complex<double> integrate(std::complex<double> (*func)(std::complex<double>),
                                 double scale,  std::complex<double> a, std::complex<double> b);
};
