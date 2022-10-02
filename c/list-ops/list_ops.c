#include "list_ops.h"
#include <string.h> 

// constructs a new list
list_t *new_list(size_t length, list_element_t elements[]) {

  list_t *list = malloc(sizeof(size_t) + sizeof(list_element_t) * length);
  for (size_t i = 0; i < length; i++) {
    list->elements[i] = elements[i]; 
  }
  // memcpy(list->elements, elements, sizeof(*elements));
  list->length = length;
  return list;
}

// append entries to a list and return the new list
list_t *append_list(list_t *list1, list_t *list2) {
  size_t l1, l2; 
  l1 = length_list(list1);
  l2 = length_list(list2);
  list_element_t elements[l1 + l2];
  for (size_t i = 0; i < l1 + l2; i++) {
    if (i < l1) {
      elements[i] = list1->elements[i]; 
    } else {
      elements[i] = list2->elements[i - l1]; 
    }
  }
  return new_list(l1 + l2, elements);
}

// filter list returning only values that satisfy the filter function
list_t *filter_list(list_t *list, bool (*filter)(list_element_t)) {
  size_t length = length_list(list);
  list_element_t elements[length];
  int idx = 0;
  for (size_t i = 0; i < length; ++i) {
    if (filter(list->elements[i])) {
      elements[idx] = list->elements[i];
      ++idx; 
    } 
  }
  list_element_t only_elements[idx + 1];
  memcpy(only_elements, elements, sizeof(list_element_t) * (idx + 1));
  return new_list(idx, only_elements);
}

// returns the length of the list
size_t length_list(list_t *list) {
  return list->length;
}

// return a list of elements whose values equal the list value transformed by
// the mapping function
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)) {
  size_t length = length_list(list);
  list_element_t elements[length];
  for (size_t i = 0; i < length; ++i) {
    elements[i] = map(list->elements[i]);    
  }
  return new_list(length, elements);
}

// folds (reduces) the given list from the left with a function
list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t)) {
  size_t length = length_list(list);
  list_element_t sum = initial;
  for (size_t i = 0; i < length; ++i) {
    sum = foldl(list->elements[i], sum); 
  }
  return sum;
}

// folds (reduces) the given list from the right with a function
list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t)) {
  size_t length = length_list(list);
  list_element_t sum = initial;
  for (size_t i = length; i > 0; --i) {
    sum = foldr(list->elements[i - 1], sum); 
  }
  return sum;
}

// reverse the elements of the list
list_t *reverse_list(list_t *list) {
  size_t length = length_list(list);
  list_element_t elements[length];
  for (size_t i = 0; i < length; ++i) {
    elements[length - 1 - i] = list->elements[i];
  }
  return new_list(length, elements);
}

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(list_t *list) {
  free(list);
}
