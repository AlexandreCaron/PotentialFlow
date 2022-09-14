#include "PointSource.h"

#define _USE_MATH_DEFINES
#include <cmath>

PointSource::PointSource() : PointSingularityElement(0.0, 0.0, 1.0)
{

}

PointSource::PointSource(double iX, double iY) : PointSingularityElement(iX, iY, 1.0)
{
}

PointSource::PointSource(double iX, double iY, double iIntensity) : PointSingularityElement(iX, iY, iIntensity)
{
}


PointSource::~PointSource()
{

}


double PointSource::potential(double iX, double iY) const
{
  double r2 = (iX - mX) * (iX - mX) + (iY - mY) * (iY - mY);
  return 0.25 * mIntensity / M_PI * log(r2);
}


double PointSource::flowline(double iX, double iY) const
{
  double theta = atan2(iY - mY, iX - mX);
  return 0.5 * mIntensity / M_PI * theta;
}


double PointSource::u(double iX, double iY) const
{
  double r2 = (iX - mX) * (iX - mX) + (iY - mY) * (iY - mY);
  return 0.5 * mIntensity / M_PI * (iX - mX) / r2;
}


double PointSource::v(double iX, double iY) const
{
  double r2 = (iX - mX) * (iX - mX) + (iY - mY) * (iY - mY);
  return 0.5 * mIntensity / M_PI * (iY - mY) / r2;
}

