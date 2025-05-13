#include "../include/Basic/buffer.h"
#include "../include/Basic/stream.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READSIZE 1000

void clear() {
#ifdef _WIN32
  system("cls");
#elif __linux__
  system("clear");
  return;
#elif __APPLE__ && __MACH__
  system("clear");
  return;
#elif __unix__
  system("clear");
  return;
#else
  fprintf(stderr, "Couldn't Find Clear for OS So Trying Linux Version\n");
  system("clear");
  return;
#endif
  return;
}

void enlargeBuffer(char *buffer) {
  printf("Alloc<< ");
  int a;
  scanf("%d", &a);
  if (a == 0) {
    fprintf(stderr, "\nFailed To ReAllocate");
    return;
  }
  realloc(buffer, a);
  if (buffer == NULL) {
    fprintf(stderr, "\nERROR BUFFER REALLOC FAILED\n");
    exit(-12);
  }
  return;
}

void echo() {
  printf("echo>> ");
  char *response = malloc(sizeof(char) * 20);
  if (response == NULL) {
    fprintf(stderr, "Failure to Allocate\n");
  }
  scanf("%s", response);
  printf("\nInputted: %s\n", response);
  free(response);
}

void loop(char *buffer) {
  bool status = true;
  do {
    if (!status) {
      goto done;
    }
    printf("Good>> ");
    scanf("%s", buffer);
    if (strcmp(buffer, "!q") == 0) {
      status = false;
    } else if (strcmp(buffer, "!speckles") == 0) {
      streams *stream = malloc(sizeof(streams));
      printf("DEBUG: Starting up stream...\n");
      if (stream == NULL) {
        fprintf(stderr, "Couldn't Allocate Memory for Streams\n");
      } else {
        printf("Allocation Success!\n");
      }
      read(stream, READSIZE);
      free(stream);
      stream = NULL;
      if (NULL != stream) {
        exit(-6);
      }
      continue;
    } else if (strcmp(buffer, "!fest") == 0) {
      streams *stream = malloc(sizeof(streams));
      printf("DEBUG: Starting up stream\n");
      if (stream == NULL) {
        fprintf(stderr, "Couldn't Allocate Memory for Streams\n");
      } else {
        printf("Succesful Allocation!\n");
      }
      create(stream, READSIZE);
      free(stream);
      stream = NULL;
      if (NULL != stream) {
        exit(-9);
      }
    } else if (strcmp(buffer, "!pen") == 0) {
      streams *stream = malloc(sizeof(streams));
      printf("DEBUG: Starting up stream\n");
      if (stream == NULL) {
        fprintf(stderr, "Couldn't Allocate Memory for streams\n");
      } else {
        printf("Succesful Allocation\n");
      }
      write(stream, READSIZE);
      free(stream);
      stream = NULL;
      if (NULL != stream) {
        exit(-10);
      }
    } else if (strcmp(buffer, "!yell") == 0) {
      echo();
    } else if (strcmp(buffer, "!enlarge") == 0) {
      enlargeBuffer(buffer);
    } else if (strcmp(buffer, "!wipe") == 0) {
      clear();
    } else if (strcmp(buffer, "!fire") == 0) {
      streams *stream = malloc(sizeof(streams));
      printf("DEBUG: Starting up stream\n");
      if (stream == NULL) {
        fprintf(stderr, "Couldn't Allocate Memory for streams\n");
      } else {
        printf("Succesful Allocation\n");
      }
      incinerate(stream, READSIZE);
      free(stream);
      stream = NULL;
      if (NULL != stream) {
        exit(-11);
      }
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
