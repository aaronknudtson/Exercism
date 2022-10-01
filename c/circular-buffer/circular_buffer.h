#include <stdint.h>

#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

typedef int16_t buffer_value_t;

typedef struct {
  int next_write;
  int next_read;
  int capacity;
  int length;
  buffer_value_t values[];
} circular_buffer_t;

int16_t write(circular_buffer_t *buffer, buffer_value_t value);
int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value);
int16_t read(circular_buffer_t *buffer, buffer_value_t *value);
circular_buffer_t * new_circular_buffer(int capacity);
void clear_buffer(circular_buffer_t *buffer);
void delete_buffer(circular_buffer_t *buffer);
void inc_read(circular_buffer_t *buffer);
void inc_write(circular_buffer_t *buffer);


#endif
