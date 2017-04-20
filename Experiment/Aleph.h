
#include <complex>

class Aleph {
 public:
  explicit Aleph(double x);
  double VAmom(double s0, std::complex<double> (*weightFunc)(std::complex<double>) );

  class Weights {
   public:
    static double w1(double x);
    static std::complex<double> w2(std::complex<double> x);
  };

  class Constants {
   public:
    static double wTau(double x);
  
    double Be = 17.827;  // HFAG 2011
    double mtau = 1.77682;  // PDG 2012
    double stau = std::pow(mtau, 2);
  };
 private:
  Weights weights;
  Constants constants;
};
