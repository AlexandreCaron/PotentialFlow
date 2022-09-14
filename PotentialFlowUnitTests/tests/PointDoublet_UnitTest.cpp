#include "gtest/gtest.h"

#include "PointDoublet.h"

const double cEpsilon = 0.01;

enum parameterIndex
{
  iX0 = 0,
  iY0,
  iIntensity,
  iAlpha,
  iX,
  iY,
  oP,
  oF,
  oU,
  oV
};

typedef std::tuple<double, double, double, double, double, double, double, double, double, double> ParameterList;

class ParametrizedPointDoubletTests : public ::testing::TestWithParam<ParameterList>
{
protected:
  virtual void SetUp()
  {
    double x0 = std::get<iX0>(GetParam());
    double y0 = std::get<iY0>(GetParam());
    double intensity = std::get<iIntensity>(GetParam());
    double alpha = std::get<iAlpha>(GetParam());

    mPointDoublet.setPosition(x0, y0);
    mPointDoublet.setIntensity(intensity);
    mPointDoublet.setAlpha(alpha);

    x = std::get<iX>(GetParam());
    y = std::get<iY>(GetParam());
  }

  virtual void TearDown()
  {
  }

  PointDoublet mPointDoublet;
  double x, y;
};

TEST_P(ParametrizedPointDoubletTests, potential)
{
  double wExpectedPotential = std::get<oP>(GetParam());
  double potential = mPointDoublet.potential(x, y);
  EXPECT_NEAR(wExpectedPotential, potential, cEpsilon);
};

TEST_P(ParametrizedPointDoubletTests, flowline)
{
  double wExpectedFlowLine = std::get<oF>(GetParam());
  double flowline = mPointDoublet.flowline(x, y);
  EXPECT_NEAR(wExpectedFlowLine, flowline, cEpsilon);
};

TEST_P(ParametrizedPointDoubletTests, u)
{
  double wExpectedU = std::get<oU>(GetParam());
  double u = mPointDoublet.u(x, y);
  EXPECT_NEAR(wExpectedU, u, cEpsilon);
};

TEST_P(ParametrizedPointDoubletTests, v)
{
  double wExpectedV = std::get<oV>(GetParam());
  double v = mPointDoublet.v(x, y);
  EXPECT_NEAR(wExpectedV, v, cEpsilon);
};

INSTANTIATE_TEST_CASE_P(
  PointDoubletTests,
  ParametrizedPointDoubletTests,
  ::testing::Values(
    //                x0    y0   int  alp    x    y      pot      psi        u        v
    std::make_tuple( 0.0,  0.0,  1.0, 0.0, 1.0, 0.0, -0.1592,  0.0000,  0.1592,  0.0000),
    std::make_tuple( 0.0,  0.0,  1.0, 0.0, 1.0, 2.0, -0.0318,  0.0637, -0.0191,  0.0255),
    std::make_tuple( 0.0,  0.0,  3.0, 0.0, 1.0, 2.0, -0.0955,  0.1910, -0.0573,  0.0764),
    std::make_tuple( 0.0,  0.0,  3.0, 2.0, 1.0, 2.0, -0.1339, -0.1663,  0.0933,  0.0203),
    std::make_tuple(-3.0,  0.0,  3.0, 2.0, 1.0, 2.0, -0.0037, -0.1067,  0.0114, -0.0210)
  )
);
