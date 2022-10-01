#include "rational_numbers.h"
#include <stdint.h>
#include <math.h>

int16_t int_pow(int16_t base, int16_t pow) {
  int16_t out = base;
  for (int i = 1; i < pow; i++) {
    out *= base;
  }
  return out;
}

int16_t gcd(int Num1, int Num2) {
  int16_t Temp, GCD;

  while (Num2 != 0) {
    Temp = Num2;
    Num2 = Num1 % Num2;
    Num1 = Temp;
  }
  GCD = Num1;
  return GCD;
}

rational_t reduce(rational_t r) {
  int16_t num = r.numerator;
  int16_t den = r.denominator;
  int16_t com = gcd(num, den);
  num = num / com;
  den = den / com;
  if (den < 0) {
    num = -num;
    den = -den;
  } 
  rational_t out = { num, den };
  return out;
}



rational_t absolute(rational_t r1) {
  // The absolute value `|r|` of the rational number `r = a/b` is equal to `|a|/|b|`.
  rational_t out = { r1.numerator, r1.denominator };
  if (out.numerator < 0) {
    out.numerator = -out.numerator; 
  }  
  if (out.denominator< 0) {
    out.denominator= -out.denominator; 
  }  
  return reduce(out);
}

rational_t add(rational_t r1, rational_t r2) {
  // The sum of two rational numbers `r₁ = a₁/b₁` and `r₂ = a₂/b₂` is `r₁ + r₂ = a₁/b₁ + a₂/b₂ = (a₁ * b₂ + a₂ * b₁) / (b₁ * b₂)`.
  int16_t a1 = r1.numerator;
  int16_t a2 = r2.numerator;
  int16_t b1 = r1.denominator;
  int16_t b2 = r2.denominator;
  int16_t num = a2 * b1 + a1 * b2;
  int16_t den = b1 * b2; 
  rational_t out = { num, den };
  return reduce(out);
}

rational_t subtract(rational_t r1, rational_t r2) {
  // The difference of two rational numbers `r₁ = a₁/b₁` and `r₂ = a₂/b₂` is `r₁ - r₂ = a₁/b₁ - a₂/b₂ = (a₁ * b₂ - a₂ * b₁) / (b₁ * b₂)`.
  int16_t a1 = r1.numerator;
  int16_t a2 = r2.numerator;
  int16_t b1 = r1.denominator;
  int16_t b2 = r2.denominator;
  int16_t num = a1 * b2 - a2 * b1;
  int16_t den = b1 * b2;
  rational_t out = { num, den };
  return reduce(out);
}

rational_t multiply(rational_t r1, rational_t r2) {
  // The product (multiplication) of two rational numbers `r₁ = a₁/b₁` and `r₂ = a₂/b₂` is `r₁ * r₂ = (a₁ * a₂) / (b₁ * b₂)`.
  int16_t a1 = r1.numerator;
  int16_t a2 = r2.numerator;
  int16_t b1 = r1.denominator;
  int16_t b2 = r2.denominator;
  int16_t num = a1 * a2;
  int16_t den = b1 * b2;
  rational_t out = { num, den };
  return reduce(out);
}

rational_t divide(rational_t r1, rational_t r2) {
  // Dividing a rational number `r₁ = a₁/b₁` by another `r₂ = a₂/b₂` is `r₁ / r₂ = (a₁ * b₂) / (a₂ * b₁)` if `a₂` is not zero.
  int16_t a1 = r1.numerator;
  int16_t a2 = r2.numerator;
  int16_t b1 = r1.denominator;
  int16_t b2 = r2.denominator;
  int16_t num = a1 * b2;
  int16_t den = a2 * b1;;
  rational_t out = { num, den };
  return reduce(out);
}

rational_t exp_rational(rational_t r, int16_t n) {
  // Exponentiation of a rational number `r = a/b` to a non-negative int16_teger power `n` is `r^n = (a^n)/(b^n)`.
  //
  // Exponentiation of a rational number `r = a/b` to a negative int16_teger power `n` is `r^n = (b^m)/(a^m)`, where `m = |n|`.
  //
  // Exponentiation of a rational number `r = a/b` to a real (floating-point16_t) number `x` is the quotient `(a^x)/(b^x)`, which is a real number.
  int num = r.numerator;
  int den = r.denominator;
  if (n == 0) {
    num = 1;
    den = 1;
  }

  if (n < 0) {
    n = -n;
    int tmp = num;
    num = den;
    den = tmp;
  }
  num = int_pow(num, n);
  den = int_pow(den, n);
  rational_t out = { num, den };
  return reduce(out);
}

float exp_real(uint16_t x, rational_t r) {
  // Exponentiation of a real number `x` to a rational number `r = a/b` is `x^(a/b) = root(x^a, b)`, where `root(p, q)` is the `q`th root of `p`.
  float rp = (float)(r.numerator) / (float)(r.denominator);
  return powf((float)(x),rp);
}

