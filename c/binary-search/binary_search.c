#include "binary_search.h"
#include <stdlib.h>

const int *binary_search(int value, const int *arr, size_t length) {
  int lo = 0;
  int hi = length;
  while (lo < hi) {
    int mdpt = lo + (hi - lo) / 2;   
    int curr = arr[mdpt];
    if (curr == value) {
      return &arr[mdpt];
    } else if (curr > value) {
      hi = mdpt;
    } else {
      lo = mdpt + 1;
    }
  } 
  return NULL;
}
