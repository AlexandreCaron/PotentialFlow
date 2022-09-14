#include "gtest/gtest.h"

#include "UniformStream.h"

const double cEpsilon = 0.01;

enum parameterIndex
{
  iU = 0,
  iV,
  iX,
  iY,
  oP,
  oF,
  oU,
  oV
};

typedef std::tuple<double, double, double, double, double, double, double, double> ParameterList;

class ParametrizedUniformStreamTests : public ::testing::TestWithParam<ParameterList>
{
protected:
  virtual void SetUp()
  {
    double wU = std::get<iU>(GetParam());
    double wV = std::get<iV>(GetParam());

    mUniformStream.setSpeed(wU, wV);

    x = std::get<iX>(GetParam());
    y = std::get<iY>(GetParam());
  }

  virtual void TearDown()
  {
  }

  UniformStream mUniformStream;
  double x, y;
};

TEST_P(ParametrizedUniformStreamTests, potential)
{
  double wExpectedPotential = std::get<oP>(GetParam());
  double potential = mUniformStream.potential(x, y);
  EXPECT_NEAR(wExpectedPotential, potential, cEpsilon);
};

TEST_P(ParametrizedUniformStreamTests, flowline)
{
  double wExpectedFlowLine = std::get<oF>(GetParam());
  double flowline = mUniformStream.flowline(x, y);
  EXPECT_NEAR(wExpectedFlowLine, flowline, cEpsilon);
};

TEST_P(ParametrizedUniformStreamTests, u)
{
  double wExpectedU = std::get<oU>(GetParam());
  double u = mUniformStream.u(x, y);
  EXPECT_NEAR(wExpectedU, u, cEpsilon);
};

TEST_P(ParametrizedUniformStreamTests, v)
{
  double wExpectedV = std::get<oV>(GetParam());
  double v = mUniformStream.v(x, y);
  EXPECT_NEAR(wExpectedV, v, cEpsilon);
};

INSTANTIATE_TEST_CASE_P(
  UniformStreamTests,
  ParametrizedUniformStreamTests,
  ::testing::Values(
    //                 u     v     x     y    pot    psi      u      v
    std::make_tuple( 0.0,  0.0,  0.0,  0.0,  0.00,  0.00,  0.00,  0.00),
    std::make_tuple( 1.0,  0.0,  0.0,  0.0,  0.00,  0.00,  1.00,  0.00),
    std::make_tuple( 1.0,  5.0,  0.0,  0.0,  0.00,  0.00,  1.00,  5.00),
    std::make_tuple( 1.0,  5.0,  1.0,  0.0,  1.00, -5.00,  1.00,  5.00),
    std::make_tuple( 3.4, -1.2,  1.2,  3.5, -0.12, 13.34,  3.40, -1.20)
  )
);