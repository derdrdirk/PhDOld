#include "experiment.h"

extern"C" {
    double vphlmntv2_(double *energy, double *vprehadsp, double *vprehadtm, double *vpimhad, double *vprelepsp, double *vpreleptm, double *vpimlep, double *vpretopsp, double *vpretoptm, int *nrflag);
}


Experiment::Experiment(double minEnergy, double maxEnergy, int dataPoints) {
  std::cout << "Experiment..." << std::endl;
  double stepSize = (maxEnergy - minEnergy) / dataPoints;
  double energy, vprehadsp, vprehadtm, vpimhad, vprelepsp, vpreleptm, vpimlep, vpretopsp, vpretoptm;
  int nrflag = 0;  // either 0 or 1? check what does defined in Fortran code
  for  (double e=minEnergy; e <= maxEnergy; e = e+stepSize) {
      vphlmntv2_(&e, &vprehadsp, &vprehadtm, &vpimhad, &vprelepsp, &vpreleptm, &vpimlep, &vpretopsp, &vpretoptm, &nrflag);
      data[e] = vpimhad;
  }
  std::cout << "Data taken" << std::endl;
}

void Experiment::exp() {
  for (auto const& ent : data) {
    std::cout << ent.first << " " << ent.second << std::endl;
  }
  std::cout << "Experiment Start" << std::endl;
  return;
}
