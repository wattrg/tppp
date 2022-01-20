
#ifndef INTERPOLATOR_H_
#define INTERPOLATOR_H_

#include <exception>
#include <iostream>
#include <vector>
#include "interpolate_errors.h"

enum interpolators {
  linear,
  cubic_spline,
};


class Interpolator {
public:
  // constructor
  Interpolator(std::vector<double> x, std::vector<double> y);

  ~Interpolator(){};

  // evaluate the interpolation
  double eval(double x_target);

  // The type of the interpolation
  interpolators type;

protected:
  // The values to interpolate
  std::vector<double> x_values;
  std::vector<double> y_values;

  // The actual implementation of the interpolation goes in here
  virtual double eval_interp(double x_target, int i) = 0;

  // the number of points being interpolated
  int n_pts;

private:
  // check the target value is within the interpolation range
  void check_bounds(double x_target);

  // find the position in the data to interpolate
  int find_interp_loc(double x_target);

  // interpolation range
  double x_min, x_max;
};

#endif // INTERPOLATOR_H_
