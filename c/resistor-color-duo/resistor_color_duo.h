#ifndef RESISTOR_COLOR_DUO_H
#define RESISTOR_COLOR_DUO_H
#include <stdint.h>

typedef int resistor_band_t;
typedef enum {
  BLACK,
  BROWN,
  RED,
  ORANGE,
  YELLOW,
  GREEN,
  BLUE,
  VIOLET,
  GREY,
  WHITE
} band_color_t;

uint16_t color_code(resistor_band_t *bands);

#endif
