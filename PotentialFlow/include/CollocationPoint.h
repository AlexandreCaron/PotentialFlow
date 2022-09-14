#ifndef COLLOCATIONPOINT_H
#define COLLOCATIONPOINT_H

#include "PotentialFlow.h"

class CLASS_DECLSPEC CollocationPoint
{
public:
  CollocationPoint();
  CollocationPoint(double iX, double iY);
  CollocationPoint(double iX, double iY, double iNx, double iNy);
  ~CollocationPoint();

  double x() const;
  double y() const;
  double Nx() const;
  double Ny() const;

protected:
private:
  double mX, mY;
  double mNx, mNy;
};

#endif
