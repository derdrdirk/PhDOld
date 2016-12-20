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
  int nrflag = 0; // either 0 or 1? check what does defined in Fortran code
  map<double, double> data;
  for(double e=startEnergy; e<=endEnergy; e= e+stepSize) {
      vphlmntv2_(&e, &vprehadsp, &vprehadtm, &vpimhad, &vprelepsp, &vpreleptm, &vpimlep, &vpretopsp, &vpretoptm, &nrflag);
      data[e] = vpimhad;	
  }
  return data;
}


int main()
{
  map<double, double> data = getData(0.5, 2.5, 1000);

  for(auto const& ent : data) {
    cout << ent.first << " " << ent.second << endl;
  }
    
  return 0;
}
