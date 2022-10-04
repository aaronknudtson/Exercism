#include "phone_number.h"
#include <stdlib.h>
#include <string.h>


#define DIGITS 10
const char chars[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }; 

char *phone_number_clean(const char *input) {
  char *output = calloc(DIGITS + 1, sizeof(char));
  int length = strlen(input);
  if (length < DIGITS) {
    strcpy(output, "0000000000"); 
    return output;
  }
  int idx = DIGITS - 1;
  for (int i = length - 1; i >= 0; --i) {
    for (int j = 0; j < DIGITS; ++j) {
      if (chars[j] == input[i] && idx >= 0) {
        if (idx == 3 && (input[i] == '0' || input[i] == '1')) {
          strcpy(output, "0000000000"); 
          return output;
        }
        output[idx--] = input[i];
        break;
      } else if (idx < 0 && chars[j] == input[i]) {
        if (input[i] != '1') {
          strcpy(output, "0000000000"); 
          return output;
        }
      }
    }
  }
  if (idx >= 0 || output[0] == '0' || output[0] == '1') {
    strcpy(output, "0000000000"); 
    return output;
  }

  return output;
}
