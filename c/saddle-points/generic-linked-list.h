#ifndef GENERIC_LINKED_LIST
#define GENERIC_LINKED_LIST

#include <stddef.h>
#include <stdbool.h>

struct g_list_node;
struct g_list;

typedef struct g_list_node g_list_node_t;
typedef struct g_list g_list_t;

g_list_t* g_list_new(void);
void g_list_destroy(g_list_t* list);
size_t g_list_count(g_list_t* list);
bool g_list_push(g_list_t* list, void* data);
void* g_list_pop(g_list_t* list);
bool g_list_unshift(g_list_t* list, void* data);
void* g_list_shift(g_list_t* list);
void g_list_clear(g_list_t* list);
void g_list_print(g_list_t* list);

#endif


