#include "resistor_color_duo.h"
#include <stdio.h>

uint16_t color_code(resistor_band_t bands[]) {
  return 10 * bands[0] + bands[1];
}
