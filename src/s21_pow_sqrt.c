#include "s21_math.h"

long double s21_pow(double base, double p) {
  long double result = TWO;
  if (p == InFN || p == InFP) {
    if (base < MINUS || base > ONE)
      result = (p == InFN ? ZERO : InFP);
    else if (base > MINUS && base < ONE)
      result = (p == InFN ? InFP : ZERO);
    else if (base == MINUS || base == ONE)
      result = ONE;
  }
  if (result == TWO && (base == InFP || base == InFN)) {
    if (p > ZERO)
      result = InFP;
    else if (p < ZERO && p != MINUS)
      result = ZERO;
    else if (p == MINUS)
      result = (base == InFP ? ZERO : ZERON);
    else
      result = ONE;
  }
  if (result == TWO) {
    result = s21_pow_double(base, p);
    if (result > __DBL_MAX__) result = InFP;
    if (result < MINUS * __DBL_MAX__) result = InFN;
  }
  if (p != p) {
    result = (base == ONE ? base : p);
  }
  if (base != base) result = base;
  return result;
}

long double s21_pow_double(double base, double p) {
  long double result;
  if (base > 0)
    result = s21_pow_calculation(base, p);
  else if (base < 0) {
    if (p == 0)
      result = ONE;
    else {
      if (p == (long int)p) {
        result = s21_pow_calculation(base * MINUS, p);
        if ((long int)p % 2 != 0) result *= MINUS;
      } else
        result = NaN;
    }
  } else {
    if (p > 0)
      result = ZERO;
    else if (p == 0)
      result = ONE;
    else
      result = InFP;
  }
  return result;
}

long double s21_pow_calculation(double base, long double p) {
  long double res;
  res = s21_exp(p * s21_log(base));
  return res;
}

long double s21_sqrt(double base) { return s21_pow(base, SQRT); }