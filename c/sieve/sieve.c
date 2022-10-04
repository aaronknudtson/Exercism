#include "sieve.h"
#include <stdbool.h>

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
  bool multiples[limit + 3];
  uint32_t count = 0;
  for (uint32_t i = 0; i <= limit; ++i) {
    // initialize array
    multiples[i] = false;
  } 
  for (uint32_t i = 2; i <= limit; ++i) {
    if (multiples[i]) {
      continue;
    }
    primes[count++] = i;  
    if (count == max_primes) {
      return count;
    }
    uint32_t multiple = i;
    while (multiple <= limit) {
      multiples[multiple] = true;
      multiple += i;
    }
  }
  return count;
}
