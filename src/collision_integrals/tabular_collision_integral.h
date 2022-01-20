#ifndef TABULAR_COLLISION_INTEGRAL_H_
#define TABULAR_COLLISION_INTEGRAL_H_

#include<vector>
#include <iostream>
#include "collision_integral.h"
#include "../interpolation/interpolator.h"
#include "../interpolation/linear_interpolator.h"
#include "../interpolation/cubic_spline_interpolator.h"

class ColIntTable : public CollisionIntegral {
public:
  ColIntTable(col_int_species species, col_int_order order,
              std::vector<double> temps, std::vector<double> ci,
              interpolators interpolator=linear);

  ~ColIntTable();

  // evaluate the collision integral for a given temperature
  double eval(double temp);

  // get and set methods
  std::vector<double> get_temps();
  std::vector<double> get_cis();
  interpolators get_interp_type();
  void set_interp_type(interpolators interp);

private:
  std::vector<double> temps;
  std::vector<double> ci;
  Interpolator * interp;
  void set_interpolator(interpolators interp);
};

#endif // TABULAR_COLLISION_INTEGRAL_H_
