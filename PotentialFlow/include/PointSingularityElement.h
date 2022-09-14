#ifndef POINTSINGULARITYELEMENT_H
#define POINTSINGULARITYELEMENT_H

#include "PotentialFlow.h"

#include "ISingularityElement.h"
class CLASS_DECLSPEC PointSingularityElement : public virtual ISingularityElement
{
public:
  PointSingularityElement(double iX, double iY, double iIntensity);
  ~PointSingularityElement();

  void setPosition(double iX, double iY);
  void setIntensity(double iIntensity);
protected:
  double mX;
  double mY;
  double mIntensity;
private:
};

#endif