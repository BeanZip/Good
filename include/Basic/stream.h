#include <stdio.h>
#ifndef STREAM_H
#define STREAM_H

typedef char *str;

typedef struct {
  FILE *file;
  char *writebuffer;
  char *readbuffer;
} streams;

void read(streams *stream, int readsize);
void create(streams *stream, int readsize);
void write(streams *stream, int readsize);
void incinerate(streams *stream, int readsize);
#endif
