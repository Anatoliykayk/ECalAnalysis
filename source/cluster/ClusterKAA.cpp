#include "ClusterKAA.h"

ClusterKAA::ClusterKAA()
  : x{9999}, y{9999}, z{9999},
  dz{9999}, dphi{9999},
  t{9999}, dt{9999}, dt_blur{9999},
  disp_long{9999}, disp_short{9999}
{
}

ClusterKAA::ClusterKAA(MpdEmcClusterKI* cluster)
  : x{ cluster.GetX() },
  y{ cluster.GetY() },
  z{ cluster.GetZ() },
  dz{ cluster.GetDZ() },
  dphi{ cluster.GetDPhi() },
  t{ 9999 },
  dt{ 9999 },
  dt_blur{ 9999 }
{
  cluster -> GetLambdas( disp_long, disp_short );
}

TVector3 ClusterKAA::GetXYZ() const
{
  TVector3 vecXYZ(x, y, z);
  return vecXYZ;
}

double ClusterKAA::GetDZ() const
{
  return dz;
}

double ClusterKAA::GetDPhi() const
{
  return dphi;
}

void ClusterKAA::GetDisp(float  &disp_long, float &disp_short) const
{
  disp_long = this -> disp_long;
  disp_short = this -> disp_short;
}
