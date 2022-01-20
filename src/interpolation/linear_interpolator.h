
#ifndef LINEAR_INTERPOLATOR_H_
#define LINEAR_INTERPOLATOR_H_

#include "interpolator.h"

class LinearInterpolator : public Interpolator {
public:
  LinearInterpolator(std::vector<double> & x, std::vector<double> & y);
  ~LinearInterpolator(){};

  // type of interpolator
  const interpolators type = linear;

protected:
  double eval_interp(double x_target, int i) override;

};

#endif // LINEAR_INTERPOLATOR_H_
