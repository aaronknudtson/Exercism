#include "isogram.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

bool is_isogram(const char phrase[]) {
  if (phrase == NULL) {
    return 0;
  }
  int length = strlen(phrase);
  int test_idx = 0;
  do {
    int test_char = tolower(phrase[test_idx]);

    for (int i = test_idx; i < length; i++) {
      int ichar = tolower(phrase[i]);

      if (ichar == test_char && test_idx != i) {
        printf("%c,%c\n",test_char,phrase[i]);
        if (ichar == '-' || ichar == ' ') {
          continue;
        } else {
          return 0;
        }
      }

    }

    test_idx++;
  } while (test_idx < length);

  return 1;
}
