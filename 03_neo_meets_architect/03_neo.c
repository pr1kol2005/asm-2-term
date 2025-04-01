#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX_LENGTH 256

typedef struct {
    char name_of_anomaly[NAME_MAX_LENGTH];
    int number_of_anomaly;
} anomaly;

char* whatisyourname() {
  char* result = malloc(256 * sizeof(char) + sizeof(int));
  for (int i = 0; i < 256; ++i) {
    result[i] = 1;
  }
  result[256] = 0;
  return result;
}
