#include "rail_fence_cipher.h"

char *encode(char *text, size_t rails) {
  int length = strlen(text);
  // initiate rails
  char **data = malloc(sizeof(*data) * (int)rails);
  for (int i = 0; i < (int)rails; ++i) data[i] = malloc(sizeof(char) * length);
  for (int i = 0; i < (int)rails; ++i) {
    for (int j = 0; j < length; ++j) {
      data[i][j] = 0;
    }
  }

  // set in zigzag pattern
  int rail = 0;
  bool ascending = true;
  for (int i = 0; i < length; ++i) {
    data[rail][i] = text[i];
    if (rail == 0) {
      ascending = false;
    } else if (rail == (int)rails - 1) {
      ascending = true;
    }
    if (ascending) {
      rail--;
    } else {
      rail++;;
    }
  }
  // read in zigzag pattern and assign character
  int curr = 0;
  char *out = malloc(sizeof(char) * length);
  for (int i = 0; i < (int)rails; ++i) {
    for (int j = 0; j < length; ++j) {
      if (data[i][j] != 0) {
        out[curr++] = data[i][j];
      } 
    }
  }
  return out;
}

char *decode(char *ciphertext, size_t rails) {
  // ? . . . ? . . . ? . . . ? . . . ? . . . ? . . . ?
  // . ? . ? . ? . ? . ? . ? . ? . ? . ? . ? . ? . ? .
  // . . ? . . . ? . . . ? . . . ? . . . ? . . . ? . .
  int length = strlen(ciphertext);

  char **data = malloc(sizeof(*data) * (int)rails);
  for (int i = 0; i < (int)rails; ++i) data[i] = malloc(sizeof(char) * length);
  for (int i = 0; i < (int)rails; ++i) {
    for (int j = 0; j < length; ++j) {
      data[i][j] = 0;
    }
  }

  // assign entire 1st rail, then 2nd, etc...
  int n_positions = 2 * rails - 2;
  int curr = 0;
  for (int i = 0; i < (int)rails; ++i) {
    for (int j = 0; j < length; ++j) {
      int position = j % n_positions;
      if (position == i) {
        data[i][j] = ciphertext[curr++]; 
      } else if (position == n_positions - i) {
        data[i][j] = ciphertext[curr++]; 
      }
    }
  }

  // read along zigzag pattern and set to new string
  curr = 0;
  int rail = 0;
  char *out = malloc(sizeof(char) * length);
  bool ascending = true;
  for (int i = 0; i < length; ++i) {
    out[curr++] = data[rail][i];
    // switch direction
    
    if (rail == 0) {
      ascending = false;
    } else if (rail == (int)rails - 1) {
      ascending = true;
    }
    if (ascending) {
      rail--;
    } else {
      rail++;;
    }
  }
  return out;
}
