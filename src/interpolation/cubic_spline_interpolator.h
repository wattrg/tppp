// A cubic spline interpolation scheme from "Numerical Methods for Engineers"
// 2006 by Griffiths and Smith
#ifndef CUBIC_SPLINE_INTERPOLATOR_H_
#define CUBIC_SPLINE_INTERPOLATOR_H_

#include "interpolator.h"

class CubicSplineInterpolator : public Interpolator {
public:
  CubicSplineInterpolator(std::vector<double> & x, std::vector<double> & y);
  ~CubicSplineInterpolator(){};

  // evaluate the interpolation
  double operator() (double x_target);

  interpolators type = cubic_spline;

protected:
  double eval_interp(double x_target, int i) override;

private:
  // the seconds derivates of the spline at the data points
  std::vector<double> y_dash_dash;

  // solve for the second derivates of the spline at the data points
  void compute_y_dash_dash();

};

#endif // CUBIC_SPLINE_INTERPOLATOR_H_
