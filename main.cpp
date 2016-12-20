#include <iostream>
#include <map>

using namespace std;

extern"C" {
    double vphlmntv2_(double *energy, double *vprehadsp, double *vprehadtm, double *vpimhad, double *vprelepsp, double *vpreleptm, double *vpimlep, double *vpretopsp, double *vpretoptm, int *nrflag);
}

map<double, double> getData(double startEnergy, double endEnergy, int dataPoints)
{
  double stepSize = (endEnergy - startEnergy) / dataPoints;
  double energy, vprehadsp, vprehadtm, vpimhad, vprelepsp, vpreleptm, vpimlep, vpretopsp, vpretoptm;
  int nrflag;
  map<double, double> data;
  for(double e=startEnergy; e<=endEnergy; e= e+stepSize) {
      data[e] = vphlmntv2_(&e, &vprehadsp, &vprehadtm, &vpimhad, &vprelepsp, &vpreleptm, &vpimlep, &vpretopsp, &vpretoptm, &nrflag);
  }
  return data;
}


int main()
{
    double energy, vprehadsp, vprehadtm, vpimhad, vprelepsp, vpreleptm, vpimlep, vpretopsp, vpretoptm;
    int nrflag = 0;
    energy = 3;
    
    vphlmntv2_(&energy, &vprehadsp, &vprehadtm, &vpimhad, &vprelepsp, &vpreleptm, &vpimlep, &vpretopsp, &vpretoptm, &nrflag);


    cout << energy << " " << vpimhad << endl;
    
    map <double, double>test;
    test[3.3] = 4.4;

    cout << test[3.3] << endl;
    
    return 0;
}
