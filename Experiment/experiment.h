#include <iostream>
#include <map>
#include <fstream>

class Experiment {
 public:
  Experiment(double minEnergy, double maxEnergy, int numBins);
  void readAleph();
  void exportData();
  void listData();
  void plot();
  double integrate(double s0);
 private:
  std::map<double, double> data;
  double teubnerFactor = -411;  // R = -3 \alpha Im \Pi
  double numBins;
  double binWidth;
};
