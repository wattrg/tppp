#include "interpolator.h"

Interpolator::Interpolator(std::vector<double> x, std::vector<double> y)
  : x_values(x), y_values(y)
{
  n_pts = x_values.size();
  x_min = x_values[0];
  x_max = x_values[n_pts-1];
  if (x_values.size() != y_values.size()) {
      throw InterpolateIncompatibleSizes();
  }
};

void Interpolator::check_bounds(double target_x){
  if ((target_x < x_min) || (target_x > x_max)) {
    throw InterpolateOutOfRangeException();
  }
}

int Interpolator::find_interp_loc(double target_x){
  for (long unsigned int i = 0; i < x_values.size(); i++){
    if (x_values[i] >= target_x) {
        return i - 1;
    }
  }
  // we failed to find the location where our interpolation should be
  return -1;
}

double Interpolator::eval(double x_target) {
  check_bounds(x_target);
  int i = find_interp_loc(x_target);
  return eval_interp(x_target, i);
}

const std::string Interpolator::get_type_string() {
  switch (type) {
    case linear:
      return "linear";
      break;
    case cubic_spline:
      return "cubic_spline";
      break;
    default:
      return "NA";
      break;
  }
}
