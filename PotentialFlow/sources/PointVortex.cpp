#include "PointVortex.h"

#define _USE_MATH_DEFINES
#include <cmath>

PointVortex::PointVortex() : PointSingularityElement(0.0, 0.0, 1.0)
{
}

PointVortex::PointVortex(double iX, double iY) : PointSingularityElement(iX, iY, 1.0)
{
}

PointVortex::PointVortex(double iX, double iY, double iIntensity) : PointSingularityElement(iX, iY, iIntensity)
{
}

PointVortex::~PointVortex()
{
}

double PointVortex::potential(double iX, double iY) const
{
  double theta = atan2(iY - mY, iX - mX);
  return 0.5*mIntensity / M_PI * theta;
}

double PointVortex::flowline(double iX, double iY) const
{
  double r2 = (iX - mX) * (iX - mX) + (iY - mY) * (iY - mY);
  return -0.25*mIntensity / M_PI * log(r2);
}

double PointVortex::u(double iX, double iY) const
{
  double theta = atan2(iY - mY, iX - mX);
  double r_inv = 1.0/sqrt((iX - mX) * (iX - mX) + (iY - mY) * (iY - mY));
  return -0.5 * mIntensity * r_inv / M_PI * sin(theta);
}

double PointVortex::v(double iX, double iY) const
{
  double theta = atan2(iY - mY, iX - mX);
  double r_inv = 1.0 / sqrt((iX - mX) * (iX - mX) + (iY - mY) * (iY - mY));
  return 0.5 * mIntensity * r_inv / M_PI * cos(theta);
}

