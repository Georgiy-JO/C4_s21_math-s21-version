#include "s21_math.h"

long double s21_acos(double x) {
  if (s21_fabs(x) > 1) return NaN;
  if (x != x) return NaN;
  return (double)(PI / 2.0 - s21_asin(x));
}

long double s21_asin(double x) {
  if (s21_fabs(x) > 1) return NaN;
  if (x != x) return NaN;

  long double res = 0;
  long double flag = 0;
  if (x > 0)
    flag = ONE;
  else
    flag = MINUS;

  if (s21_fabs(x) < 0.9) {
    long double step = x;
    res += step;
    for (long double i = 1; s21_fabs((double)step) >= EPSilon2; i += 2) {
      step = step * x * x * i * i / ((i + 1.0) * (i + 2.0));
      res += step;
    }
  } else {  /// |x| >= 0.9
    res = flag * s21_acos(s21_sqrt(1 - x * x));
  }

  return res;
}

long double s21_atan(double x) {
  if (x * x > __DBL_MAX__) {
    if (x > 0)
      return PI / 2.0;
    else
      return -PI / 2.0;
  }
  if (x != x) return NaN;
  long double res = 0;
  res = 1.0 / s21_sqrt(1.0 + x * x);
  if (s21_fabs(x) >= 1) {
    res = s21_acos((double)(res));
    if (x < 0) res *= -1.0;
  } else
    res = s21_asin((double)(x * res));
  return res;
}