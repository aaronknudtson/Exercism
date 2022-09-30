#include "difference_of_squares.h"


unsigned int difference_of_squares(unsigned int number) {
  return  square_of_sum(number) - sum_of_squares(number);
}
unsigned int sum_of_squares(unsigned int n) {
  return (n * (n + 1) * (2 * n + 1)) / 6; // this is a handy dandy formuler!
}

unsigned int square_of_sum(unsigned int n) {
  unsigned int sum = (n * (n + 1)) / 2; // this is a handy dandy formuler!
  return sum * sum;
}
