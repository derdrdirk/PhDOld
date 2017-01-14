#include "theory.h"





Theory::Theory () {
  std::cout << "Theory..." << std::endl;
}

double Theory::Dimension0(double x) {
  return x*x;
  // return 1./4./M_PI * ( 1. + a );
}

void Theory::testMinuit() {

  OPE fcn;

  {
  ROOT::Minuit2::MnUserParameters upar;
  upar.Add("x", 1., 0.1);
  upar.Add("y", 1., 0.1);
  upar.Add("z", 1., 0.1);
  upar.Add("w", 1., 0.1);

  ROOT::Minuit2::MnMigrad migrad(fcn, upar);
  ROOT::Minuit2::FunctionMinimum min = migrad();
  std::cout << "minimum : " << min << std::endl;
  }

  
  
}


// initialise integration
// find abscissas + weights
// 3rd Numerical Recpies p.184 gauleg
void Theory::gauleg(Doub x1, Doub x2, std::vector<double>& x, std::vector<double>& w) {
  const Doub EPS = 1.0e-14;
  Doub z1, z, xm, xl, pp, p3, p2, p1;
  Int n = x.size();
  Int m = (n+1)/2;
  xm = 0.5*(x2+x1);
  xl = 0.5*(x2-x1);
  for (Int i = 0; i < m; i++) {
    z = cos(3.141592654*(i+0.75)/(n+0.5));
    do {
      p1 = 1.0;
      p2 = 0.0;
      for (Int j = 0; j < n; j++) {
        p3 = p2;
        p2 = p1;
        p1 = ((2.0*j+1.0)*z*p2-j*p3) / (j+1);
      }
      pp = n*(z*p1-p2)/(z*z-1.0);
      z1 = z;
      z = z1 - p1/pp;
    } while (abs(z-z1) > EPS);
    x[i] = xm - xl*z;
    x[n-1-i] = xm+xl*z;
    w[i] = 2.0*xl/((1.0-z*z)*pp*pp);
    w[n-1-i] = w[i];
  }
}


// Gauss Quadratur
Doub Theory::qgauss(const Doub a, const Doub b) {
  // std::cout << "Gauss" << std::endl;

  std::vector<double> x(10);
  std::vector<double> w(10);

  gauleg(a, b, x, w);

  // for ( auto const& value: x ) {
  //   std::cout << value << std::endl;
  // }

  // double sum;
  // for (auto const& val: w) {
  //   std::cout << val << std::endl;
  //   sum += val;
  // }

  // std::cout << "Sum :" << sum << std::endl;

  double s = 0;
  for (int i = 0; i < x.size(); i++) {
    s += w[i]*Theory::Dimension0(x[i]);
  }

  
  std::cout << "Integral value: " << s << std::endl;
  
  return s;
}



