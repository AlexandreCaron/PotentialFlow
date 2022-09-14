#include <iostream>
#include "SingularityElementList.h"
#include "CollocationPointList.h"
#include "InfluenceCoefficientMatrix.h"

int main(int argc, char* argv[])
{
  double c = 1;
  double qinf = 10;
  double alpha = 3.1416 / 24;

  SingularityElementList mVariableSingularityElementList;
  SingularityElementList mFixedSingularityElementList;
  CollocationPointList mCollocationPointList;

  // Free stream
  mFixedSingularityElementList.addUniformStream(qinf * cos(alpha), qinf * sin(alpha));

  // Vortex elements
  mVariableSingularityElementList.addVortex(1 * c / 8, 0, 1);
  mVariableSingularityElementList.addVortex(5 * c / 8, 0, 1);

  // Collocation points
  mCollocationPointList.addCollocationPoint(3 * c / 8, 0, 0, 1);
  mCollocationPointList.addCollocationPoint(7 * c / 8, 0, 0, 1);

  // Influence coefficient
  InfluenceCoefficientMatrix mInfluenceCoefficientMatrix(mVariableSingularityElementList, mCollocationPointList);

  return 0;
}