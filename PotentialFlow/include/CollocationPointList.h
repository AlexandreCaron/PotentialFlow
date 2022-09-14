#ifndef COLLOCATIONPOINTLIST_H
#define COLLOCATIONPOINTLIST_H

#include "PotentialFlow.h"

#include <vector>
#include <memory>

#include "CollocationPoint.h"

class CollocationPointList
{
public:
  CLASS_DECLSPEC CollocationPointList();
  CLASS_DECLSPEC ~CollocationPointList();

  void CLASS_DECLSPEC addCollocationPoint(double x, double y, double nx, double ny);
  void CLASS_DECLSPEC addCollocationPoint(double x, double y, double beta);

  std::shared_ptr<CollocationPoint> operator[](int i) const;

  size_t CLASS_DECLSPEC size() const;

protected:
private:
  std::vector<std::shared_ptr<CollocationPoint>> mElementVector;
};

#endif
