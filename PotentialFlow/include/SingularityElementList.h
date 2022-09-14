#ifndef SINGULARITYELEMENTLIST_H
#define SINGULARITYELEMENTLIST_H

#include "PointSingularityElement.h"
#include "ISingularityElement.h"

#include <vector>
#include <memory>

class SingularityElementList : ISingularityElement
{
public:
  CLASS_DECLSPEC SingularityElementList();
  CLASS_DECLSPEC ~SingularityElementList();

  void CLASS_DECLSPEC addSource(double x0, double y0, double intensity);
  void CLASS_DECLSPEC addDoublet(double x0, double y0, double alpha, double intensity);
  void CLASS_DECLSPEC addVortex(double x0, double y0, double intensity);
  void CLASS_DECLSPEC addUniformStream(double u, double v);

  double CLASS_DECLSPEC potential(double x, double y) const;
  double CLASS_DECLSPEC flowline(double x, double y) const;
  double CLASS_DECLSPEC u(double x, double y) const;
  double CLASS_DECLSPEC v(double x, double y) const;

  size_t CLASS_DECLSPEC size() const;
  std::shared_ptr<ISingularityElement> CLASS_DECLSPEC operator[](int i) const;

protected:
private:
  std::vector<std::shared_ptr<ISingularityElement>> mElementVector;
};

#endif