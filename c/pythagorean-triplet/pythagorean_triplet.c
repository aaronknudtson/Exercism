#include "pythagorean_triplet.h"
#include <stdint.h>
#include <stdlib.h>

triplets_t *triplets_with_sum(uint16_t sum) {

  triplet_t triplets[sum];
  uint16_t count = 0;
  for (uint16_t c = 1; c < sum; ++c) {
    for (uint16_t i = 1; i < c; ++i) {
      uint16_t a = i;
      uint16_t b = sum - c - i;
      if (a > b) {
        break;
      }
      if (a*a + b*b != c*c) {
        continue;
      } 

      uint8_t repeat = 0;
      for (uint8_t i = 0; i < count; ++i) {
        triplet_t curr = triplets[i];
        if ((a == curr.a && b == curr.b) || (a == curr.b && b == curr.a)) {
          repeat = 1;
          break;
        }
      }
      if (repeat == 0) {
        triplets[count] = (triplet_t){ a, b, c };
        ++count;
      }
    }
  }

  triplets_t *out = malloc(sizeof(count) + sizeof(triplet_t) * count); 
  out->count = count;
  for (uint16_t i = 0; i < count; ++i) {
    out->triplets[i] = triplets[i];
  }
  return out;
}

void free_triplets(triplets_t *triplets) {
  free(triplets);
}
