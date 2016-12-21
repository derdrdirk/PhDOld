#include <iostream>
#include <map>

class Experiment {
 public:
  Experiment(double minEnergy, double maxEnergy, int dataPoints);
  void exportData();
  void listData();
  void plot();
 private:
  std::map<double, double> data;
};
