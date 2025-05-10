#include "../include/Basic/stream.h"
#include <stdio.h>
#include <stdlib.h>

void read(streams *stream, int readsize) {
  printf("File<< ");
  scanf_s("%s", stream->writebuffer, (unsigned)_countof(stream->writebuffer));
  printf("\n Looking for %s....\n", stream->writebuffer);
  errno_t err = fopen_s(&stream->file, stream->writebuffer, "r");
  switch (err) {
  case 0:
    printf("Opened file %s\n", stream->writebuffer);
  case 1:
    fprintf(stderr, "Couldn't Open File %s\n", stream->writebuffer);
    exit(-3);
  }
  stream->readbuffer = malloc(sizeof(char) * readsize);
  while (fgets(stream->readbuffer, readsize, stream->file)) {
    printf_s("%s", stream->readbuffer);
  }
  fclose(stream->file);
  free(stream);
  if (stream != NULL || stream->readbuffer != NULL ||
      stream->writebuffer != NULL) {
    fprintf(stderr, "Couldn't Free File I/O Buffer\n");
    exit(-4);
  }
}
