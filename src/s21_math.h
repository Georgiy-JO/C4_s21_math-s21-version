#ifndef S21_MATH_H
#define S21_MATH_H

#define SUCCESS 0
#define ERROR 1

#define EPSilon 1E-18
#define EPSilon2 1E-9

#define ONE 1.0
#define ZERO 0.0
#define ZERON -0.0
#define TWO 2.0
#define MINUS (-1.0)
#define SQRT 0.5

#define NaN 0.0 / 0.0
#define NaNP -0.0 / 0.0
#define InFN -1.0 / 0.0
#define InFP 1.0 / 0.0

// #define __DBL_MAX__ 1.79769313486231570814527423731704357e+308L
// #define __DBL_DENORM_MIN__ 4.94065645841246544176568792868221372e-324L

#define PI 3.14159265358979323846
#define PI_2 2.0 * PI
#define Emathh 2.7182818284590450907955982984276488423347473144531250

int s21_abs(int x);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_fabs(double x);

long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);

long double s21_exp(double x);
long double s21_exp_double(double x);
long double s21_exp_int_neg(long double p);

long double s21_fmod(double x, double y);
long double s21_truncate(double x);

long double s21_log(double x);

long double s21_pow(double base, double p);
long double s21_pow_calculation(double base, long double p);
long double s21_pow_double(double base, double p);
long double s21_sqrt(double base);

long double s21_cos(double x);
long double s21_sin(double x);
long double s21_tan(double x);
double s21_extra_pi_romoval(double* x);
long double s21_nans_infs(double x);

#endif
