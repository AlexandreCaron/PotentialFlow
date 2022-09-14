#include "InfluenceCoefficientMatrix.h"

InfluenceCoefficientMatrix::InfluenceCoefficientMatrix(const SingularityElementList& iSingularityElementList, const CollocationPointList& iCollocationPointList)
  :mSingularityElementList(iSingularityElementList)
  , mCollocationPointList(iCollocationPointList)
{
  CalculateInfluenceCoefficient();
}

InfluenceCoefficientMatrix::~InfluenceCoefficientMatrix()
{

}


void InfluenceCoefficientMatrix::CalculateInfluenceCoefficient()
{
  size_t wSingularityElementSize =  mSingularityElementList.size();
  size_t wCollocationPointSize = mCollocationPointList.size();
  mInfluenceCoefficientMatrix.resize(wSingularityElementSize, wCollocationPointSize);
  for (int i = 0; i < wSingularityElementSize; i++)
  {
    for (int j = 0; j < wCollocationPointSize; j++)
    {
      double x_j = mCollocationPointList[j]->x();
      double y_j = mCollocationPointList[j]->y();
      double u_ij = mSingularityElementList[i]->u(x_j, y_j);
      double v_ij = mSingularityElementList[i]->v(x_j, y_j);
      double Nx_j = mCollocationPointList[j]->Nx();
      double Ny_j = mCollocationPointList[j]->Ny();

      mInfluenceCoefficientMatrix(i, j) = u_ij * Nx_j + v_ij * Ny_j;
    }
  }
}