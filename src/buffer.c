#include "../include/Basic/buffer.h"
#include "../include/Basic/stream.h"
#include "../include/Misc/misc.h"
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
  int realloc_size;
  scanf("%d", &realloc_size);
  if (realloc_size <= 0 || realloc_size >= 32) {
    fprintf(stderr, "Allocation Failed!!");
    return;
  }
  buffer = realloc(buffer, realloc_size * 4096);
  if (buffer == NULL) {
    fprintf(stderr, "\nERROR BUFFER REALLOC FAILED\n");
    exit(-12);
  }
  return;
}

#define DELIMITER "__"
void echo() {
  printf("Echo>> ");
  char *input = malloc(sizeof(char) * 100);
  if (input == NULL) {
    fprintf(stderr, "Failed to allocate memory for echo\n");
    return;
  }

  scanf("%s", input);

  char *token = strtok(input, DELIMITER);

  while (token != NULL) {
    printf("%s ", token);
    token = strtok(NULL, DELIMITER);
  }
  printf("\n");

  free(input);
}

void loop(char *buffer) {
  bool status = true;
  do {
    if (!status) {
      goto done;
    }
    printf("Good>> ");
    scanf("%s", buffer);
    char *token = strtok(buffer, DELIMITER);

    if (token != NULL) {
      if (strcmp(token, "!q") == 0) {
        status = false;
      } else if (strcmp(token, "!speckles") == 0) {
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
      } else if (strcmp(token, "!fest") == 0) {
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
      } else if (strcmp(token, "!pen") == 0) {
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
      } else if (strcmp(token, "!yell") == 0) {
        echo();
      } else if (strcmp(token, "!enlarge") == 0) {
        enlargeBuffer(buffer);
      } else if (strcmp(token, "!wipe") == 0) {
        clear();
      } else if (strcmp(token, "!fire") == 0) {
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
      } else if (strcmp(token, "neofetch")) {
        fetch();
      } else {
        fprintf(stderr, "Unknown Command: %s\n", token);
      }

      token = strtok(NULL, DELIMITER);
      while (token != NULL) {
        fprintf(stderr, "Ignoring extra argument: %s\n", token);
        token = strtok(NULL, DELIMITER);
      }
    }
  } while (status);

done:
  free(buffer);
  buffer = NULL;
  if (buffer != NULL) {
    fprintf(stderr, "Uh Oh, Couldn't Free Buffer\n");
    exit(-2);
  } else {
    printf("Buffer has been Successfully Freed\n");
    exit(0);
  }
}
