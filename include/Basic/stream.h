#include <stdio.h>
#ifndef STREAM_H
#define STREAM_H

typedef char *str;

typedef struct {
  FILE *file;
  char *writebuffer;
  char *readBuffer;
} streams;

str read(streams *stream, int readsize);

#endif
