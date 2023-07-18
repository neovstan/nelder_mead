#include "nelder_mead.h"

#include <algorithm>

#include "vector.hpp"

nelder_mead::nelder_mead(double alpha, double beta, double gamma, int n)
    : alpha_{alpha}, beta_{beta}, gamma_{gamma}, n_{n} {
}

double nelder_mead::run(test_function_t f) {
  struct point {
    point(const vector& v, test_function_t f) : vec{v}, val{f(v.x, v.y)} {
    }

    vector vec;
    double val;
  };

  std::array<point, 3> simplex{point{{0, 0}, f}, {{1, 0}, f}, {{0, 1}, f}};
  auto best = simplex.at(0);

  for (auto i = 0; i < n_; i++) {
    std::sort(simplex.begin(), simplex.end(),
              [](const point& l, const point& r) { return l.val < r.val; });

    best = simplex.at(0);
    const auto good = simplex.at(1);
    auto worst = simplex.at(2);

    const auto mid = (best.vec + good.vec) / 2;

    // reflection
    const auto xr = point{mid + (mid - worst.vec) * alpha_, f};

    if (xr.val < good.val) {
      worst = xr;
    } else {
      if (xr.val < worst.val) {
        worst = xr;
      }

      const auto xc = point{(worst.vec + mid) / 2, f};
      if (xc.val < worst.val) {
        worst = xc;
      }
    }

    // expansion
    if (xr.val < best.val) {
      const auto xe = point{mid + (xr.vec - mid) * gamma_, f};
      if (xe.val < xr.val) {
        worst = xe;
      } else {
        worst = xr;
      }
    }

    // contraction
    if (xr.val > good.val) {
      const auto xc = point{mid + (worst.vec - mid) * beta_, f};
      if (xc.val < worst.val) {
        worst = xc;
      }
    }

    simplex.at(0) = worst;
    simplex.at(1) = good;
    simplex.at(2) = best;
  }

  return best.val;
}
