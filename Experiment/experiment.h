#include <iostream>
#include <map>

class Experiment {
 public:
  Experiment(double minEnergy, double maxEnergy, int dataPoints);
  void exportData();
  void listData();
  void plot();
  double integrate();
 private:
  std::map<double, double> data;
  double teubnerFactor = -411;  // R = -3 \alpha Im \Pi
  double stepSize_;
};
