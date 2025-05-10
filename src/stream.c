#include "../include/Basic/stream.h"
#include <stdio.h>
#include <stdlib.h>

str read(streams *stream, int readsize) {
  printf("File<< ");
  scanf_s("%s", stream->writebuffer, (unsigned)_countof(stream->writebuffer));
  errno_t err = fopen_s(&stream->file, stream->writebuffer, "r");
  switch (err) {
  case 0:
    printf("Opened file %s\n", stream->writebuffer);
  case 1:
    fprintf(stderr, "Couldn't Open File %s\n", stream->writebuffer);
  }
  stream->readBuffer = malloc(sizeof(char) * readsize);
  fgets(stream->readBuffer, readsize, stream->file);
  return stream->readBuffer;
}
