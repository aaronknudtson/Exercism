#include "acronym.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

char *abbreviate(const char *phrase) {
  if (phrase == NULL) {
    return NULL;
  }
  int length = strlen(phrase);
  if (length == 0) {
    return NULL;
  }
  bool next_is = true;
  char *out = calloc(length, sizeof(char));
  int count = 0;
  for (int i = 0; i < length; ++i) {
    if (phrase[i] == ' ' || phrase[i] == '-') {
      next_is = true;
    } else if (next_is && ((phrase[i] >= 'A' && phrase[i] <= 'Z') || (phrase[i] >= 'a' && phrase[i] <= 'z'))) {
      out[count++] = toupper(phrase[i]);
      next_is = false;
    } 
  }
  return out;
}
