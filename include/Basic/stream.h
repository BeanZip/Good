#include <stdio.h>
#ifndef STREAM_H
#define STREAM_H

typedef char *str;


/**
 * @brief Struct to hold the file stream and buffers
 * @param FILE *file - Pointer to the file stream
 * @param char *wBuffer - Pointer to the write buffer
 * @param char *rBuffer - Pointer to the read buffer
 */
typedef struct {
  FILE *file;
  char *wBuffer;
  char *rBuffer;
} streams;

void read(streams *stream, int size);
void create(streams *stream, int size);
void write(streams *stream, int size);
void incinerate(streams *stream, int size);
#endif
