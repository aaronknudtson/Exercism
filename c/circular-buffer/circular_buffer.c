#include "circular_buffer.h"
#include <stdlib.h>
#include <errno.h>


void inc_read(circular_buffer_t *buffer) {
  if (buffer->next_read + 1 == buffer->capacity) {
    buffer->next_read = 0;
  } else {
    buffer->next_read++;
  }
}

void inc_write(circular_buffer_t *buffer) {
  if (buffer->next_write + 1 == buffer->capacity) {
    buffer->next_write = 0;
  } else {
    buffer->next_write++;
  }
}

int16_t write(circular_buffer_t *buffer, buffer_value_t value) {
  if (buffer->length == buffer->capacity) {
    errno = ENOBUFS; 
    return EXIT_FAILURE;
  } 
  buffer->values[buffer->next_write] = value;

  inc_write(buffer);
  buffer->length++; 

  return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value) {
  if (buffer->length == buffer->capacity) {
    inc_read(buffer);
  } else {
    buffer->length++; 
  } 
  buffer->values[buffer->next_write] = value;

  inc_write(buffer);

  return EXIT_SUCCESS;
}

int16_t read(circular_buffer_t *buffer, buffer_value_t *value) {
  if (!buffer || !value || buffer->length == 0) {
    errno = ENODATA;
    return EXIT_FAILURE;
  }
  *value = buffer->values[buffer->next_read];
  buffer->values[buffer->next_read] = 0;
  inc_read(buffer);
  buffer->length--;

  return EXIT_SUCCESS;
}

circular_buffer_t *new_circular_buffer(int capacity) {
  circular_buffer_t *buffer = malloc(sizeof(circular_buffer_t) + sizeof(buffer_value_t) * capacity);
  if (!buffer) {
    return NULL;
  }

  buffer->capacity = capacity;
  clear_buffer(buffer);
  return buffer;
}

void clear_buffer(circular_buffer_t *buffer) {
  buffer->next_write = 0;
  buffer->next_read = 0;
  buffer->length = 0;
  // leave capacity
  for (int16_t i = 0; i < buffer->capacity; i++) {
    buffer->values[i] = 0;
  }
}

void delete_buffer(circular_buffer_t *buffer) {
  free(buffer);
}

