#include "../include/Basic/stream.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read(streams *stream, int size) {
  if (stream == NULL) {
    fprintf(stderr, "Invalid stream pointer\n");
    exit(-6);
  }

  printf("File>> ");

  stream->wBuffer = malloc(sizeof(char) * size);
  scanf("%s", stream->wBuffer);
  if (stream->wBuffer == NULL || strcmp(stream->wBuffer, "") == 0) {
    fprintf(stderr, "Write buffer not allocated\n");
    free(stream->wBuffer);
    exit(-7);
  }

  printf("\n Looking for %s....\n", stream->wBuffer);

  stream->file = fopen(stream->wBuffer, "r");

  printf("Opened file %s\n", stream->wBuffer);

  stream->rBuffer = malloc(sizeof(char) * size);
  if (stream->rBuffer == NULL) {
    fprintf(stderr, "Failed to allocate read buffer\n");
    free(stream->wBuffer);
    fclose(stream->file);
    return;
  }

  while (fgets(stream->rBuffer, size, stream->file)) {
    printf("%s\n", stream->rBuffer);
  }

  fclose(stream->file);
  free(stream->rBuffer);
  return;
}

void create(streams *stream, int size) {
  if (stream == NULL) {
    fprintf(stderr, "Invalid stream Pointer\n");
  }

  printf("File>> ");
  stream->wBuffer = malloc(sizeof(char) * size);
  if (size == 0 || stream->wBuffer == 0) {
    fprintf(stderr, "Couldn't Allocate\n");
    return;
  }
  scanf("%s", stream->wBuffer);
  stream->file = fopen(stream->wBuffer, "w");
  fclose(stream->file);
  return;
}

void write(streams *stream, int size) {
  if (stream == NULL) {
    fprintf(stderr, "Couldn't access stream\n");
    return;
  }
  printf("File>> ");
  stream->wBuffer = malloc(sizeof(char) * size);
  scanf("%s", stream->wBuffer);
  stream->file = fopen(stream->wBuffer, "w");
  printf("Write>> ");
  scanf("%s", stream->wBuffer);
  fprintf(stream->file, "%s", stream->wBuffer);
  fclose(stream->file);
}

void incinerate(streams *stream, int size) {
  printf("File<< ");
  stream->wBuffer = malloc(sizeof(char) * size);
  if (stream == NULL || stream->wBuffer == NULL) {
    fprintf(stderr, "Couldn't access stream\n");
    return;
  }
  scanf("%s", stream->wBuffer);

  if (remove(stream->wBuffer) != 0) {
    fprintf(stderr, "Couldn't Remove File with name %s\n", stream->wBuffer);
    free(stream->wBuffer);
    return;
  }
  printf("Deleted File With Name %s\n", stream->wBuffer);
}
