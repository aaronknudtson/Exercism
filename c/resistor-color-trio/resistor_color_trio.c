#include "resistor_color_trio.h"
#include <math.h>

resistor_value_t color_code(resistor_band_t bands[]) {
  int value = (10 * bands[0] + bands[1]) * pow(10,bands[2]);
  resistor_band_t unit;
  if (value % 1000 == 0) {
    value = value / 1000;
    unit = KILOOHMS; 
  } else {
    unit = OHMS;
  }
  return (resistor_value_t){ value, unit};
}
