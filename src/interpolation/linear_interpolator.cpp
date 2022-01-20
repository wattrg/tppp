#include<exception>
#include<vector>
#include<iostream>
#include "linear_interpolator.h"

LinearInterpolator::LinearInterpolator(std::vector<double> & x,
                                       std::vector<double> & y)
  : Interpolator(x, y)
{
}


double linear_interpolate(double x_1, double x_2, double y_1, double y_2, double x){
  return y_1 + (y_2 - y_1) / (x_2 - x_1) * (x - x_1);
}


double LinearInterpolator::operator() (double target_x){
  check_bounds(target_x);
  int i = find_interp_loc(target_x);
  return linear_interpolate(x_values[i], x_values[i+1], y_values[i], y_values[i+1], target_x);
}
