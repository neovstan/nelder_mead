#include "nelder_mead.h"

#include <algorithm>
#include <stdexcept>
#include <vector>

nelder_mead::nelder_mead(int dimension, int n, double alpha, double beta, double gamma)
    : dimension_{dimension}, n_{n}, alpha_{alpha}, beta_{beta}, gamma_{gamma} {
  if (dimension_ != 2 && dimension_ != 3) {
    throw std::runtime_error{"Dimension must be 2 or 3"};
  }
}

nelder_mead::point nelder_mead::run(test_function_t fn) {
  // 1. Preparing
  std::vector<point> simplex;
  simplex.push_back(point{{0, 0, 0}, fn});
  simplex.push_back(point{{0, 1, 0}, fn});
  simplex.push_back(point{{0, 0, 2}, fn});
  simplex.push_back(point{{1, 0, 1}, fn});

  point best_point;

  for (auto i = 0; i < n_; i++) {
    // 2. Order
    std::sort(simplex.begin(), simplex.end(),
              [](const point& l, const point& r) { return l.val < r.val; });

    auto worst_point = simplex.at(dimension_);
    const auto good_point = simplex.at(dimension_ - 1);
    best_point = simplex.at(0);

    // 3. Calculation of the simplex centroid
    vector centroid{};
    for (auto i = 0; i < dimension_; i++) {
      centroid += simplex.at(i).vec;
    }
    centroid /= dimension_;

    // 4. Reflection
    auto reflected_point = point{centroid * (1 + alpha_) - worst_point.vec * alpha_, fn};

    // 5. Expansion
    if (reflected_point.val < best_point.val) {
      const auto expanded_point = point(centroid * (1 - gamma_) + reflected_point.vec * gamma_, fn);
      simplex.at(dimension_) =
          expanded_point.val < reflected_point.val ? expanded_point : reflected_point;
      continue;
    }

    if ((best_point.val < reflected_point.val) && (reflected_point.val < good_point.val)) {
      simplex.at(dimension_) = reflected_point;
      continue;
    }

    bool allow_shrinkage{};

    // 6. Contraction
    if ((good_point.val < reflected_point.val) && (reflected_point.val < worst_point.val)) {
      simplex.at(dimension_) = reflected_point;
      std::swap(reflected_point, worst_point);
      allow_shrinkage = true;
    }

    if (!allow_shrinkage && worst_point.val < reflected_point.val) {
      allow_shrinkage = true;
    }

    // 7. Shrinkage
    if (allow_shrinkage) {
      const auto shrinked_point = point{worst_point.vec * beta_ + centroid * (1 - beta_), fn};
      if (shrinked_point.val < worst_point.val) {
        simplex.at(dimension_) = shrinked_point;
        worst_point = shrinked_point;
      } else {
        for (auto i = 0; i <= dimension_; i++) {
          simplex.at(i) = point{best_point.vec + (simplex.at(i).vec - best_point.vec) / 2, fn};
        }
      }
    }
  }

  return best_point;
}
