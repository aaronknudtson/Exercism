#include "generic-linked-list.h"
#include <stdio.h>
#include <stdlib.h>


struct g_list_node {

  void* data;

  g_list_node_t* prev;

  g_list_node_t* next;

};


struct g_list {

  g_list_node_t* first;

  g_list_node_t* last;

};


g_list_t* g_list_new(void)

{

  g_list_t* list = calloc(1, sizeof(g_list_t));


  if (!list) {

    return NULL;

  }


  return list;

}


void g_list_destroy(g_list_t* list)

{

  g_list_clear(list);

  free(list);

}


size_t g_list_count(g_list_t* list)

{

  size_t count = 0;


  for (g_list_node_t* node = list->first; node; node = node->next) {

    count++;

  }


  return count;

}


static g_list_node_t* _new_node(void* data)

{

  g_list_node_t* node = calloc(1, sizeof(g_list_node_t));


  if (!node) {

    return false;

  }


  node->data = data;


  return node;

}


bool g_list_push(g_list_t* list, void* data)

{

  g_list_node_t* node = _new_node(data);


  if (!node) {

    return false;

  }


  node->prev = list->last;


  if (!list->first) {

    list->first = node;

  }


  if (list->last) {

    node->prev = list->last;

    list->last->next = node;

  }



  list->last = node;


  return true;

}


void* g_list_pop(g_list_t* list)

{

  if (!list->last) {

    return NULL;

  }


  g_list_node_t* node = list->last;

  void* data = node->data;


  if (list->first == node) {

    list->first = NULL;

  } else {

    node->prev->next = NULL;

  }



  list->last = node->prev;


  free(node);


  return data;

}


bool g_list_unshift(g_list_t* list, void* data)

{

  g_list_node_t* node = _new_node(data);


  if (!node) {

    return false;

  }


  node->next = list->first;


  if (!list->last) {

    list->last = node;

  }


  if (list->first) {

    node->next = list->first;

    list->first->prev = node;

  }


  list->first = node;


  return true;

}


void* g_list_shift(g_list_t* list)

{

  if (!list->first) {

    return NULL;

  }


  g_list_node_t* node = list->first;

  void* data = node->data;


  if (list->last == node) {

    list->last = NULL;

  } else {

    node->next->prev = NULL;

  }


  list->first = node->next;


  free(node);


  return data;

}


void g_list_clear(g_list_t* list)

{

  g_list_node_t* tmp;


  while (list->first) {

    tmp = list->first;

    list->first = list->first->next;

    free(tmp);

  }


  list->last = NULL;

}


void g_list_print(g_list_t* list)

{

  printf("list: %p, first; %p, last: %p, count: %zu, data: ",

         (void*)list, (void*)list->first, (void*)list->last,

         g_list_count(list));


  for (g_list_node_t* node = list->first; node; node = node->next) {

    printf("[%p %p %p %p] ", (void*)node, (void*)node->prev,

           (void*)node->next, (void*)node->data);

  }


  printf("\n");

}


/*

int main(int argc, char** argv)

{

    g_list_t* list = g_list_new();



    int data[] = {1, 2, 3, 4, 5, 6};



    g_list_push(list, &data[0]);

    g_list_push(list, &data[1]);

    g_list_print(list);



    g_list_unshift(list, &data[2]);

    g_list_unshift(list, &data[3]);

    g_list_print(list);



    g_list_pop(list);

    g_list_print(list);



    g_list_shift(list);

    g_list_print(list);



    g_list_pop(list);

    g_list_pop(list);

    g_list_shift(list);

    g_list_shift(list);

    g_list_print(list);



    g_list_destroy(list);



    return 0;

}
*/
