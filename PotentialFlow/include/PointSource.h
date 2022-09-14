#ifndef POINT_SOURCE_H
#define POINT_SOURCE_H

#include "PointSingularityElement.h"

class CLASS_DECLSPEC PointSource : public virtual PointSingularityElement
{
public :
  PointSource();
  PointSource(double iX, double iY);
  PointSource(double iX, double iY, double iIntensity);
  ~PointSource();

  virtual double u(double x, double y) const;
  virtual double v(double x, double y) const;
  virtual double potential(double x, double y) const;
  virtual double flowline(double x, double y) const;

protected:
private :
};

#endif
