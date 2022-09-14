#include "PointSingularityElement.h"

#define _USE_MATH_DEFINES
#include <cmath>

PointSingularityElement::PointSingularityElement(double iX, double iY, double iIntensity)
  :mX(iX)
  , mY(iY)
  , mIntensity(iIntensity)
{
}

PointSingularityElement::~PointSingularityElement()
{
}

void PointSingularityElement::setPosition(double iX, double iY)
{
  mX = iX;
  mY = iY;
}

void PointSingularityElement::setIntensity(double iIntensity)
{
  mIntensity = iIntensity;
}