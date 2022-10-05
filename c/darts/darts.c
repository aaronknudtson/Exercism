#include "darts.h"


uint8_t score(coordinate_t pos) {
  float rad = sqrtf(pos.x*pos.x + pos.y*pos.y);
  if (rad <= 1) {
    return 10;
  } else if (rad <= 5) {
    return 5;
  } else if (rad <= 10) {
    return 1;
  }
  return 0;
}
