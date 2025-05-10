#include "../include/Basic/buffer.h"
#include "../include/Basic/stream.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
void loop(char *buffer) {
  bool status = true;
  do {
    if (!status) {
      goto done;
    }
    printf("Good>> ");
    scanf_s("%s", buffer, (unsigned)_countof(buffer));
    if (strcmp(buffer, "!q") == 0) {
      status = false;
    } else if (strcmp(buffer, "!speckles")) {
      streams *stream;
      stream->writebuffer = malloc(sizeof(char) * 100);
      char *a = read(stream, 1000);
      printf("%s", a);
    } else {
      printf("Unknown Command: %s\n", buffer);
    }

  } while (status);

done:
  free(buffer);
  buffer = NULL;
  if (buffer != NULL) {
    fprintf(stderr, "Uh Oh, Couldn't Free Buffer\n");
    exit(-2);
  } else {
    printf("Buffer has been Succesfully Freed\n");
    exit(0);
  }
}
