#include "cubic_spline_interpolator.h"

CubicSplineInterpolator::CubicSplineInterpolator(std::vector<double> & x, std::vector<double> & y)
: Interpolator(x, y)
{
  if (n_pts < 4) {
      throw InterpolateInsufficientPoints();
  }
  y_dash_dash = std::vector<double>(n_pts, 0.0);
  compute_y_dash_dash();
}

void print_vector(std::vector<double> vec){
  std::cout << "[";
  for (auto i: vec) {
    std::cout << i << ", ";
  }
  std::cout << "]" << std::endl;
}

void CubicSplineInterpolator::compute_y_dash_dash(){
  // This funcion computes the required information for interpolating
  // points using a cubic spline interpolation scheme.
  // Note since the matrix equation we're solving is symmetrical and tridiagonal
  // we can represent the matrix with two vectos (one for the diagonal and
  // another for the off diagonals)
  // Also note we have n-2 equations, where n is the number of points, and solving
  // for n-2 unknown second derivates. The final two conditions are applied later
  int n_eqn = n_pts - 2;
  std::vector<double> diag(n_eqn, 0.0);
  std::vector<double> upper(n_eqn-1, 0.0);
  std::vector<double> rhs(n_eqn, 0.0);

  // Fill in the arrays to set up the system of equations
  double delta_xi, delta_yi;
  for (int i=0; i <= n_eqn; i++){
    delta_xi = x_values[i+1] - x_values[i];
    delta_yi = y_values[i+1] - y_values[i];

    if (i != n_eqn) {
        diag[i] += delta_xi;
        rhs[i] -= delta_yi / delta_xi;
    }

    if (i == 0) { continue; }

    rhs[i-1] += delta_yi / delta_xi;
    diag[i-1] += delta_xi;
    upper[i-1] += delta_xi;
  }
  for (auto& i: rhs) { i *= 6; }
  for (auto& i: diag) { i *= 2; }

  // now use the Thomas algorithm to solve the system of equations
  // https://en.wikipedia.org/wiki/Tridiagonal_matrix_algorithm
  //
  // Sweep forward, eliminating bottom diagonal
  double w;
  for (int i = 1; i < n_eqn; i++){
    w = upper[i-1] / diag[i-1];
    diag[i] = diag[i] - w * upper[i-1];
    rhs[i] = rhs[i] - w * rhs[i-1];
  }

  // back substitution. Note that the indexing of y_dash_dash includes the
  // boundary nodes, whereas the indexing of rhs, diag, and upper
  // doesn't include these nodes.
  y_dash_dash[n_pts-2] = rhs[n_eqn-1] / diag[n_eqn-1];
  for (int i = n_eqn-2; i >= 0; i--){
    y_dash_dash[i+1] = (rhs[i] - upper[i] * y_dash_dash[i+2]) / diag[i];
  }
}

double CubicSplineInterpolator::operator() (double x_target){
  check_bounds(x_target);
  int i = find_interp_loc(x_target);
  double dx_plus = x_values[i+1] - x_target;
  double dx_minus = x_target - x_values[i];
  double delta_xi = x_values[i+1] - x_values[i];
  double a = (y_dash_dash[i] * dx_plus*dx_plus*dx_plus +
              y_dash_dash[i+1] * dx_minus*dx_minus*dx_minus)/(6 * delta_xi);
  double b = (y_values[i] / delta_xi - y_dash_dash[i] * delta_xi / 6) * dx_plus;
  double c = (y_values[i+1]/delta_xi - y_dash_dash[i+1] * delta_xi / 6) * dx_minus;
  return a + b + c;
}
