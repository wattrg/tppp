#include <vector>
#include <iostream>
#include "collision_integrals/tabular_collision_integral.h"
#include "interpolation/linear_interpolator.h"
#include "interpolation/interpolator.h"
#include "collision_integrals/collision_integral.h"

int main(int argc, char *argv[]) {
  std::cout << "Welcome to tppp!" << std::endl;
  std::vector<double> x = {1.0, 2.0, 4.0, 5.0, 10.0};
  std::vector<double> y = {1.0, 4.0, 16.0, 25.0, 100.0};
  //std::vector<double> y = {1.0, 4.0, 4.0, 5.0, 10.0};
  col_int_species species = std::make_tuple("N2", "N2");
  col_int_order order = std::make_tuple(1, 1);
  ColIntTable ci = ColIntTable(species, order, x, y, cubic_spline);
  std::cout << ci.eval(4.999) << std::endl;
  return 0;
}
