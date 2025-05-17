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

int switchCommand(char *buffer) {
  if (buffer == NULL) {
    fprintf(stderr, "ERROR! Buffer is empty\n");
    return -99;
  }
  if (strcmp(buffer, "!q") == 0) {
    return 0;
  } else if (strcmp(buffer, "!speckles") == 0) {
    return 1;
  } else if (strcmp(buffer, "!fest") == 0) {
    return 2;
  } else if (strcmp(buffer, "!pen") == 0) {
    return 3;
  } else if (strcmp(buffer, "!yell") == 0) {
    return 4;
  } else if (strcmp(buffer, "!enlarge") == 0) {
    return 5;
  } else if (strcmp(buffer, "!wipe") == 0) {
    return 6;
  } else if (strcmp(buffer, "!fire") == 0) {
    return 7;
  } else if (strcmp(buffer, "neofetch") == 0) {
    return 8;
  } else if (strcmp(buffer, "!adios") == 0) {
    return 9;
  }
  return -22;
}

void loop(char *buffer) {
  bool status = true;
  streams *stream;
  do {
    if (!status) {
      goto done;
    }
    printf("Good>> ");
    scanf("%s", buffer);
    char *token = strtok(buffer, DELIMITER);
    switch (switchCommand(token)) {
    case 0:
      printf("\n Exiting Shell...");
      status = false;
      break;
    case 1:
      stream = malloc(sizeof(streams));
      if (stream == NULL) {
        fprintf(stderr, "\n Error Couldn't Allocate for Stream");
        return;
      }
      read(stream, READSIZE);
      free(stream);
      break;
    case 2:
      stream = malloc(sizeof(streams));
      if (stream == NULL) {
        fprintf(stderr, "\nCouldn't Allocate For Stream");
      }
      create(stream, READSIZE);
      free(stream);
      break;
    case 3:
      stream = malloc(sizeof(streams));
      if (stream == NULL) {
        fprintf(stderr, "\nCouldn't Allocate For Stream");
      }
      write(stream, READSIZE);
      free(stream);
      break;
    case 4:
      echo();
      break;
    case 5:
      enlargeBuffer(buffer);
      break;
    case 6:
      clear();
      break;
    case 7:
      stream = malloc(sizeof(streams));
      if (stream == NULL) {
        fprintf(stderr, "\n Couldn't Allocate For Stream");
      }
      incinerate(stream, READSIZE);
      free(stream);
      break;
    case 8:
      fetch();
      break;
    case 9:
      shutdown(READSIZE);
      break;
    default:
      printf("\nUnknown Command %s\n", token);
    }
    token = strtok(NULL, DELIMITER);
    while (token != NULL) {
      printf("\nIgnoring Arguments %s\n", token);
      token = strtok(NULL, DELIMITER);
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
