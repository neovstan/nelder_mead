#ifndef NELDER_MEAD_H
#define NELDER_MEAD_H

#include <functional>

#include "vector.hpp"

namespace nelder_mead {
class impl {
 public:
  using test_function_t = std::function<double(double, double, double)>;

  struct point {
    point() : vec{}, val{} {
    }

    point(const vector& v, test_function_t fn) : vec{v}, val{fn(v.x, v.y, v.z)} {
    }

    vector vec;
    double val;
  };

 public:
  impl(int dimension = 3, int n = 25, double alpha = 1, double beta = 0.5, double gamma = 2);

  point run(test_function_t fn);

 private:
  const int dimension_;
  const int n_;
  const double alpha_;
  const double beta_;
  const double gamma_;
};
}  // namespace nelder_mead

#endif  // NELDER_MEAD_H
