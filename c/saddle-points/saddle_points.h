#include <stdint.h>

#ifndef SADDLE_POINTS_H
#define SADDLE_POINTS_H

typedef struct {
  uint8_t row;
  uint8_t column;
} point_t;

typedef struct {
  uint8_t value;
  uint8_t count;
  point_t points[];
} points_t;

typedef struct {
  points_t group[];
} group_t;

typedef struct {
  uint8_t row;
  uint8_t column;
} saddle_point_t;


typedef struct {
  uint8_t count;
  saddle_point_t points[];
} saddle_points_t;

saddle_points_t *saddle_points(uint8_t nrows, uint8_t ncols, uint8_t matrix[nrows][ncols]);
void free_saddle_points(saddle_points_t *points);


#endif
