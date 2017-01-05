#include "theory.h"


double myFunction(double x, double y) {
  return x*x*x*x + x*x + x*y + y*y;
}

void minuitFunction(int& nDim, double* gout, double& result, double par[], int flg) {
  result = myFunction(par[0], par[1]);
}


Theory::Theory () {
  std::cout << "Theory..." << std::endl;
}

double Theory::Dimension0(double a) {
  return 1./4./M_PI * ( 1. + a );
}

void Theory::testMinuit() {


//Fitter* minimizer = new TFitter(2);
//
//
// double p1 =-1;
// minimizer->ExecuteCommand("SET PRINTOUT", &p1,1);
//
// minimizer->SetFCN(minuitFunction);
// minimizer->SetParameter(0,"X",2,1,0,0);
// minimizer->SetParameter(1,"Y",2,1,0,0);
//
}
