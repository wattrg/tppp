#include <exception>
#include <iostream>
#include <vector>

#ifndef INTERPOLATOR_H_
#define INTERPOLATOR_H_

enum interpolators {
  linear,
};

class Interpolator {
public:
  Interpolator(){}
  ~Interpolator(){};
  // evaluate the interpolation
  virtual double operator() (double x_target) = 0;

  // check the target value is within the interpolation range
  void check_bounds(double x_target);

  double x_min, x_max;

protected:
  std::vector<double> x_values;
};

class InterpolatorException : public std::exception {
  const char * what () const throw (){
    return "Interpolation error";
  }
};

class InterpolateOutOfRangeException : public InterpolatorException {
  const char * what () const throw() {
    return "Value out of interpolation range";
  }
};

class InterpolateIncompatibleSizes : public InterpolatorException {
  const char * what () const throw() {
    return "Different number of x and y values";
  }
};
#endif // INTERPOLATOR_H_
