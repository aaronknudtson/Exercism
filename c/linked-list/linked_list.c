#include "linked_list.h"
#include <stdlib.h>

struct list_node {
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list {
   struct list_node *first, *last;
};

// constructs a new (empty) list
struct list *list_create(void) {
  struct list *new = calloc(1, sizeof(struct list));
  new->first = new->last = NULL; 
  return new;
}

// counts the items on a list
size_t list_count(const struct list *list) {
  size_t count = 0;
  struct list_node *curr = list->first;
  while (curr != NULL) {
    count++;
    curr = curr->next;
  }
  return count;
}

// inserts item at back of a list
void list_push(struct list *list, ll_data_t item_data) {
  // set up node
  struct list_node *node = calloc(1, sizeof(struct list_node));
  node->prev = list->last;
  node->next = NULL;
  node->data = item_data;

  if (node->prev == NULL) {
    list->first = node;
  } else {
    node->prev->next = node;
  }
  // attach to back of list
  list->last = node;
}

// removes item from back of a list
ll_data_t list_pop(struct list *list) {
  struct list_node *tmp = list->last;
  // unlink
  list->last = list->last->prev;
  tmp->prev = NULL;


  if (list->last == NULL) {
    list->first = NULL;
  } else {
    list->last->next = NULL;
  }

  ll_data_t data = tmp->data;
  free(tmp);

  return data;
}

// inserts item at front of a list
void list_unshift(struct list *list, ll_data_t item_data) {
  struct list_node *node = calloc(1, sizeof(struct list_node));
  node->prev = NULL;
  node->next = list->first;
  node->data = item_data;
  if (node->next == NULL) {
    list->last = node;
  } else {
    list->first->prev = node;
  }

  list->first = node;
}

// removes item from front of a list
ll_data_t list_shift(struct list *list) {
  ll_data_t data = list->first->data;

  struct list_node *tmp = list->first;
  list->first = tmp->next;
  tmp->next = NULL;
  if (list->first == NULL) {
    list->last = NULL;
  } else {
    list->first->prev = NULL;
  }
  free(tmp);

  return data;
}

// deletes a node that holds the matching data
void list_delete(struct list *list, ll_data_t data) {
  struct list_node *curr = list->first;
  while (curr != NULL) {
    if (curr->data == data) {
      break;
    }
    curr = curr->next;
  }
  if (curr == NULL) {
    return;
  }
  if (curr->prev == NULL) {
    list->first = curr->next;
  } else {
    curr->prev->next = curr->next;
  }
  if (curr->next == NULL) {
    list->last = curr->prev;
  } else {
    curr->next->prev = curr->prev;
  }
  curr->next = curr->prev = NULL;
  free(curr);
}

// destroys an entire list
// list will be a dangling pointer after calling this method on it
void list_destroy(struct list *list) {
  // until prev is null

  while (list->first != NULL) {
    struct list_node* next = list->first->next;
    free(list->first);
    list->first = next;
  }
  free(list);

}
