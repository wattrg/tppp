#include<vector>
#include "interpolator.h"

#ifndef LINEAR_INTERPOLATOR_H_
#define LINEAR_INTERPOLATOR_H_

class LinearInterpolator : public Interpolator {
public:
  LinearInterpolator(std::vector<double> & x, std::vector<double> & y);
  ~LinearInterpolator(){};

  // evaluate the interpolation
  double operator()(double x_target);

protected:
  // the data to interpolate
  // assumes that x_values are sorted from lowest to highest
  std::vector<double> x_values;
  std::vector<double> y_values;

  // find the position in the data to interpolate
  int find_interp_loc(double x_target);
};

#endif // LINEAR_INTERPOLATOR_H_
