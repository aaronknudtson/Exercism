#include "grains.h"
#include <stdint.h>
#include <stdlib.h>

uint64_t * get_squares(uint8_t index) {
  uint64_t * squares;
  squares = malloc(sizeof(uint64_t) * index);
  squares[0] = 1;
  for (int i = 1; i < index; i++) {
    squares[i] = 2 * squares[i - 1];
  }  
  return squares;
}

uint64_t square(uint8_t index) {
  if (index == 0) {
    return 0ull;
  }
  uint64_t * squares;
  squares = get_squares(index);
  return squares[index - 1];
}

uint64_t total(void) {
  uint64_t * squares;
  squares = get_squares(64);
  uint64_t sum = 0;
  for (int i = 0; i < 64; i++) {
    sum += squares[i];
  } 
  return sum;
}

