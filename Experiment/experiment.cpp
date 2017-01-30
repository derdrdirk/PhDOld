#include "experiment.h"
#include <vector>
#include <cmath>


extern"C" {
    double vphlmntv2_(double *energy, double *vprehadsp, double *vprehadtm, double *vpimhad, double *vprelepsp, double *vpreleptm, double *vpimlep, double *vpretopsp, double *vpretoptm, int *nrflag);
}


extern"C" {
  void aleph_vplusa_(double *sbin, double *dsbin, double *sfm2, double *derr, double (*corerr)[80]);
}


Experiment::Experiment(double minEnergy, double maxEnergy, int numBins) {
  std::cout << "Experiment..." << std::endl;
  
  binWidth = (maxEnergy - minEnergy) / numBins;
  
  double energy, vprehadsp, vprehadtm, vpimhad, vprelepsp, vpreleptm, vpimlep, vpretopsp, vpretoptm;
  int nrflag = 0;  // either 0 or 1? check what does defined in Fortran code
  for  (double e=minEnergy; e <= maxEnergy; e = e+binWidth) {
      vphlmntv2_(&e, &vprehadsp, &vprehadtm, &vpimhad, &vprelepsp, &vpreleptm, &vpimlep, &vpretopsp, &vpretoptm, &nrflag);
      data[e] = vpimhad * teubnerFactor;
  }
  std::cout << "Datataken" << std::endl;
}



void Experiment::VAmomAleph() {
  double sbin[80], dsbin[80], sfm2[80], derr[80], corerr[80][80];
  aleph_vplusa_(sbin, dsbin, sfm2, derr, corerr);

  double s0 = 1.9;
  int Nmax = 0;
  
  // Set Nmax to next bigger sbin
  for (int i = 80; i > 0; i--) {
    std::cout << sbin[i] << std::endl;
    if(fabs(s0-sbin[i]) < dsbin[i]/2.) {
      Nmax = i;
      // std::cout << "Nmax: " << Nmax << std::endl;
      break;
    }
  }

  // Integrate momenta up to s0
  double mom = 0.;
  for (int i=1; i < Nmax; i++) {
    mom += sfm2[i];
  }
  std::cout << "mom: " << mom << std::endl;
  
  
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


// Experiment::integrate(double s0)
// 
// Integrate over the experimental data points.
// Loop through data map.
// Find center of height between neighbouring points.
// Add rectangle (binWidht * binHeight) to integral sum.
// Compensate 1 bin for half bin at beginning at end.
    
double Experiment::integrate(double s0) {
  double result = 0;

  std::map<double, double> intMap = data;
  
  int numIntBins = 0;

  auto it = std::begin(intMap);

  for(auto end=std::end(intMap); it!=end; ++it) {
    if (it->first > s0) {
      intMap.erase(it, intMap.end() );
      break;
    }
  }

  
  it = std::begin(intMap);
  double y2, y1 = it->second;
  result += 0.5 * binWidth * y1;
  ++it;

  
  for(auto end=std::end(intMap); it!=end; ++it) {
    y2 = it->second;
    result += binWidth * (y1 + y2) / 2;
    y1 = y2;
  }

  result += 0.5 * binWidth * y2;
  
  return result;
}
