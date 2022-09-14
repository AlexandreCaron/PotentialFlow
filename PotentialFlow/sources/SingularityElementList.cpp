#include "SingularityElementList.h"

#include "PointSource.h"
#include "PointDoublet.h"
#include "PointVortex.h"
#include "UniformStream.h"

SingularityElementList::SingularityElementList()
{
}

SingularityElementList::~SingularityElementList()
{
}

void SingularityElementList::addSource(double x0, double y0, double intensity)
{
  std::shared_ptr<PointSource> wPointSource = std::make_shared<PointSource>(x0, y0, intensity);
  mElementVector.push_back(std::move(wPointSource));
}

void SingularityElementList::addDoublet(double x0, double y0, double alpha, double intensity)
{
  std::shared_ptr<PointDoublet> wPointDoublet = std::make_shared<PointDoublet>(x0, y0, alpha, intensity);
  mElementVector.push_back(std::move(wPointDoublet));
}

void SingularityElementList::addVortex(double x0, double y0, double intensity)
{
  std::shared_ptr<PointVortex> wPointVortex = std::make_shared<PointVortex>(x0,y0,intensity);
  mElementVector.push_back(std::move(wPointVortex));
}

void SingularityElementList::addUniformStream(double u, double v)
{
  std::shared_ptr<UniformStream> wUniformStream = std::make_shared<UniformStream>(u, v);
  mElementVector.push_back(std::move(wUniformStream));
}

double SingularityElementList::potential(double x, double y) const
{
  double potential = 0.0;
  for (auto & it : mElementVector) {
    potential += it->potential(x,y);
  }
  return potential;
}

double SingularityElementList::flowline(double x, double y) const
{
  double flowline = 0.0;
  for (auto& it : mElementVector) {
    flowline += it->flowline(x, y);
  }
  return flowline;
}

double SingularityElementList::u(double x, double y) const
{
  double u = 0.0;
  for (auto& it : mElementVector) {
    u += it->u(x, y);
  }
  return u;
}

double SingularityElementList::v(double x, double y) const
{
  double v = 0.0;
  for (auto& it : mElementVector) {
    v += it->v(x, y);
  }
  return v;
}

size_t SingularityElementList::size() const
{
  return mElementVector.size();
}


std::shared_ptr<ISingularityElement> SingularityElementList::operator[](int i) const
{
  return mElementVector.at(i);
}