#include "saddle_points.h"
#include "generic-linked-list.h"
#include <stdlib.h>
#include <string.h>

void free_saddle_points(saddle_points_t *points) {
  free(points->points);
  free(points);
}

g_list_t* find_max(uint8_t ncols, uint8_t row[ncols]) {
  uint8_t max = 0;
  g_list_t *maxidxs = g_list_new();

  for (uint8_t i = 0; i < ncols; ++i) {
    if (i == 0 || row[i] > max) {
      g_list_clear(maxidxs);
      uint8_t *idx = malloc(sizeof(uint8_t));
      *idx = i;
      max = row[i];
      g_list_push(maxidxs, idx);
    } else if (row[i] == max) {
      uint8_t *idx = malloc(sizeof(uint8_t));
      *idx = i;
      max = row[i];
      g_list_push(maxidxs, idx);
    }
  }
  return maxidxs;
}

saddle_points_t *saddle_points(uint8_t nrows, uint8_t ncols, uint8_t matrix[nrows][ncols]) {

  saddle_point_t points[nrows];
  uint8_t pcount = 0; 
  // grab row, send to find_max function, it will return a linked list
  for (uint8_t row = 0; row < nrows; ++row) {
    g_list_t *max_in_row = find_max(ncols, matrix[row]);
    // cycle through cols, check if min 
    for (uint8_t *idx = g_list_pop(max_in_row); idx; idx = g_list_pop(max_in_row)) {
      bool is_saddlepoint = true; 
      for (uint8_t r = 0; r < nrows; r++) {
        if (matrix[row][*idx] > matrix[r][*idx]) {
          is_saddlepoint = false;
          break;
        }
      }
      if (is_saddlepoint) {
        points[pcount] = (saddle_point_t){ row + 1, *idx + 1 };
        pcount++;
      }
    }
    g_list_destroy(max_in_row);
  }
  saddle_points_t *out = malloc(sizeof(saddle_points_t));
  out->count = pcount;
  out->points = malloc(sizeof(saddle_point_t) * pcount);
  memcpy(out->points, points, sizeof(saddle_point_t) * pcount);

  return out;
}
