#include "../include/Misc/misc.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_TIME 60

void shutdown(int readSize) {
  printf("System>> ");
  char *commandBuffer = malloc(sizeof(char) * readSize);
  int sleep_time;
  scanf("%d", &sleep_time);

  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;

  if (sleep_time > MAX_TIME || sleep_time < 0) {
    fprintf(stderr, "Invalid Sleep Time");
    free(commandBuffer);
    return;
  }

#ifdef _WIN32
  printf("\nFounded Type: Windows\n");
  snprintf(commandBuffer, readSize, "shutdown /s /t %d", sleep_time);
  system(commandBuffer);
  free(commandBuffer);
#elif __linux__
  printf("\nFounded Type: Linux\n");
  snprintf(commandBuffer, readSize, "shutdown -h +%d", sleep_time);
  system(commandBuffer);
  free(commandBuffer);
  return;
#elif __APPLE__ && __MACH__
  printf("\nFounded Type: MacOS\n");
  snprintf(commandBuffer, readSize, "shutdown -h +%d", sleep_time);
  system(commandBuffer);
  free(commandBuffer);
  return;
#elif __unix__
  printf("\nFounded Type: Unix(Could be FreeBSD??)\n");
  snprintf(commandBuffer, readSize, "shutdown -h +%d", sleep_time);
  system(commandBuffer);
  free(commandBuffer);
  return;
#else
  fprintf(stderr, "Couldn't find shutdown command for this OS\n");
  free(commandBuffer);
  return;
#endif
  return;
}

void fetch() {
#ifdef _WIN32
  printf("\nFounded Type: Windows\n");
  system("neofetch");
  return;
#elif __linux__
  printf("\nFounded Type: Linux\n");
  system("neofetch");
  return;
#elif __APPLE__ && __MACH__
  printf("\nFounded Type: MacOS\n");
  system("neofetch");
  return;
#elif __unix__
  printf("\nFounded Type: Unix(Could be FreeBSD??)\n");
  system("neofetch");
  return;
#else
  fprintf(stderr, "Couldn't Find OS Type\n");
  system("neofetch");
  return;
#endif
}
