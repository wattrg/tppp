#include<exception>
#include "tabular_collision_integral.h"
#include <iostream>


ColIntTable::ColIntTable(col_int_species species, col_int_order order,
                         std::vector<double> temps, std::vector<double> ci,
                         interpolators interpolator)
  : CollisionIntegral(species, order), temps(temps), ci(ci)
{
  set_interpolator(interpolator);
}

void ColIntTable::set_interpolator(interpolators interpolator){
  switch (interpolator) {
    case linear:
      this->interp = new LinearInterpolator(temps, ci);
      break;
    case cubic_spline:
      this->interp = new CubicSplineInterpolator(temps, ci);
      break;
    default:
      throw new std::exception();
  }
}

ColIntTable::~ColIntTable() {
  free(interp);
}


double ColIntTable::eval(double temp) {
  return interp->eval(temp);
}

std::vector<double> ColIntTable::get_temps() {
  return temps;
}

std::vector<double> ColIntTable::get_cis() {
  return ci;
}

interpolators ColIntTable::get_interp_type() {
  return interp->type;
}

void ColIntTable::set_interp_type(interpolators interpolator) {
  free(interp);
  set_interpolator(interpolator);
}
