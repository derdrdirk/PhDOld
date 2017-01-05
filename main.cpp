// Copyright 2016 <Dirk Hornung>
#include <iostream>
#include "Experiment/experiment.h"
#include "Theory/theory.h"

#include "Quad4F.h"
#include "Minuit2/FunctionMinimum.h"
#include "Minuit2/MnMigrad.h"
#include "Minuit2/MnHesse.h"
#include "Minuit2/MnUserParameters.h"
#include "Minuit2/MnPrint.h"

using namespace ROOT::Minuit2;

int main() {

 Quad4F fcn;

//   PentiumTimer stopwatch;
//   stopwatch.start();

//   long long int start = stopwatch.lap().ticks();
//   long long int stop = stopwatch.lap().ticks();
//   std::cout<<"stop-start: "<<stop - start<<std::endl;
//   start = stopwatch.lap().ticks();
  {
  //test constructor
  MnUserParameters upar;
  upar.Add("x", 1., 0.1);
  upar.Add("y", 1., 0.1);
  upar.Add("z", 1., 0.1);
  upar.Add("w", 1., 0.1);

  MnMigrad migrad(fcn, upar);
  FunctionMinimum min = migrad();
  std::cout<<"minimum: "<<min<<std::endl;
  }
  {
     // use analytical derivatives 
     Quad4FGrad gfcn;

     MnUserParameters upar;
     upar.Add("x", 1., 0.1);
     upar.Add("y", 1., 0.1);
     upar.Add("z", 1., 0.1);
     upar.Add("w", 1., 0.1);

     MnMigrad migrad(gfcn, upar);
     FunctionMinimum min = migrad();
     std::cout<<"minimum with grad calculation : "<<min<<std::endl;

     // try to run hesse 
     MnHesse hesse; 
     hesse( gfcn, min); 
     std::cout<<"minimum after hesse: "<<min<<std::endl;
  }


  

  // Experiment exp(0.1, 3.0, 10000);
  // exp.exportData();
  // exp.plot();
  // std::cout << "Integral: " << exp.integrate() << std::endl;



  Theory th;
  double var = th.Dimension0(1);
  std::cout << var << std::endl;
  
  std::cout << "The End" << std::endl;
  
  return 0;
}






