#include "space_age.h"


const float periods[] = { 0.2408467, 0.61519726, 1.0, 1.8808158, 11.862615, 29.447498, 84.016846, 164.79132 };
float age(planet_t planet, int64_t seconds) {
  if (planet < 0 || planet > NEPTUNE) {
    return -1;
  }  
  int64_t earthyears = seconds / 31557600;               
  return earthyears / periods[planet];
}
