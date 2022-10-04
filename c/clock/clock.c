#include "clock.h"


clock_t clock_create(int hour, int minute) {
  while (minute < 0 || hour < 0) {
    if (minute < 0) {
      minute += 60;
      hour -= 1;
    }
    if (hour < 0) {
      hour += 24;
    }
  }
  hour = (hour + minute / 60) % 24;
  minute = minute % 60;
  clock_t clock = {{ hour / 10 + '0', hour % 10 + '0', ':', minute / 10 + '0', minute % 10 + '0' }};
  return clock;
}

clock_t clock_add(clock_t clock, int minute_add) {
  int hours = 10 * (clock.text[0] - '0') + (clock.text[1] - '0');
  int minutes = 10 * (clock.text[3] - '0') + (clock.text[4] - '0');
  return clock_create(hours, minutes + minute_add);
}

clock_t clock_subtract(clock_t clock, int minute_subtract) {
  int hours = 10 * (clock.text[0] - '0') + (clock.text[1] - '0');
  int minutes = 10 * (clock.text[3] - '0') + (clock.text[4] - '0');
  return clock_create(hours, minutes - minute_subtract);
}

bool clock_is_equal(clock_t a, clock_t b) {
  for (int i = 0; i < 6; ++i) {
    if (a.text[i] != b.text[i]) {
      return false;
    }
  }
  return true;
}

