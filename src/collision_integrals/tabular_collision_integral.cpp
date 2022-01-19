#include<exception>
#include "tabular_collision_integral.h"
#include <iostream>

ColIntTable::ColIntTable(std::vector<double> temps, std::vector<double> ci,
                         interpolators interpolator)
  : temps(temps), ci(ci)
{
  switch (interpolator) {
    case linear:
      interp = new LinearInterpolator(temps, ci);
      break;
    default:
      throw new std::exception();
  }
}

ColIntTable::~ColIntTable() {}

double ColIntTable::eval(double temp) {
  return (*interp)(temp);
}

std::vector<double> ColIntTable::get_temps() {
  return temps;
}

std::vector<double> ColIntTable::get_cis() {
  return ci;
}
