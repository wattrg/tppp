#include<vector>
#include "collision_integral.h"
#include "../interpolation/interpolator.h"
#include "../interpolation/linear_interpolator.h"

#ifndef TABULAR_COLLISION_INTEGRAL_H_
#define TABULAR_COLLISION_INTEGRAL_H_

class ColIntTable : public CollisionIntegral {
public:
  ColIntTable(std::vector<double> temps, std::vector<double> ci, interpolators interpolator=linear);
  ~ColIntTable();

  // evaluate the collision integral for a given temperature
  double eval(double temp);

  std::vector<double> get_temps();
  std::vector<double> get_cis();

private:
  std::vector<double> temps;
  std::vector<double> ci;
  Interpolator * interp;
};

#endif // TABULAR_COLLISION_INTEGRAL_H_
