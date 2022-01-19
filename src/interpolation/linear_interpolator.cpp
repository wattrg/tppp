#include<exception>
#include<vector>
#include<iostream>
#include "linear_interpolator.h"

LinearInterpolator::LinearInterpolator(std::vector<double> & x,
                                       std::vector<double> & y)
  : x_values(x), y_values(y)
{
  if (x_values.size() != y_values.size()) {
      throw InterpolateIncompatibleSizes();
  }
  int n = x_values.size();
  x_min = x_values[0];
  x_max = x_values[n-1];
}


double linear_interpolate(double x_1, double x_2, double y_1, double y_2, double x){
  return y_1 + (y_2 - y_1) / (x_2 - x_1) * (x - x_1);
}

int LinearInterpolator::find_interp_loc(double target_x){
  for (long unsigned int i = 0; i < x_values.size(); i++){
    if (x_values[i] >= target_x) {
        return i - 1;
    }
  }
  // we failed to find the location where our interpolation should be
  return -1;
}

double LinearInterpolator::operator() (double target_x){
  check_bounds(target_x);
  int i = find_interp_loc(target_x);
  return linear_interpolate(x_values[i], x_values[i+1], y_values[i], y_values[i+1], target_x);
}
