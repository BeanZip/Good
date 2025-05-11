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
  scanf("%s", stream->writebuffer);
  if (stream->writebuffer == NULL || strcmp(stream->writebuffer, "") == 0) {
    fprintf(stderr, "Write buffer not allocated\n");
    free(stream->writebuffer);
    exit(-7);
  }

  printf("\n Looking for %s....\n", stream->writebuffer);

  stream->file = fopen(stream->writebuffer, "r");

  printf("Opened file %s\n", stream->writebuffer);

  stream->readbuffer = malloc(sizeof(char) * readsize);
  if (stream->readbuffer == NULL) {
    fprintf(stderr, "Failed to allocate read buffer\n");
    free(stream->writebuffer);
    fclose(stream->file);
    return;
  }

  while (fgets(stream->readbuffer, readsize, stream->file)) {
    printf("%s\n", stream->readbuffer);
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
  scanf("%s", stream->writebuffer);
  stream->file = fopen(stream->writebuffer, "w");
  fclose(stream->file);
}

void write(streams *stream, int readsize) {
  if (stream == NULL) {
    fprintf(stderr, "Couldn't access stream\n");
    return;
  }
  printf("File>> ");
  stream->writebuffer = malloc(sizeof(char) * readsize);
  scanf("%s", stream->writebuffer);
  stream->file = fopen(stream->writebuffer, "w");
  printf("Write>> ");
  scanf("%s", stream->writebuffer);
  fprintf(stream->file, "%s", stream->writebuffer);
  fclose(stream->file);
}
