#include "s21_math.h"

long double s21_pow(double base, double p) {
  if (p == (long int)p)
    return s21_pow_int(base, p);
  else
    return s21_pow_double(base, p);
}

long double s21_pow_int(long double base,
                        long double p) {  // try 1.000001  - bag here
  // printf("%Lf\n", p);
  // if (p == 0) {
  //   return ONE;  // Выход из рекурсии.
  // }
  // if (p > 0) {
  //   if ((long long)p % 2 == 0) {
  //     long double t = s21_pow_int(base, p / 2.0);
  //     return t * t;
  //   } else {
  //     return s21_pow_int(base, p - ONE) * base;
  //   }
  // } else {
  //   return s21_pow_int(base, p + ONE) / base;
  // }

  /*
    long double result = ONE;
    int flag_even = 0;
    if ((long long)p % 2 == 0) flag_even = 1;
    if (base == 0 && p != 0) {
      if (p > 0)
        result = ZERO;
      else
        result = InFP;
    } else if (base != ONE) {
      if (base == MINUS) {
        if (!flag_even) result = MINUS;
      } else {
        for (; p != 0;) {
          if (p > 0) {
            result *= base;
            p--;
          } else {
            result /= base;
            p++;
          }
          // printf("%Lf->%Lf->->%Lf\n", base, p, result);

          if (result > __DBL_MAX__) {
            if (base < 0 && !flag_even)
              result = InFN;
            else
              result = InFP;
            p = 0;
          } else if (result < __DBL_MAX__ * MINUS) {
            if (flag_even)
              result = InFP;
            else
              result = InFN;
            p = 0;
          } else if (result < __DBL_DENORM_MIN__ && result > 0) {
            if (base < 0 && !flag_even)
              result = ZERON;
            else
              result = ZERO;
            p = 0;
          } else if (result > __DBL_DENORM_MIN__ * MINUS && result < 0) {
            if (flag_even)
              result = ZERO;
            else
              result = ZERON;
            p = 0;
          }
        }
      }
    }
  */

  long double result = ONE;
  int flag_even = 0;
  if ((long long)p % 2 == 0) flag_even = 1;
  if (base == 0 && p != 0) {
    if (p > 0)
      result = ZERO;
    else
      result = InFP;
  } else if (base != ONE) {
    if (base == MINUS) {
      if (!flag_even) result = MINUS;
    } else {
      for (; p != 0;) {
        if (p > 0) {
          result *= base;
          p--;
        } else {
          result /= base;
          p++;
        }
        // printf("%Lf->%Lf->->%Lf\n", base, p, result);

        if (result > __DBL_MAX__) {
          if (base < 0 && !flag_even)
            result = InFN;
          else
            result = InFP;
          p = 0;
        } else if (result < __DBL_MAX__ * MINUS) {
          if (flag_even)
            result = InFP;
          else
            result = InFN;
          p = 0;
        } else if (result < __DBL_DENORM_MIN__ && result > 0) {
          if (base < 0 && !flag_even)
            result = ZERON;
          else
            result = ZERO;
          p = 0;
        } else if (result > __DBL_DENORM_MIN__ * MINUS && result < 0) {
          if (flag_even)
            result = ZERO;
          else
            result = ZERON;
          p = 0;
        }
      }
    }
  }

  return result;
}

long double s21_pow_double(
    double base, double p) {  // we need to either change LN either pow
  long double result;
  if (base > 0)
    result = s21_pow_calculation(base, p);
  else if (base < 0) {
    if (p == 0)
      result = ONE;
    else {
      if (p == (long int)p)
        result = s21_pow_calculation(base, p);
      else
        result = NaN;  /// bag here?
    }
  } else {
    if (p > 0)
      result = ZERO;
    else if (p == 0)
      result = ONE;
    else
      result = InFP;  // error with INF??
  }
  return result;
}

long double s21_pow_calculation(double base, long double p) {
  long double res;
  // printf("%lf->%Lf", base, p);
  res = s21_exp(p * s21_log(base));
  // printf("->->%Lf\t", res);
  return res;

  // long double i = 0;
  // for (; i <= p; i++)
  //   ;
  // long double res = s21_pow_int(base, i);
  // if (res != InFN && res != InFP)
  //   res = res * s21_exp((long double)(p - i) * s21_log(base));
  // return res;

  //  return s21_exp(p * s21_log(base));
}

long double s21_sqrt(double base) { return s21_pow_double(base, SQRT); }

// long double not_a_crutch(long double x) {
//   long int temp;
//   temp = x * 1000000000;

//   if ((x - (double)temp) * 10 >= 5)
//     return x + 0.000000001;
//   else
//     return x;
// }