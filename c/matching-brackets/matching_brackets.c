#include "matching_brackets.h"
#include <stdlib.h>
#include <string.h>

char opens[] = { '{', '[', '(' };
char closes[] = { '}', ']', ')' };

int get_idx(char arr[3], char n) {
  for (int i = 0; i < 3; ++i) {
    if (arr[i] == n) {
      return i;
    }
  }
  return -1;
}

bool is_paired(const char *input) {
  int length = strlen(input);  
  char *arr = malloc(sizeof(char) * length);
  for (int i = 0; i < length; ++i) arr[i] = 0;
  int count = 0; 
  for (int i = 0; i < length; ++i){
    bool match_open = false;
    bool match_close = false;
    for (int j = 0; j < 3; j++) {
      if (opens[j] == input[i]) {
        match_open = true;
        break;
      }
      if (closes[j] == input[i]) {
        match_close = true;
        break;
      }
    }

    if (match_open) {
      arr[count++] = input[i];
    } else if (match_close) {
      if (arr[--count] != opens[get_idx(closes, input[i])]) {
        return false;
      } else {
        arr[count] = 0;
      }
    }
  } 

  if (arr[0] != 0) return false; else return true;
  return true;
}

