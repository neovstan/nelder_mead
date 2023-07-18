#include <cmath>
#include <iostream>

#include "nelder_mead.h"

double himmelblau(double x, double y, double z) {
  return std::pow(std::pow(x, 2) + y - 11, 2) + std::pow(x + std::pow(y, 2) - 7, 2);
}

double mccormick(double x, double y, double z) {
  return std::sin(x + y) + std::pow(x - y, 2) - 1.5 * x + 2.5 * y + 1;
}

double matyas(double x, double y, double z) {
  return 0.26 * (std::pow(x, 2) + std::pow(y, 2)) - 0.48 * x * y;
}

double beale(double x, double y, double z) {
  return std::pow(1.5 - x + x * y, 2) + std::pow(2.25 - x + x * std::pow(y, 2), 2) +
         std::pow(2.625 - x + x * std::pow(y, 3), 2);
}

int main() {
  nelder_mead optimizer;
  std::cout << optimizer.run(himmelblau).val << std::endl;
  std::cout << optimizer.run(mccormick).val << std::endl;
  std::cout << optimizer.run(matyas).val << std::endl;
  std::cout << optimizer.run(beale).val << std::endl;
}
