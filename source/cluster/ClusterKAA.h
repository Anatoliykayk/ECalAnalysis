//ROOT CERN
#include "TVector3.h"
#include "TLorentzVector.h"
//MPDROOT
#include "/lhep/users/dblau/opt/mpdroot/emc/emcKI/MpdEmcClusterKI.h"

class ClusterKAA
{
 public:
  ClusterKAA();
  ClusterKAA(MpdEmcClusterKI* cluster);
  
  TVector3 GetXYZ() const;
  double GetDZ() const;
  double GetDPhi() const;
  double GetTime() const;
  void GetDisp(float &disp_long, float &disp_short) const;
  int GetMultiplicity() const;
  double GetR() const;
  double GetRhi() const;
  TLorentzVector GetMomentum() const;
  
 private:
  double x, y, z;
  double dz, dphi;
  double t, dt, dt_blur;
  float disp_long, disp_short;  
};
