#include "theory.h"

Theory::Theory () {
  std::cout << "Theory..." << std::endl;
}

double Theory::Dimension0(double a) {
  return 1./4./M_PI * ( 1. + a );
}
