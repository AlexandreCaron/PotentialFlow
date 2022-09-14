#ifndef UNIFORMSTREAM_H
#define UNIFORMSTREAM_H

#include "ISingularityElement.h"

class CLASS_DECLSPEC UniformStream : public virtual ISingularityElement
{
public:
  UniformStream();
  UniformStream(double iU, double iV);
  ~UniformStream();

  virtual double u(double x, double y) const;
  virtual double v(double x, double y) const;
  virtual double potential(double x, double y) const;
  virtual double flowline(double x, double y) const;

  void setSpeed(double iU, double iV);
private:
  double mU;
  double mV;
};

#endif
