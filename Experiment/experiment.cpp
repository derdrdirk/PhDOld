#include "experiment.h"
#include <fstream>

extern"C" {
    double vphlmntv2_(double *energy, double *vprehadsp, double *vprehadtm, double *vpimhad, double *vprelepsp, double *vpreleptm, double *vpimlep, double *vpretopsp, double *vpretoptm, int *nrflag);
}


Experiment::Experiment(double minEnergy, double maxEnergy, int dataPoints) {
  std::cout << "Experiment..." << std::endl;
  
  double stepSize = (maxEnergy - minEnergy) / dataPoints;
  stepSize_ = stepSize;
  
  double energy, vprehadsp, vprehadtm, vpimhad, vprelepsp, vpreleptm, vpimlep, vpretopsp, vpretoptm;
  int nrflag = 0;  // either 0 or 1? check what does defined in Fortran code
  for  (double e=minEnergy; e <= maxEnergy; e = e+stepSize) {
      vphlmntv2_(&e, &vprehadsp, &vprehadtm, &vpimhad, &vprelepsp, &vpreleptm, &vpimlep, &vpretopsp, &vpretoptm, &nrflag);
      data[e] = vpimhad * teubnerFactor;
  }
  std::cout << "Data taken" << std::endl;
}

void Experiment::listData() {
  for (auto const& ent : data) {
    std::cout << ent.first << " " << ent.second << std::endl;
  }
  return;
}

void Experiment::exportData() {
  std::ofstream dataFile;
  dataFile.open("data.dat");
  for (auto const& ent : data) {
    dataFile << ent.first << "\t" << ent.second << "\n";
  }
  dataFile.close();
}

void Experiment::plot() {
   std::system("gnuplot> load '../Experiment/plot.gp'");
}

double Experiment::integrate() {
  double result = 0;
  for (auto const& ent : data) {
    result += ent.second * stepSize_;
  }
  return result;
}
