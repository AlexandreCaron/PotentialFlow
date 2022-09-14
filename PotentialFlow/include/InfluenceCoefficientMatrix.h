#ifndef INFLUENCECOEFFICIENTMATRIX_H
#define INFLUENCECOEFFICIENTMATRIX_H

#include "PotentialFlow.h"

#include "CollocationPointList.h"
#include "SingularityElementList.h"

#include "Eigen/Dense"

class CLASS_DECLSPEC InfluenceCoefficientMatrix
{
public:
  InfluenceCoefficientMatrix(const SingularityElementList& iSingularityElementList, const CollocationPointList& iCollocationPointList);
  ~InfluenceCoefficientMatrix();

private:
  const SingularityElementList& mSingularityElementList;
  const CollocationPointList& mCollocationPointList;

  void CalculateInfluenceCoefficient();

  Eigen::MatrixXd mInfluenceCoefficientMatrix;
};

#endif
