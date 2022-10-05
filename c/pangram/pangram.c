#include "pangram.h"
#include <ctype.h>

bool is_pangram(const char *sentence) {
  if (sentence == NULL) {
    return false;
  }
  int length = strlen(sentence);  

  // initialize
  bool anagrams[26];
  for (int i = 0; i < 26; i++) {
    anagrams[i] = false;
  }

  // loop and check idxs
  for (int i = 0; i < length; i++) {
    char elem = tolower(sentence[i]); 
    if (elem >= 'a' && elem <= 'z') {
      anagrams[elem - 'a'] = true;
    } 
  }

  // loop and check if any are false
  for (int i = 0; i < 26; i++) {
    if (!anagrams[i]) {
      return false;
    }
  }
  return true;
}
