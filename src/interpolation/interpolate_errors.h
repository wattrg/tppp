#ifndef INTERPOLATE_ERRORS_H_
#define INTERPOLATE_ERRORS_H_

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

class InterpolateInsufficientPoints : public InterpolatorException {
  const char * what () const throw() {
    return "Insufficient points to interpolate";
  }
};


#endif // INTERPOLATE_ERRORS_H_
