#include "UniformStream.h"

UniformStream::UniformStream()
  :mU(0.0)
  , mV(0.0)
{

}

UniformStream::UniformStream(double iU, double iV)
  :mU(iU)
  ,mV(iV)
{

}

UniformStream::~UniformStream()
{

}

double UniformStream::u(double x, double y) const
{
  return mU;
}

double UniformStream::v(double x, double y) const
{
  return mV;
}

double UniformStream::potential(double x, double y) const
{
  return mU * x + mV * y;
}

double UniformStream::flowline(double x, double y) const
{
  return -mV * x + mU * y;
}

void UniformStream::setSpeed(double iU, double iV)
{
  mU = iU;
  mV = iV;
}

