#include <vector>
#include <iostream>
#include "collision_integrals/tabular_collision_integral.h"
#include "interpolation/linear_interpolator.h"
#include "interpolation/interpolator.h"

int main(int argc, char *argv[]) {
  std::cout << "Welcome to tppp!" << std::endl;
  std::vector<double> x = {1.0, 2.0, 4.0};
  std::vector<double> y = {3.0, 6.0, 7.0};
  ColIntTable ci = ColIntTable(x, y);
  std::cout << ci.eval(3.0) << std::endl;
  return 0;
}
