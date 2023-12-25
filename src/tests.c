#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

// FABS
START_TEST(fabs_positive) {
  double input = 12.54;
  double result = s21_fabs(input);
  double expected = fabs(input);
  ck_assert_ldouble_eq(result, expected);
}

START_TEST(fabs_negative) {
  double input = -12.54;
  double result = s21_fabs(input);
  double expected = fabs(input);
  ck_assert_ldouble_eq(result, expected);
}

START_TEST(fabs_nan) {
  ck_assert_ldouble_nan(s21_fabs(NaN));
  ck_assert_ldouble_nan(fabs(NaN));
}

START_TEST(fabs_inf_positive) {
  ck_assert_ldouble_infinite(s21_fabs(InFP));
  ck_assert_ldouble_infinite(fabs(InFP));
}

// Не совсем ясно как идет сравнение минус бесконечности
START_TEST(fabs_inf_negative) {
  ck_assert_ldouble_infinite(s21_fabs(InFN));
  ck_assert_ldouble_infinite(fabs(InFN));
}

// CEIL
START_TEST(ceil_edge1) {
  double input = -0.000001;
  double result = s21_ceil(input);
  double expected = ceil(input);
  ck_assert_ldouble_eq(result, expected);
}

START_TEST(ceil_int) {
  double input = 12.0;
  double result = s21_ceil(input);
  double expected = ceil(input);
  ck_assert_ldouble_eq(result, expected);
}

START_TEST(ceil_positive) {
  double input = 12.54;
  double result = s21_ceil(input);
  double expected = ceil(input);
  ck_assert_ldouble_eq(result, expected);
}

START_TEST(ceil_negative) {
  double input = -12.54;
  double result = s21_ceil(input);
  double expected = ceil(input);
  ck_assert_ldouble_eq(result, expected);
}

START_TEST(ceil_nan) {
  ck_assert_ldouble_nan(s21_ceil(NaN));
  ck_assert_ldouble_nan(ceil(NaN));
}

START_TEST(ceil_inf_positive) {
  ck_assert_ldouble_infinite(s21_ceil(InFP));
  ck_assert_ldouble_infinite(ceil(InFP));
}

// Не совсем ясно как идет сравнение минус бесконечности
START_TEST(ceil_inf_negative) {
  ck_assert_ldouble_infinite(s21_ceil(InFN));
  ck_assert_ldouble_infinite(ceil(InFN));
}

// FLOOR
START_TEST(floor_positive_int) {
  double input = 12.0;
  double result = s21_floor(input);
  double expected = floor(input);
  ck_assert_ldouble_eq(result, expected);
}

START_TEST(floor_positive) {
  double input = 12.54;
  double result = s21_floor(input);
  double expected = floor(input);
  ck_assert_ldouble_eq(result, expected);
}

START_TEST(floor_negative) {
  double input = -12.54;
  double result = s21_floor(input);
  double expected = floor(input);
  ck_assert_ldouble_eq(result, expected);
}

START_TEST(floor_nan) {
  ck_assert_ldouble_nan(s21_floor(NaN));
  ck_assert_ldouble_nan(floor(NaN));
}

START_TEST(floor_inf_positive) {
  ck_assert_ldouble_infinite(s21_floor(InFP));
  ck_assert_ldouble_infinite(floor(InFP));
}

// Не совсем ясно как идет сравнение минус бесконечности
START_TEST(floor_inf_negative) {
  ck_assert_ldouble_infinite(s21_floor(InFN));
  ck_assert_ldouble_infinite(floor(InFN));
}

// ABS
START_TEST(abs_positive) {
  int input = 12;
  int result = s21_abs(input);
  int expected = abs(input);
  ck_assert_int_eq(result, expected);
}

START_TEST(abs_negative) {
  int input = -12;
  int result = s21_abs(input);
  int expected = abs(input);
  ck_assert_int_eq(result, expected);
}

START_TEST(abs_nan) {
  int input = NaN;
  int result = s21_abs(input);
  int expected = abs(input);
  ck_assert_int_eq(result, expected);
}

START_TEST(abs_inf_positive) {
  int input = InFP;
  int result = s21_abs(input);
  int expected = abs(input);
  ck_assert_int_eq(result, expected);
}

// Не совсем ясно как идет сравнение минус бесконечности
START_TEST(abs_inf_negative) {
  int input = InFN;
  int result = s21_abs(input);
  int expected = abs(input);
  ck_assert_int_eq(result, expected);
}

// ACOS
START_TEST(acos_nan) {
  double input = NaN;
  double result = s21_acos(input);
  double expected = acos(input);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}

START_TEST(acos_inf_positive) {
  double input = InFP;
  double result = s21_acos(input);
  double expected = acos(input);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}

START_TEST(acos_more_one) {
  double input = 1.000001;
  double result = s21_acos(input);
  double expected = acos(input);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}

START_TEST(acos_one) {
  double input = 1.0;
  double result = s21_acos(input);
  double expected = acos(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}

START_TEST(acos_positive_less_one) {
  double input = 0.000001;
  double result = s21_acos(input);
  double expected = acos(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}

START_TEST(acos_null) {
  double input = 0.0;
  double result = s21_acos(input);
  double expected = acos(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}

START_TEST(acos_negative_more_minus_one) {
  double input = -0.999999;
  double result = s21_acos(input);
  double expected = acos(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}

START_TEST(acos_minus_one) {
  double input = -1.0;
  double result = s21_acos(input);
  double expected = acos(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}

START_TEST(acos_negative_less_minus_one) {
  double input = -9999999999;
  double result = s21_acos(input);
  double expected = acos(input);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}

START_TEST(acos_inf_negative) {
  double input = InFN;
  double result = s21_acos(input);
  double expected = acos(input);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}

// ASIN
START_TEST(asin_nan) {
  double input = NaN;
  double result = s21_asin(input);
  double expected = asin(input);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}

START_TEST(asin_inf_positive) {
  double input = InFP;
  double result = s21_asin(input);
  double expected = asin(input);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}

START_TEST(asin_more_one) {
  double input = 1.000001;
  double result = s21_asin(input);
  double expected = asin(input);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}

START_TEST(asin_one) {
  double input = 1.0;
  double result = s21_asin(input);
  double expected = asin(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}

START_TEST(asin_positive_less_one) {
  double input = 0.000001;
  double result = s21_asin(input);
  double expected = asin(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}

START_TEST(asin_null) {
  double input = 0.0;
  double result = s21_asin(input);
  double expected = asin(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}

START_TEST(asin_negative_more_minus_one) {
  double input = -0.999999;
  double result = s21_asin(input);
  double expected = asin(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}

START_TEST(asin_minus_one) {
  double input = -1.0;
  double result = s21_asin(input);
  double expected = asin(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}

START_TEST(asin_negative_less_minus_one) {
  double input = -9999999999;
  double result = s21_asin(input);
  double expected = asin(input);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}

START_TEST(asin_inf_negative) {
  double input = InFN;
  double result = s21_asin(input);
  double expected = asin(input);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}

// ATAN
START_TEST(atan_nan) {
  double input = NaN;
  double result = s21_atan(input);
  double expected = atan(input);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}

START_TEST(atan_inf_positive) {
  double input = InFP;
  double result = s21_atan(input);
  double expected = atan(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}

START_TEST(atan_positive) {
  double input = 9999999999.0;
  double result = s21_atan(input);
  double expected = atan(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}

START_TEST(atan_null) {
  double input = 0.0;
  double result = s21_atan(input);
  double expected = atan(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}

START_TEST(atan_negative) {
  double input = -0.000001;
  double result = s21_atan(input);
  double expected = atan(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}

START_TEST(atan_max_negative) {
  double input = -2.3;
  double result = s21_atan(input);
  double expected = atan(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}

START_TEST(atan_inf_negative) {
  double input = InFN;
  double result = s21_atan(input);
  double expected = atan(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}

// COS
START_TEST(cos_nan) {
  double input = NaN;
  double result = s21_cos(input);
  double expected = cos(input);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}

START_TEST(cos_inf_positive) {
  double input = InFP;
  double result = s21_cos(input);
  double expected = cos(input);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}

START_TEST(cos_positive_big) {
  double input = 302.8*PI;
  double result = s21_cos(input);
  double expected = cos(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}

START_TEST(cos_positive) {
  double input = 3.0*PI/4.0;
  double result = s21_cos(input);
  double expected = cos(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}

START_TEST(cos_null) {
  double input = 0.0;
  double result = s21_cos(input);
  double expected = cos(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}

START_TEST(cos_negative) {
  double input = -1.5*PI;
  double result = s21_cos(input);
  double expected = cos(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}

START_TEST(cos_negative_big) {
  double input = -30.5*PI;
  double result = s21_cos(input);
  double expected = cos(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}

START_TEST(cos_inf_negative) {
  double input = InFN;
  double result = s21_cos(input);
  double expected = cos(input);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}

// SIN
START_TEST(sin_nan) {
  double input = NaN;
  double result = s21_sin(input);
  double expected = sin(input);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}

START_TEST(sin_inf_positive) {
  double input = InFP;
  double result = s21_sin(input);
  double expected = sin(input);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}

START_TEST(sin_positive_big) {
  double input = 5075.8*PI;
  double result = s21_sin(input);
  double expected = sin(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}

START_TEST(sin_positive) {
  double input = PI/4.0;
  double result = s21_sin(input);
  double expected = sin(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}

START_TEST(sin_null) {
  double input = 0.0;
  double result = s21_sin(input);
  double expected = sin(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}

START_TEST(sin_negative) {
  double input = -PI_2/3.0;
  double result = s21_sin(input);
  double expected = sin(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}

START_TEST(sin_negative_big) {
  double input = -101.5*PI;
  double result = s21_sin(input);
  double expected = sin(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}

START_TEST(sin_inf_negative) {
  double input = InFN;
  double result = s21_sin(input);
  double expected = sin(input);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}

// TAN
START_TEST(tan_nan) {
  double input = NaN;
  double result = s21_tan(input);
  double expected = tan(input);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}

START_TEST(tan_inf_positive) {
  double input = InFP;
  double result = s21_tan(input);
  double expected = tan(input);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}

START_TEST(tan_inf_negative) {
  double input = InFN;
  double result = s21_tan(input);
  double expected = tan(input);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}

// Добавляйте свои тесты как в примере выше

// EXP
START_TEST(exp_inf_negative) {
  double input = InFN;
  double result = s21_exp(input);
  double expected = exp(input);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(exp_negative) {
  double input = -12;
  double result = s21_exp(input);
  double expected = exp(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}
START_TEST(exp_negative_less_one) {
  double input = -0.01;
  double result = s21_exp(input);
  double expected = exp(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}
START_TEST(exp_null) {
  double input = 0.0;
  double result = s21_exp(input);
  double expected = exp(input);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(exp_positive_less_one) {
  double input = 0.01;
  double result = s21_exp(input);
  double expected = exp(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}
START_TEST(exp_positive_one) {
  double input = 1.0;
  double result = s21_exp(input);
  double expected = exp(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}
START_TEST(exp_positive) {
  double input = 12.0;
  double result = s21_exp(input);
  double expected = exp(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}
START_TEST(exp_positive_max) {
  double input = 1000;
  double result = s21_exp(input);
  double expected = exp(input);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(exp_inf_positive) {
  double input = InFP;
  double result = s21_exp(input);
  double expected = exp(input);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(exp_nan) {
  ck_assert_ldouble_nan(s21_exp(NaN));
  ck_assert_ldouble_nan(exp(NaN));
}
// LOG
START_TEST(log_inf_negative) {
  double input = InFN;
  double result = s21_log(input);
  double expected = log(input);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}
START_TEST(log_negative) {
  double input = -12;
  double result = s21_log(input);
  double expected = log(input);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}
START_TEST(log_null) {
  double input = 0.0;
  double result = s21_log(input);
  double expected = log(input);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(log_positive_less_one) {
  double input = 0.01;
  double result = s21_log(input);
  double expected = log(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}
START_TEST(log_positive_one) {
  double input = 1.0;
  double result = s21_log(input);
  double expected = log(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}
START_TEST(log_positive) {
  double input = 12.0;
  double result = s21_log(input);
  double expected = log(input);
  ck_assert_ldouble_eq_tol(result, expected, 1e-6);
}
START_TEST(log_inf_positive) {
  double input = InFP;
  double result = s21_log(input);
  double expected = log(input);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(log_nan) {
  double input = NaN;
  double result = s21_log(input);
  double expected = log(input);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}

// POW
START_TEST(pow_nan_0) {
  double input1 = NaN;
  double input2 = NaN;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}
START_TEST(pow_nan_1) {
  double input1 = 1.0;
  double input2 = NaN;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_nan_2) {
  double input1 = 12;
  double input2 = NaN;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}
START_TEST(pow_nan_3) {
  double input1 = NaN;
  double input2 = 12;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}
START_TEST(pow_inf_1) {
  double input1 = InFN;
  double input2 = InFN;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_2) {
  double input1 = InFP;
  double input2 = InFP;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_3) {
  double input1 = InFN;
  double input2 = InFP;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_4) {
  double input1 = InFP;
  double input2 = InFN;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_negative1_nan) {
  double input1 = InFN;
  double input2 = NaN;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}
START_TEST(pow_inf_negative2_nan) {
  double input1 = NaN;
  double input2 = InFN;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}
START_TEST(pow_inf_positive1_nan) {
  double input1 = InFP;
  double input2 = NaN;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}
START_TEST(pow_inf_positive2_nan) {
  double input1 = NaN;
  double input2 = InFP;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_nan(result);
  ck_assert_ldouble_nan(expected);
}
START_TEST(pow_inf_negative1_1) {
  double input1 = InFN;
  double input2 = 12;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_negative1_2) {
  double input1 = InFN;
  double input2 = -12;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_negative1_3) {
  double input1 = InFN;
  double input2 = -1;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_negative1_4) {
  double input1 = InFN;
  double input2 = 0;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_negative1_5) {
  double input1 = InFN;
  double input2 = 1.5;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_negative2_1) {
  double input1 = -12;
  double input2 = InFN;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_negative2_2) {
  double input1 = -1;
  double input2 = InFN;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_negative2_3) {
  double input1 = -0.5;
  double input2 = InFN;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_negative2_4) {
  double input1 = -0;
  double input2 = InFN;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_negative2_5) {
  double input1 = 0.5;
  double input2 = InFN;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_negative2_6) {
  double input1 = 1;
  double input2 = InFN;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_negative2_7) {
  double input1 = 12;
  double input2 = InFN;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_positive1_1) {
  double input1 = InFP;
  double input2 = 12;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_positive1_2) {
  double input1 = InFP;
  double input2 = -12;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_positive1_3) {
  double input1 = InFP;
  double input2 = -1;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_positive1_4) {
  double input1 = InFP;
  double input2 = 0;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_positive1_5) {
  double input1 = InFP;
  double input2 = 1.5;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_positive2_1) {
  double input1 = -12;
  double input2 = InFP;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_positive2_2) {
  double input1 = -1;
  double input2 = InFP;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_positive2_3) {
  double input1 = -0.5;
  double input2 = InFP;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_positive2_4) {
  double input1 = -0;
  double input2 = InFP;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_positive2_5) {
  double input1 = 0.5;
  double input2 = InFP;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_positive2_6) {
  double input1 = 1;
  double input2 = InFP;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
START_TEST(pow_inf_positive2_7) {
  double input1 = 12;
  double input2 = InFP;
  double result = s21_pow(input1, input2);
  double expected = pow(input1, input2);
  ck_assert_ldouble_eq(result, expected);
}
// START_TEST(log_null) {
//   double input = 0.0;
//   double result = s21_log(input);
//   double expected = log(input);
//   ck_assert_ldouble_eq(result, expected);
// }
// START_TEST(log_positive) {
//   double input = 12.0;
//   double result = s21_log(input);
//   double expected = log(input);
//   ck_assert_ldouble_eq_tol(result, expected, 1e-6);
// }

Suite *my_math_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("MyMath");

  tc_core = tcase_create("Core");

  // tcase_add_test(tc_core, name of test);  // add test case in suite

  // FABS
  tcase_add_test(tc_core, fabs_positive);
  tcase_add_test(tc_core, fabs_negative);
  tcase_add_test(tc_core, fabs_nan);
  tcase_add_test(tc_core, fabs_inf_positive);
  tcase_add_test(tc_core, fabs_inf_negative);

  // CEIL
  tcase_add_test(tc_core, ceil_edge1);
  tcase_add_test(tc_core, ceil_int);
  tcase_add_test(tc_core, ceil_positive);
  tcase_add_test(tc_core, ceil_negative);
  tcase_add_test(tc_core, ceil_nan);
  tcase_add_test(tc_core, ceil_inf_positive);
  tcase_add_test(tc_core, ceil_inf_negative);

  // FLOOR
  tcase_add_test(tc_core, floor_positive_int);
  tcase_add_test(tc_core, floor_positive);
  tcase_add_test(tc_core, floor_negative);
  tcase_add_test(tc_core, floor_nan);
  tcase_add_test(tc_core, floor_inf_positive);
  tcase_add_test(tc_core, floor_inf_negative);

  // ABS
  tcase_add_test(tc_core, abs_positive);
  tcase_add_test(tc_core, abs_negative);
  tcase_add_test(tc_core, abs_nan);
  tcase_add_test(tc_core, abs_inf_positive);
  tcase_add_test(tc_core, abs_inf_negative);

  // ACOS
  tcase_add_test(tc_core, acos_nan);
  tcase_add_test(tc_core, acos_inf_positive);
  tcase_add_test(tc_core, acos_more_one);
  tcase_add_test(tc_core, acos_one);
  tcase_add_test(tc_core, acos_positive_less_one);
  tcase_add_test(tc_core, acos_null);
  tcase_add_test(tc_core, acos_negative_more_minus_one);
  tcase_add_test(tc_core, acos_minus_one);
  tcase_add_test(tc_core, acos_negative_less_minus_one);
  tcase_add_test(tc_core, acos_inf_negative);

  // ASIN
  tcase_add_test(tc_core, asin_nan);
  tcase_add_test(tc_core, asin_inf_positive);
  tcase_add_test(tc_core, asin_more_one);
  tcase_add_test(tc_core, asin_one);
  tcase_add_test(tc_core, asin_positive_less_one);
  tcase_add_test(tc_core, asin_null);
  tcase_add_test(tc_core, asin_negative_more_minus_one);
  tcase_add_test(tc_core, asin_minus_one);
  tcase_add_test(tc_core, asin_negative_less_minus_one);
  tcase_add_test(tc_core, asin_inf_negative);

  // ATAN
  tcase_add_test(tc_core, atan_nan);
  tcase_add_test(tc_core, atan_inf_positive);
  tcase_add_test(tc_core, atan_positive);
  tcase_add_test(tc_core, atan_null);
  tcase_add_test(tc_core, atan_negative);
  tcase_add_test(tc_core, atan_max_negative);
  tcase_add_test(tc_core, atan_inf_negative);


  // COS
  tcase_add_test(tc_core, cos_nan);
  tcase_add_test(tc_core, cos_inf_positive);
  tcase_add_test(tc_core, cos_positive_big);
  tcase_add_test(tc_core, cos_positive);
  tcase_add_test(tc_core, cos_null);
  tcase_add_test(tc_core, cos_negative);
  tcase_add_test(tc_core, cos_negative_big);
  tcase_add_test(tc_core, cos_inf_negative);

  // SIN
  tcase_add_test(tc_core, sin_nan);
  tcase_add_test(tc_core, sin_inf_positive);
  tcase_add_test(tc_core, sin_positive_big);
  tcase_add_test(tc_core, sin_positive);
  tcase_add_test(tc_core, sin_null);
  tcase_add_test(tc_core, sin_negative);
  tcase_add_test(tc_core, sin_negative_big);
  tcase_add_test(tc_core, sin_inf_negative);

  // TAN
  tcase_add_test(tc_core, tan_nan);
  tcase_add_test(tc_core, tan_inf_positive);
  tcase_add_test(tc_core, tan_inf_negative);

  // EXP
  tcase_add_test(tc_core, exp_inf_negative);
  tcase_add_test(tc_core, exp_negative);
  tcase_add_test(tc_core, exp_negative_less_one);
  tcase_add_test(tc_core, exp_null);
  tcase_add_test(tc_core, exp_positive_less_one);
  tcase_add_test(tc_core, exp_positive_one);
  tcase_add_test(tc_core, exp_positive);
  tcase_add_test(tc_core, exp_positive_max);
  tcase_add_test(tc_core, exp_inf_positive);
  tcase_add_test(tc_core, exp_nan);

  // LOG
  tcase_add_test(tc_core, log_inf_negative);
  tcase_add_test(tc_core, log_negative);
  tcase_add_test(tc_core, log_null);
  tcase_add_test(tc_core, log_positive_less_one);
  tcase_add_test(tc_core, log_positive_one);
  tcase_add_test(tc_core, log_positive);
  tcase_add_test(tc_core, log_inf_positive);
  tcase_add_test(tc_core, log_nan);

  // POW
  tcase_add_test(tc_core, pow_nan_0);
  tcase_add_test(tc_core, pow_nan_1);
  tcase_add_test(tc_core, pow_nan_2);
  tcase_add_test(tc_core, pow_nan_3);
  tcase_add_test(tc_core, pow_inf_1);
  tcase_add_test(tc_core, pow_inf_2);
  tcase_add_test(tc_core, pow_inf_3);
  tcase_add_test(tc_core, pow_inf_4);
  tcase_add_test(tc_core, pow_inf_negative1_nan);
  tcase_add_test(tc_core, pow_inf_negative2_nan);
  tcase_add_test(tc_core, pow_inf_positive1_nan);
  tcase_add_test(tc_core, pow_inf_positive2_nan);
  tcase_add_test(tc_core, pow_inf_negative1_1);
  tcase_add_test(tc_core, pow_inf_negative1_2);
  tcase_add_test(tc_core, pow_inf_negative1_3);
  tcase_add_test(tc_core, pow_inf_negative1_4);
  tcase_add_test(tc_core, pow_inf_negative1_5);
  tcase_add_test(tc_core, pow_inf_negative2_1);
  tcase_add_test(tc_core, pow_inf_negative2_2);
  tcase_add_test(tc_core, pow_inf_negative2_3);
  tcase_add_test(tc_core, pow_inf_negative2_4);
  tcase_add_test(tc_core, pow_inf_negative2_5);
  tcase_add_test(tc_core, pow_inf_negative2_6);
  tcase_add_test(tc_core, pow_inf_negative2_7);
  tcase_add_test(tc_core, pow_inf_positive1_1);
  tcase_add_test(tc_core, pow_inf_positive1_2);
  tcase_add_test(tc_core, pow_inf_positive1_3);
  tcase_add_test(tc_core, pow_inf_positive1_4);
  tcase_add_test(tc_core, pow_inf_positive1_5);
  tcase_add_test(tc_core, pow_inf_positive2_1);
  tcase_add_test(tc_core, pow_inf_positive2_2);
  tcase_add_test(tc_core, pow_inf_positive2_3);
  tcase_add_test(tc_core, pow_inf_positive2_4);
  tcase_add_test(tc_core, pow_inf_positive2_5);
  tcase_add_test(tc_core, pow_inf_positive2_6);
  tcase_add_test(tc_core, pow_inf_positive2_7);

  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = my_math_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? SUCCESS : ERROR;
}
