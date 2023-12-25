#include "s21_math.h"

long double s21_cos(double x) {
  long double res = 0.0, step = 1.0;
  double flag = 0.0;
  res = nans_infs(x);
  if (!res) {
    flag = extra_pi_romoval(&x);
    for (long double i = 2;
         (step >= EPSilon2 && step > 0) || (step <= EPSilon2 && step < 0);
         i += 2) {
      res += step;
      step = MINUS * step * x * x / (i * (i - ONE));
    }
  }
  return flag * res;
}

long double s21_sin(double x) {
  long double res = 0.0;
  res = nans_infs(x);
  if (!res) {
    res = s21_cos(x - PI/2.0); // sinx = cos(x - PI/2)
  }
  return res;
}

long double s21_tan(double x) {
  if (s21_fabs(s21_cos(x)) <= EPSilon) {
    if ((s21_cos(x) <= 0 && s21_sin(x) < 0) ||
        (s21_cos(x) >= 0 && s21_sin(x) > 0))
      return InFP;
    else
      return InFN;
  }
  return s21_sin(x) / s21_cos(x);
}

double extra_pi_romoval(double* x) {
  double tmp = 0.0, flag = 1.0;
  tmp = s21_fmod((*x), PI_2);  // +- 2pi -> x in (-2pi, 2pi)
  if (tmp < 0) tmp = -tmp;  // cos(-x) = cosx -> x in [0, 2pi)
  if (tmp >= PI) {          // x in [0, pi)
    *x = tmp - PI;          // cos(x - PI) = -cosx
    flag = -1.0;
  } else {
    *x = tmp;
  }
  return flag;
}

long double nans_infs(double x) {
  long double flag;
  if (x > InFN && x < InFP && x == x)
    flag = 0;
  else if (x == InFN || x == InFP)
    flag = NaN;
  else  // x!=x
    flag = x;
  return flag;
}