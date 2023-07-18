#ifndef NELDER_MEAD_H
#define NELDER_MEAD_H

#include <functional>

class nelder_mead {
 public:
  using test_function_t = std::function<double(double, double)>;

  nelder_mead(double alpha = 1, double beta = 0.5, double gamma = 2, int n = 15);

  double run(test_function_t f);

 private:
  double alpha_;
  double beta_;
  double gamma_;
  int n_;
};

#endif  // NELDER_MEAD_H
