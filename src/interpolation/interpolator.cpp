
#include "interpolator.h"
void Interpolator::check_bounds(double target_x){
  if ((target_x < x_min) || (target_x > x_max)) {
    throw InterpolateOutOfRangeException();
  }
}
