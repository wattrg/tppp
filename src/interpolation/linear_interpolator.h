
#ifndef LINEAR_INTERPOLATOR_H_
#define LINEAR_INTERPOLATOR_H_

#include "interpolator.h"

class LinearInterpolator : public Interpolator {
public:
  LinearInterpolator(std::vector<double> & x, std::vector<double> & y);
  ~LinearInterpolator(){};

  // evaluate the interpolation
  double operator()(double x_target);

  // type of interpolator
  interpolators type = linear;

};

#endif // LINEAR_INTERPOLATOR_H_
