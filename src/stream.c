#include "../include/Basic/stream.h"
#include <stdio.h>
#include <stdlib.h>

void read(streams *stream, int readsize) {
  printf("Allocating....\n");

  if (stream == NULL) {
    fprintf(stderr, "Invalid stream pointer\n");
    exit(-6);
  }

  if (stream->writebuffer == NULL) {
    fprintf(stderr, "Write buffer not allocated\n");
    exit(-7);
  }

  printf("File>> ");
  scanf_s("%s", stream->writebuffer, readsize);

  printf("\n Looking for %s....\n", stream->writebuffer);

  errno_t err = fopen_s(&stream->file, stream->writebuffer, "r");
  if (err != 0) {
    fprintf(stderr, "Couldn't Open File %s\n", stream->writebuffer);
    exit(-3);
  }

  printf("Opened file %s\n", stream->writebuffer);

  stream->readbuffer = malloc(sizeof(char) * readsize);
  if (stream->readbuffer == NULL) {
    fprintf(stderr, "Failed to allocate read buffer\n");
    fclose(stream->file);
    exit(-5);
  }

  while (fgets(stream->readbuffer, readsize, stream->file)) {
    printf_s("%s", stream->readbuffer);
  }

  fclose(stream->file);
  free(stream->readbuffer);
}
