// Copyright 2016 <Dirk Hornung>
#include <iostream>
#include <map>
#include "Experiment/experiment.h"
#include <stdio.h>

int main() {

  Experiment exp(0.5, 2.0, 10);
  exp.exportData();
  exp.plot();
  
  
  return 0;
}

