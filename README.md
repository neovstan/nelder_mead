# nelder_mead

### Implementation of the simplest and at the same time effective optimization method — [the Nelder—Mead method](https://en.wikipedia.org/wiki/Nelder%E2%80%93Mead_method)
##
![!](https://upload.wikimedia.org/wikipedia/commons/7/72/An-iteration-of-the-Nelder-Mead-method-over-two-dimensional-space-showing-point-p-min.png "An iteration of the Nelder-Mead method over two-dimensional space.")
##
###
```cpp
#include <cmath>
#include <iostream>
#include <nelder_mead/impl.h>

double himmelblau(double x, double y, double z) {
  return std::pow(std::pow(x, 2) + y - 11, 2) + std::pow(x + std::pow(y, 2) - 7, 2);
}

int main() {
  nelder_mead::impl optimizer;
  const auto min_point = optimizer.run(himmelblau);
  std::cout << min_point.value << std::endl;
  std::cout << min_point.vec.x << " " << min_point.vec.y << " " << min_point.vec.z;
}
```
