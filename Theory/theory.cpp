
#include "theory.h"
#include "FCN.h"


Theory::Theory () {
  std::cout << "Theory..." << std::endl;
}


void Theory::testMinuit() {

  FCN fcn;

  {
  ROOT::Minuit2::MnUserParameters upar;
  upar.Add("x", 1., 0.1);

  ROOT::Minuit2::MnMigrad migrad(fcn, upar);
  ROOT::Minuit2::FunctionMinimum min = migrad();
  std::cout << "minimum : " << min << std::endl;
  }

  
  
}








