#include <stdint.h>
#include "generic-linked-list.h"

#ifndef SADDLE_POINTS_H
#define SADDLE_POINTS_H

typedef struct {
  uint8_t row;
  uint8_t column;
} saddle_point_t;


typedef struct {
  uint8_t count;
  saddle_point_t *points;
} saddle_points_t;

g_list_t* find_max(uint8_t ncols, uint8_t row[ncols]);
saddle_points_t *saddle_points(uint8_t nrows, uint8_t ncols, uint8_t matrix[nrows][ncols]);
void free_saddle_points(saddle_points_t *points);


#endif
