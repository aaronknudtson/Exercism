#include "square_root.h"
#include <stdio.h>

unsigned int square_root_recur(unsigned int candidate, unsigned int radicand) {

  unsigned int prev = candidate;
  unsigned int test = candidate * candidate;
  if (test == radicand) 
    return candidate;
  
  if (test > radicand) {
    candidate >>= 2;
  }

  unsigned int next_candidate = candidate + 1;
  if (next_candidate * next_candidate > radicand) {
    if (prev != candidate) {
      return square_root_recur(candidate, radicand);
    } else {
      return 0;
    }
  } else {
    return square_root_recur(next_candidate, radicand);
  }
}

unsigned int square_root(unsigned int radicand) {
  return square_root_recur(radicand, radicand);
}






// unsigned int square_root_tailcall(unsigned int candidate, unsigned int radicand) {
//   // based somewhat on https://en.wikipedia.org/wiki/unsigned integer_square_root#Using_bitwise_operations
//   // I loves me my recursion.
//   // This uses a tail recursive call so it can be optimized on GCC with -O2, -O3 or -Os.
//   // https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
//   // Without tail-call optimization, ran a million times for an average 4.55184e-08 seconds per call
//   // when calculating square root of 65025. That's 45.5184 nanoseconds.
//   unsigned int last_used = candidate;
//   unsigned int try_it = candidate * candidate;
//   if (try_it == radicand)
//     return candidate;
//   // every bit shifted right halves the value, so this divides by 4.
//   if (try_it > radicand)
//     candidate >>= 2;
//   unsigned int large_candidate = candidate + 1;
//   printf("%d\n",try_it);
//   if (large_candidate * large_candidate > radicand) {
//     if (last_used != candidate) {
//       return square_root_tailcall(candidate, radicand);
//     } else {
//       printf("%d\n",candidate);
//       // return 0 if we can't calculate a whole number for square root
//       return 0;
//     }
//   } else {
//     return square_root_tailcall(large_candidate, radicand);
//   }
// }
//
// unsigned int square_root(unsigned int radicand) {
//   return square_root_tailcall(radicand, radicand);
// }
