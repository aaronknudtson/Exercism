#include "word_count.h"

int count_words(const char *sentence, word_count_word_t *words) {
  int rolling_count = 0;
  int length = strlen(sentence);
  char *curr = calloc(MAX_WORD_LENGTH, sizeof(char));

  for (int i = 0; i < length;) {
    while (tolower(sentence[i]) < 'a' || tolower(sentence[i]) > 'z') {
      if (sentence[i] >= '0' && sentence[i] <= '9') {
        break;
      }
      i++;
    }
    memset(curr, 0, MAX_WORD_LENGTH);
    // get the word
    int count = 0;
    while (i + count < length) {
      curr[count] = sentence[i + count];
      count++;
      // if (sentence[i + count] == ' ' || sentence[i + count] == ',' || sentence[i + count] == ':' || sentence[i + count] == '!' || sentence[i + count] == '.') {
      if ((sentence[i + count] < '0' && sentence[i + count] != '\'') || (sentence[i + count] > '9' && sentence[i + count] < 'A')) {
        break;
      }
    }
    // check if word in array. if not, add it 
    for (int j = 0; j < MAX_WORDS; j++) {
      //cleanup
      *curr = tolower(*curr);  
      for (int i = 0; i < MAX_WORD_LENGTH; ++i) curr[i] = tolower(curr[i]);
      for (int i = 0; i < MAX_WORD_LENGTH; ++i) if (curr[i] == '\'' && curr[i+1] == 0) curr[i] = 0;
       
      
      if (words[j].count == 0) {
        rolling_count++;
        strcpy(words[j].text, curr);
        words[j].count++;;
        break;
      } else if (strcmp(words[j].text, curr) == 0) {
        words[j].count++;;
        break;
      }
    }
    i+=count+1;

    while (tolower(sentence[i]) < 'a' || tolower(sentence[i]) > 'z') {
      if (sentence[i] >= '0' && sentence[i] <= '9') {
        break;
      }
      i++;
    }
  }
  return rolling_count;
}
