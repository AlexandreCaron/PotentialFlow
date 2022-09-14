#include "gtest/gtest.h"

#include "PointVortex.h"

const double cEpsilon = 0.01;

enum parameterIndex
{
  iX0 = 0,
  iY0,
  iIntensity,
  iX,
  iY,
  oP,
  oF,
  oU,
  oV
};

typedef std::tuple<double, double, double, double, double, double, double, double, double> ParameterList;

class ParametrizedPointVortexTests : public ::testing::TestWithParam<ParameterList>
{
protected:
  virtual void SetUp()
  {
    double x0 = std::get<iX0>(GetParam());
    double y0 = std::get<iY0>(GetParam());
    double intensity = std::get<iIntensity>(GetParam());

    mPointVortex.setPosition(x0, y0);
    mPointVortex.setIntensity(intensity);

    x = std::get<iX>(GetParam());
    y = std::get<iY>(GetParam());
  }

  virtual void TearDown()
  {
  }

  PointVortex mPointVortex;
  double x, y;
};

TEST_P(ParametrizedPointVortexTests, potential)
{
  double wExpectedPotential = std::get<oP>(GetParam());
  double potential = mPointVortex.potential(x, y);
  EXPECT_NEAR(wExpectedPotential, potential, cEpsilon);
};

TEST_P(ParametrizedPointVortexTests, flowline)
{
  double wExpectedFlowLine = std::get<oF>(GetParam());
  double flowline = mPointVortex.flowline(x, y);
  EXPECT_NEAR(wExpectedFlowLine, flowline, cEpsilon);
};

TEST_P(ParametrizedPointVortexTests, u)
{
  double wExpectedU = std::get<oU>(GetParam());
  double u = mPointVortex.u(x, y);
  EXPECT_NEAR(wExpectedU, u, cEpsilon);
};

TEST_P(ParametrizedPointVortexTests, v)
{
  double wExpectedV = std::get<oV>(GetParam());
  double v = mPointVortex.v(x, y);
  EXPECT_NEAR(wExpectedV, v, cEpsilon);
};

INSTANTIATE_TEST_CASE_P(
  PointVortexTests,
  ParametrizedPointVortexTests,
  ::testing::Values(
    //                x0    y0   int     x     y      pot      psi        u        v
    std::make_tuple( 0.0,  0.0,  1.0,  1.0,  0.0,  0.0000,  0.0000,  0.0000,  0.1592),
    std::make_tuple( 0.0,  0.0,  1.0,  1.0,  1.0,  0.1250, -0.0552, -0.0796,  0.0796),
    std::make_tuple( 0.0,  0.0,  1.0, -5.0, -2.0, -0.4394, -0.2680,  0.0110, -0.0274),
    std::make_tuple( 0.0,  0.0,  4.0, -5.0, -2.0, -1.7578, -1.0718,  0.0439, -0.1098),
    std::make_tuple( 2.0,  0.0, -2.0, -5.0, -2.0,  0.9114,  0.6319, -0.0120,  0.0420),
    std::make_tuple( 2.0, -0.5,  2.0, -5.0, -2.0, -0.9328, -0.6265,  0.0093, -0.0435)
  )
);