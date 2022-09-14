#include "CollocationPointList.h"


CollocationPointList::CollocationPointList()
{

}

CollocationPointList::~CollocationPointList()
{

}

void CollocationPointList::addCollocationPoint(double x, double y, double nx, double ny)
{
  double wInvNorm = 1.0 / (nx * nx + ny * ny);
  mElementVector.push_back(std::make_shared<CollocationPoint>(x, y, nx * wInvNorm, ny* wInvNorm));
}

void CollocationPointList::addCollocationPoint(double x, double y, double beta)
{
  mElementVector.push_back(std::make_shared<CollocationPoint>(x, y, cos(beta), sin(beta)));
}

size_t CollocationPointList::size() const
{
  return mElementVector.size();
}

std::shared_ptr<CollocationPoint> CollocationPointList::operator[](int i) const
{
  return mElementVector.at(i);
}