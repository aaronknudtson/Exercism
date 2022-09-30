#include "hamming.h"
#include <string.h>

int compute(const char *lhs, const char *rhs) {
  int length = strlen(lhs);
  int rhlength = strlen(rhs);
  if (length != rhlength) {
    return -1;
  }

  int distance = 0;  
  for (int i = 0; i < length; i++) {
    if (lhs[i] != rhs[i]) {
      distance++;
    } 
  }
  return distance;
}
