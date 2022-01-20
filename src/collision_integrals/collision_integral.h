
#ifndef COLLISION_INTEGRAL_H_
#define COLLISION_INTEGRAL_H_

#include <tuple>
#include <string>

using col_int_order = std::tuple<int, int>;
using col_int_species = std::tuple<std::string, std::string>;

enum ColIntType {
  table,
};

class CollisionIntegral {
public:
  CollisionIntegral(){}
  CollisionIntegral(col_int_species species, col_int_order order);
  ~CollisionIntegral(){}

  // The species present in the collision
  col_int_species species;

  // The order of the collision integral
  col_int_order order;

  // evaluate the collision integral
  virtual double eval(double temp) = 0;

};


#endif // COLLISION_INTEGRAL_H_
