#ifndef POINTDOUBLET_H
#define POINTDOUBLET_H

#include "PointSingularityElement.h"

class CLASS_DECLSPEC PointDoublet : public virtual PointSingularityElement
{
public :
  PointDoublet();
  PointDoublet(double iX, double iY, double iAlpha);
  PointDoublet(double iX, double iY, double iAlpha, double iIntensity);
  ~PointDoublet();

  virtual double u(double x, double y) const;
  virtual double v(double x, double y) const;
  virtual double flowline(double x, double y) const;
  virtual double potential(double x, double y) const;

  void setAlpha(double iAlpha);
protected:
private :
  double mAlpha;
};

#endif