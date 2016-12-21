#include <iostream>
#include <map>

class Experiment {
 public:
  Experiment(double minEnergy, double maxEnergy, int dataPoints);
  void exp();
 private:
  std::map<double, double> data;
};
