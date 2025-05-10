#include "../include/Basic/buffer.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 4096

int main() {
  char *buffer = (char *)malloc(BUFFERSIZE);
  if (buffer == NULL) {
    fprintf(stderr, "Couldn't Allocate Memory\n");
    return -1;
  }
  loop(buffer);
  return 0;
}
