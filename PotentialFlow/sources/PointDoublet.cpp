#include "PointDoublet.h"

#define _USE_MATH_DEFINES
#include <cmath>

PointDoublet::PointDoublet() : PointSingularityElement(0.0, 0.0, 1.0)
, mAlpha(0.0)
{
}

PointDoublet::PointDoublet(double iX, double iY, double iAlpha) : PointSingularityElement(iX, iY, 1.0)
  , mAlpha(iAlpha)
{
}


PointDoublet::PointDoublet(double iX, double iY, double iAlpha, double iIntensity) : PointSingularityElement(iX, iY, iIntensity)
  , mAlpha(iAlpha)
{
}

PointDoublet::~PointDoublet()
{
}


double PointDoublet::potential(double iX, double iY) const
{
  double num = (iX - mX) * cos(mAlpha) + (iY - mY) * sin(mAlpha);
  double r2 = (iX - mX) * (iX - mX) + (iY - mY) * (iY - mY);
  return -0.5 * mIntensity / M_PI * num / r2;
}

double PointDoublet::flowline(double iX, double iY) const
{
  double num = (iY - mY) * cos(mAlpha) - (iX - mX) * sin(mAlpha);
  double r2 = (iX - mX) * (iX - mX) + (iY - mY) * (iY - mY);
  return 0.5 * mIntensity / M_PI * num / r2;
}

double PointDoublet::u(double iX, double iY) const
{
  double num = ((iX - mX) * (iX - mX) - (iY - mY) * (iY - mY)) * cos(mAlpha) + 2.0 * (iX - mX) * (iY - mY) * sin(mAlpha);
  double r2 = (iX - mX) * (iX - mX) + (iY - mY) * (iY - mY);
  return 0.5 * mIntensity / M_PI * num / (r2 * r2);
}

double PointDoublet::v(double iX, double iY) const
{
  double num = ((iY - mY) * (iY - mY) - (iX - mX) * (iX - mX)) * sin(mAlpha) + 2.0 * (iX - mX) * (iY - mY) * cos(mAlpha);
  double r2 = (iX - mX) * (iX - mX) + (iY - mY) * (iY - mY);
  return 0.5 * mIntensity / M_PI * num / (r2 * r2);
}

void PointDoublet::setAlpha(double iAlpha)
{
  mAlpha = iAlpha;
}
