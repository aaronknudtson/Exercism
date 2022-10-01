#include <stdint.h>

#ifndef RATIONAL_NUMBERS_H
#define RATIONAL_NUMBERS_H

typedef struct {
  int16_t numerator;
  int16_t denominator;
} rational_t;

rational_t divide(rational_t r1, rational_t r2);
rational_t multiply(rational_t r1, rational_t r2);
rational_t subtract(rational_t r1, rational_t r2);
rational_t add(rational_t r1, rational_t r2);
rational_t absolute(rational_t r1);
rational_t reduce(rational_t r);
int16_t gcd(int Num1, int Num2);
int16_t int_pow(int16_t base, int16_t pow);
float exp_real(uint16_t x, rational_t r);
rational_t exp_rational(rational_t r, int16_t n);


#endif
