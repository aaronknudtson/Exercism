#include "pascals_triangle.h"
#include <stdlib.h>

void free_triangle(uint8_t **triangle, size_t rows) {
  for (uint8_t i = 0; i < rows; ++i) {
    free(triangle[i]);
  }
  free(triangle);
}

uint8_t **create_triangle(size_t rows) {
  if (rows == 0) {
    uint8_t **triangle = malloc(sizeof(*triangle) * 1);
    triangle[0] = malloc(sizeof(uint8_t) * 1);
    triangle[0][0] = 0;
    return triangle;
  }
  uint8_t **triangle = malloc(sizeof(*triangle) * rows);
  for (size_t row = 0; row < rows; ++row) {
    triangle[row] = malloc(sizeof(uint8_t) * rows);
    for (size_t idx = 0; idx < rows; ++idx) {
      triangle[row][idx] = 0;
    }
  }
  triangle[0][0] = 1;
  for (size_t i = 1; i < rows; ++i) {
    for (size_t j = 0; j < i + 1; ++j) {
      if (j == 0) {
        // left edge
        triangle[i][j] = triangle[i - 1][j];
      } else if (j == i) {
        // right edge
        triangle[i][j] = triangle[i - 1][j - 1];
      } else {
        triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
      }
    }   
  }
  return triangle;
}
