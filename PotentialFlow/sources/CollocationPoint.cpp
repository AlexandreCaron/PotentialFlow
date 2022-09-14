#include "CollocationPoint.h"


CollocationPoint::CollocationPoint()
  :mX(0.0)
  , mY(0.0)
  , mNx(0.0)
  , mNy(0.0)
{
}

CollocationPoint::CollocationPoint(double iX, double iY)
  :mX(iX)
  , mY(iY)
  , mNx(0.0)
  , mNy(0.0)
{
}

CollocationPoint::CollocationPoint(double iX, double iY, double iNx, double iNy)
  :mX(iX)
  , mY(iY)
  , mNx(iNx)
  , mNy(iNy)
{
}

CollocationPoint::~CollocationPoint()
{
}

double CollocationPoint::x() const
{
  return mX;
}

double CollocationPoint::y() const
{
  return mY;
}

double CollocationPoint::Nx() const
{
  return mNx;
}

double CollocationPoint::Ny() const
{
  return mNy;
}