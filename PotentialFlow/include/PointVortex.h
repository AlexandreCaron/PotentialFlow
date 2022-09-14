#ifndef POINT_VORTEX_H
#define POINT_VORTEX_H

#pragma once
#include "PointSingularityElement.h"

class CLASS_DECLSPEC PointVortex : public virtual PointSingularityElement
{
public :
  PointVortex();
  PointVortex(double iX, double iY);
  PointVortex(double iX, double iY, double iIntensity);
  ~PointVortex();

  virtual double u(double x, double y) const;
  virtual double v(double x, double y) const;
  virtual double flowline(double x, double y) const;
  virtual double potential(double x, double y) const;

protected:
private :
};

#endif