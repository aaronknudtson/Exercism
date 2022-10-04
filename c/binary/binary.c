#include "binary.h"
#include <string.h>
#include <stdbool.h>

int convert(const char *input) {
  int length = strlen(input); 
  int out = 0;
  for (int i = 0; i < length; ++i) {
    char elem = input[i];
    bool is_valid = elem == '0' || elem == '1';
    if (!is_valid) {
      return -1;
    }

    out <<= 1;
    if (elem == '1') {
      out++;
    }
  }
  return out;
}
