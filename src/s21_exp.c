#include "s21_math.h"

long double s21_exp(double x) {
  long double res = ONE;
  if (x == InFN)
    res = ZERO;
  else {
    if (x > ZERO) {
      res = s21_exp_double(x);
    } else {
      res = s21_exp_int_neg((long long)x);
      res *= s21_exp_double(x - (long long)x);
    }
    if (res > __DBL_MAX__) res = InFP;
  }
  return res;
}
long double s21_exp_double(double x) {
  long double cur = ONE;
  long double add = ONE;
  double i = ONE;
  while (s21_fabs(add) > EPSilon) {
    add = add * x / i;
    cur = cur + add;
    i++;
    if (cur > __DBL_MAX__) break;
  }
  return cur;
}

long double s21_exp_int_neg(long double p) {
  long double base = Emathh;  //~2.7182818
  long double result = ONE;
  for (; p != 0;) {
    result /= base;
    p++;
    if (result < __DBL_DENORM_MIN__) {
      result = ZERO;
      p = 0;
    }
  }
  return result;
}
