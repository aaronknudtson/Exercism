#include "allergies.h"
#include <stdlib.h>


static allergen_t allergens[] = {
   ALLERGEN_EGGS,
   ALLERGEN_PEANUTS,
   ALLERGEN_SHELLFISH,
   ALLERGEN_STRAWBERRIES,
   ALLERGEN_TOMATOES,
   ALLERGEN_CHOCOLATE,
   ALLERGEN_POLLEN,
   ALLERGEN_CATS,
   ALLERGEN_COUNT,
};

allergen_list_t get_allergens(uint16_t value) {
  value = value % 256;
  int length = sizeof(allergens) / sizeof(allergens[0]);
  allergen_list_t *out = malloc(sizeof(int) + sizeof(bool) * length);
  out->count = 0;

  for (int i = 0; i < length - 1; ++i) {
    // go through mask
    int mask = 1 << i;
    int masked_bit = value & mask;
    int bit = masked_bit >> i;

    if (bit == 1) {
      out->allergens[allergens[allergens[i]]] = true;
      out->count++;
    }
  }
  return *out;
}

bool is_allergic_to(allergen_t allergen, uint16_t value) {
  allergen_list_t list = get_allergens(value);
  return list.allergens[allergen];
}
