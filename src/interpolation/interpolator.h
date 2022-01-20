
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
  virtual double operator() (double x_target) = 0;

  // check the target value is within the interpolation range
  void check_bounds(double x_target);

  // the number of points being interpolated
  int n_pts;

  interpolators type;

protected:
  std::vector<double> x_values;
  std::vector<double> y_values;

  // find the position in the data to interpolate
  int find_interp_loc(double x_target);

  double x_min, x_max;

};

#endif // INTERPOLATOR_H_
