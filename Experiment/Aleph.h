
class Aleph {
 public:
  explicit Aleph(double x);
  double VAmom(double s0);

  class Weights {
   public:
    static double w1(double x);
  };

  class Factors {
   public:
    static double wTau(double x);
  
    double Be = 17.827;  // HFAG 2011
    double mtau = 1.77682;  // PDG 2012
    
  };
 private:
  Weights weights;
  Factors factors;
};