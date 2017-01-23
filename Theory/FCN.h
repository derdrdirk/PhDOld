
#include <vector>
#include "Minuit2/FCNBase.h"
#include "OPE.h"

class FCN : public ROOT::Minuit2::FCNBase {
 public:
  FCN() {}
  ~FCN() {}

  double operator()(const std::vector<double>& par) const;

  double Up() const {return 1.;}

 private:
};

