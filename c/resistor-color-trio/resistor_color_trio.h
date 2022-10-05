#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H

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
  WHITE,
  OHMS = 69,
  KILOOHMS = 420
} resistor_band_t;

typedef struct {
  int value;
  resistor_band_t unit;
} resistor_value_t; 

resistor_value_t color_code(resistor_band_t bands[]);

#endif
