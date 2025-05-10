#include "../include/Basic/buffer.h"
#include "../include/Basic/stream.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loop(char *buffer) {
  bool status = true;
  do {
    if (!status) {
      goto done;
    }
    printf("Good>> ");
    scanf_s("%s", buffer, (unsigned)_countof(buffer) * 8);
    if (strcmp(buffer, "!q") == 0) {
      status = false;
    } else if (strcmp(buffer, "!speckles") == 0) {
      streams *stream = malloc(sizeof(streams));
      if (stream == NULL) {
        fprintf(stderr, "Couldn't Allocate Memory for Streams\n");
        exit(-5);
      }
      read(stream, 1000);
      free(stream);
      stream = NULL;
      if (NULL != stream) {
        exit(-6);
      }
      continue;
    } else {
      fprintf(stderr, "Unknown Command: %s\n", buffer);
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
