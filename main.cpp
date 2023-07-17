#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>

#include "vector.h"

double f(double x, double y);

double f(const vector& v) {
  return f(v.x, v.y);
}

double nelder_mead(double alpha = 1, double beta = 0.5, double gamma = 2, int n = 10) {
  struct point {
    point(const vector& v) : vec{v}, val{f(vec)} {
    }

    vector vec;
    double val;
  };

  std::array<point, 3> simplex{point{{0, 0}}, {{1, 0}}, {{0, 1}}};
  auto best = simplex.at(0);

  for (auto i = 0; i < n; i++) {
    std::sort(simplex.begin(), simplex.end(),
              [](const point& l, const point& r) { return l.val < r.val; });

    best = simplex.at(0);
    const auto good = simplex.at(1);
    auto worst = simplex.at(2);

    const auto mid = (best.vec + good.vec) / 2;

    // reflection
    const auto xr = point{mid + (mid - worst.vec) * alpha};

    if (xr.val < good.val) {
      worst = xr;
    } else {
      if (xr.val < worst.val) {
        worst = xr;
      }

      const auto xc = point{(worst.vec + mid) / 2};
      if (xc.val < worst.val) {
        worst = xc;
      }
    }

    // expansion
    if (xr.val < best.val) {
      const auto xe = point{mid + (xr.vec - mid) * gamma};
      if (xe.val < xr.val) {
        worst = xe;
      } else {
        worst = xr;
      }
    }

    // contraction
    if (xr.val > good.val) {
      const auto xc = point{mid + (worst.vec - mid) * beta};
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

double f(double x, double y) {
  return std::pow(x, 2) + std::pow(y, 2) + x * y - 4 * x;
}

int main() {
  std::cout << nelder_mead() << std::endl;
}
