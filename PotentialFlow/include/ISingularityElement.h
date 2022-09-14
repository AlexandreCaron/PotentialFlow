#ifndef ISINGULARITYELEMENT_H
#define ISINGULARITYELEMENT_H

#include "PotentialFlow.h"

class ISingularityElement
{
public:
  virtual double potential(double x, double y) const = 0;
  virtual double flowline(double x, double y) const = 0;
  virtual double u(double x, double y) const = 0;
  virtual double v(double x, double y) const = 0;
protected:
private:
};

#endif