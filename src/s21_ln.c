#include "s21_math.h"

long double s21_log(double x) {
  long double cur = ZERO;
  if (x < ZERO) cur = NaN;
  if (x == ZERO) cur = InFN;
  if (x == InFP) cur = x;
  if (cur == ZERO) {
    long double power = ZERO;
    for (; x > ONE; power++) {
      x = x / s21_exp(ONE);
    }
    cur = x - ONE;
    long double prev = ZERO;
    while (s21_fabs(cur - prev) > EPSilon2) {
      prev = cur;
      cur = cur + TWO * (x - s21_exp(cur)) / (x + s21_exp(cur));
    }
    cur = cur + power;
  }
  return cur;
}