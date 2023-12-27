#include "s21_math.h"

long double s21_fmod(double x, double y) {
  if (x != x || y != y) return NaN;
  if (y == 0 || s21_fabs(x) == InFP) return NaN;
  long double res = 0;
  if (s21_fabs(y) == InFP) {
    res = x;
  } else {
    long double temp = s21_truncate(x / y);
    res = (long double)x - temp * (long double)y;
  }
  return res;
}
long double s21_truncate(double x) {
  return x < 0 ? -s21_floor(-x) : s21_floor(x);
}
