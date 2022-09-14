#include <tuple>
#include "gtest/gtest.h"

#include "PointSource.h"

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

class ParametrizedPointSourceTests : public ::testing::TestWithParam<ParameterList>
{
protected:
  virtual void SetUp()
  {
    double x0 = std::get<iX0>(GetParam());
    double y0 = std::get<iY0>(GetParam());
    double intensity = std::get<iIntensity>(GetParam());

    mPointSource.setPosition(x0, y0);
    mPointSource.setIntensity(intensity);

    x = std::get<iX>(GetParam());
    y = std::get<iY>(GetParam());
  };

  PointSource mPointSource;
  double x, y;
};

TEST_P(ParametrizedPointSourceTests, potential)
{
  double wExpectedPotential = std::get<oP>(GetParam());
  double potential = mPointSource.potential(x, y);
  EXPECT_NEAR(wExpectedPotential, potential, cEpsilon);
};

TEST_P(ParametrizedPointSourceTests, flowline)
{
  double wExpectedFlowLine = std::get<oF>(GetParam());
  double flowline = mPointSource.flowline(x, y);
  EXPECT_NEAR(wExpectedFlowLine, flowline, cEpsilon);
};

TEST_P(ParametrizedPointSourceTests, u)
{
  double wExpectedU = std::get<oU>(GetParam());
  double u = mPointSource.u(x, y);
  EXPECT_NEAR(wExpectedU, u, cEpsilon);
};

TEST_P(ParametrizedPointSourceTests, v)
{
  double wExpectedV = std::get<oV>(GetParam());
  double v = mPointSource.v(x, y);
  EXPECT_NEAR(wExpectedV, v, cEpsilon);
};

INSTANTIATE_TEST_CASE_P(
  PointSourceTests,
  ParametrizedPointSourceTests,
  ::testing::Values(
    //                x0    y0   int     x     y      pot      psi        u        v
    std::make_tuple( 0.0,  0.0,  1.0,  1.0,  0.0,  0.0000,  0.0000,  0.1592,  0.0000),
    std::make_tuple( 0.0,  0.0,  1.0,  1.0,  1.0,  0.0552,  0.1250,  0.0796,  0.0796),
    std::make_tuple( 0.0,  0.0,  1.0, -5.0, -2.0,  0.2680, -0.4394, -0.0274, -0.0110),
    std::make_tuple( 0.0,  0.0,  4.0, -5.0, -2.0,  1.0718, -1.7578, -0.1098, -0.0439),
    std::make_tuple( 2.0,  0.0, -2.0, -5.0, -2.0, -0.6319,  0.9114,  0.0420,  0.0120),
    std::make_tuple( 2.0, -0.5,  2.0, -5.0, -2.0,  0.6265, -0.9328, -0.0435, -0.0093)
  )
);