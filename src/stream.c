#include "../include/Basic/stream.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read(streams *stream, int readsize) {
  if (stream == NULL) {
    fprintf(stderr, "Invalid stream pointer\n");
    exit(-6);
  }

  printf("File>> ");

  stream->writebuffer = malloc(sizeof(char) * readsize);
  scanf_s("%s", stream->writebuffer, readsize);
  if (stream->writebuffer == NULL || strcmp(stream->writebuffer, "") == 0) {
    fprintf_s(stderr, "Write buffer not allocated\n");
    free(stream->writebuffer);
    exit(-7);
  }

  printf("\n Looking for %s....\n", stream->writebuffer);

  errno_t err = fopen_s(&stream->file, stream->writebuffer, "r");
  if (err != 0) {
    fprintf_s(stderr, "Couldn't Open File %s\n", stream->writebuffer);
    free(stream->writebuffer);
    return;
  }

  printf("Opened file %s\n", stream->writebuffer);

  stream->readbuffer = malloc(sizeof(char) * readsize);
  if (stream->readbuffer == NULL) {
    fprintf(stderr, "Failed to allocate read buffer\n");
    free(stream->writebuffer);
    fclose(stream->file);
    return;
  }

  while (fgets(stream->readbuffer, readsize, stream->file)) {
    printf_s("%s", stream->readbuffer);
  }

  fclose(stream->file);
  free(stream->readbuffer);
}

void create(streams *stream, int readsize) {
  if (stream == NULL) {
    fprintf(stderr, "Invalid stream Pointer\n");
  }

  printf("File>> ");
  stream->writebuffer = malloc(sizeof(char) * readsize);
  if (readsize == 0 || stream->writebuffer == 0) {
    fprintf(stderr, "Couldn't Allocate\n");
    return;
  }
  scanf_s("%s", stream->writebuffer, readsize);
  errno_t err = fopen_s(&stream->file, stream->writebuffer, "w");
  if (err != 0) {
    fprintf_s(stderr, "Couldn't Create File named %s\n", stream->writebuffer);
    free(stream->writebuffer);
    return;
  }

  fclose(stream->file);
}
