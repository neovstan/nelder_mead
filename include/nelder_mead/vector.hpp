#ifndef NELDER_MEAD_VECTOR_HPP
#define NELDER_MEAD_VECTOR_HPP

namespace nelder_mead {
struct vector {
  double x;
  double y;
  double z;

  vector& operator+=(const vector& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
  }

  vector& operator-=(const vector& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
  }

  vector& operator*=(const vector& v) {
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
  }

  vector& operator/=(const vector& v) {
    x /= v.x;
    y /= v.y;
    z /= v.z;
    return *this;
  }

  vector& operator+=(double value) {
    x += value;
    y += value;
    z += value;
    return *this;
  }

  vector& operator-=(double value) {
    x -= value;
    y -= value;
    z -= value;
    return *this;
  }

  vector& operator*=(double value) {
    x *= value;
    y *= value;
    z *= value;
    return *this;
  }

  vector& operator/=(double value) {
    x /= value;
    y /= value;
    z /= value;
    return *this;
  }
};

inline vector operator+(const vector& lhs, const vector& rhs) {
  return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
}

inline vector operator-(const vector& lhs, const vector& rhs) {
  return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
}

inline vector operator*(const vector& lhs, const vector& rhs) {
  return {lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z};
}

inline vector operator/(const vector& lhs, const vector& rhs) {
  return {lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z};
}

inline vector operator*(const vector& lhs, double rhs) {
  return {lhs.x * rhs, lhs.y * rhs, lhs.z * rhs};
}

inline vector operator/(const vector& lhs, double rhs) {
  return {lhs.x / rhs, lhs.y / rhs, lhs.z / rhs};
}
}  // namespace nelder_mead

#endif  // NELDER_MEAD_VECTOR_HPP
