#include "saddle_points.h"
#include <stdlib.h>
#include <string.h>

#include <stdio.h>


void free_saddle_points(saddle_points_t *points) {
  free(points);
}

void add_new_point(group_t *group, uint8_t idx, uint8_t row, uint8_t col, uint8_t value) {
  group->group[idx].points[group->group[idx].count] = (point_t){ row, col };
  group->group[idx].value = value;
  group->group[idx].count++;
}

void clear_points(group_t *group, uint8_t idx) {
  group->group[idx].count = 0;
  group->group[idx].value = 0;
}

saddle_points_t *saddle_points(uint8_t nrows, uint8_t ncols, uint8_t matrix[nrows][ncols]) {
  // max number of points is the min of nrows or ncols
  uint8_t n;
  if (nrows < ncols) {
    n = nrows;
  } else {
    n = ncols;
  }
  group_t *maxr = malloc((sizeof(points_t) + sizeof(point_t) * nrows) * nrows);
  group_t *minc = malloc((sizeof(points_t) + sizeof(point_t) * ncols) * ncols);
  // points_t *minc = malloc(sizeof(points_t) + sizeof(point_t) * ncols);
  // initialize saddle points with extreme points
  for (uint8_t i = 0; i < nrows; ++i) {
    maxr->group[i].value = 0;
    maxr->group[i].count = 0;
  }
  for (uint8_t i = 0; i < ncols; ++i) {
    minc->group[i].value = 255;
    minc->group[i].count = 0;
  }
  // loop and find maxes
  for (uint8_t row = 0; row < nrows; ++row) {
    for (uint8_t col = 0; col < ncols; ++col) {
      if (matrix[row][col] > maxr->group[row].value) {
        clear_points(maxr, row);
        add_new_point(maxr, row, row, col, matrix[row][col]);
      } else if (matrix[row][col] == maxr->group[row].value) {
        // if it is the same as a previous point, it is not a max
        add_new_point(maxr, row, row, col, matrix[row][col]);
      }
      if (matrix[row][col] < minc->group[col].value) {
        clear_points(minc, col);
        add_new_point(minc, col, row, col, matrix[row][col]);
      } else if (matrix[row][col] == minc->group[col].value) {
        // if it is the same as a previous point, it is not a max
        add_new_point(minc, col, row, col, matrix[row][col]);
      }
    }
  }  
  saddle_point_t points[n];
  uint8_t count = 0;
  for (uint8_t row = 0; row < nrows; ++row) {
    for (uint8_t col = 0; col < ncols; ++col) {
      points_t thisrow = maxr->group[row];
      points_t thiscol = minc->group[col];
      // printf("%d\n", minc[col].value);
      // printf("Max in row point: %d,%d, Min in col point: %d,%d\n", maxr[row].row, maxr[row].column, minc[col].row, minc[col].column);
      for (uint8_t row_count = 0; row_count < thisrow.count; row_count++) {
        for (uint8_t col_count = 0; col_count < thiscol.count; col_count++) {
          if (thisrow.points[row_count].row == thiscol.points[col_count].row
            && thisrow.points[row_count].column == thiscol.points[col_count].column) {
            points[count].row = thisrow.points[row_count].row;
            points[count].column = thisrow.points[row_count].column;
            count++;
          }
        }
      }
      // printf("match!\n");
    }
  }
  // assign saddle points
  saddle_points_t *out = malloc(sizeof(n) + sizeof(saddle_point_t) * n);
  out->count = count;
  // memcpy(points, out->points, sizeof(saddle_point_t) * count);
  for (uint8_t i = 0; i < count; ++i) {
    out->points[i].row = points[i].row + 1;
    out->points[i].column = points[i].column + 1;
    // printf("Point: %d, %d\n", out->points[i].row, out->points[i].column);
  }
  return out;
}
