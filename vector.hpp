#ifndef VECTOR_H
#define VECTOR_H

struct vector {
  double x;
  double y;
};

inline vector operator+(const vector& lhs, const vector& rhs) {
  return {lhs.x + rhs.x, lhs.y + rhs.y};
}

inline vector operator-(const vector& lhs, const vector& rhs) {
  return {lhs.x - rhs.x, lhs.y - rhs.y};
}

inline vector operator*(const vector& lhs, const vector& rhs) {
  return {lhs.x * rhs.x, lhs.y * rhs.y};
}

inline vector operator/(const vector& lhs, const vector& rhs) {
  return {lhs.x / rhs.x, lhs.y / rhs.y};
}

inline vector operator*(const vector& lhs, double rhs) {
  return {lhs.x * rhs, lhs.y * rhs};
}

inline vector operator/(const vector& lhs, double rhs) {
  return {lhs.x / rhs, lhs.y / rhs};
}

#endif  // VECTOR_H
