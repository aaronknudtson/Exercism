#include "armstrong_numbers.h"
#include <stdio.h>

bool is_armstrong_number(int candidate) {
  int n = candidate;
  int digits = 0;
  do {
    n /= 10;
    ++digits;
  } while (n != 0);
  
  n = candidate;
  int sum = 0;
  while (n > 0) {
    int i;
    int num = 1;
    for (i = 0; i < digits; i++) {
      num = num * (n % 10); // last digit
    }
    sum = sum + num;
    n = n / 10;
  }

  if (sum == candidate) {
    return 1;
  } 

  return 0;
}
