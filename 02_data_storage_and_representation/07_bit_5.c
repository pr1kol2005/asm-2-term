#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *line = "";

  size_t tmp = 0;
  getline(&line, &tmp, stdin);

  int code = 0;
  char* tokens = strtok(line, " \t\n");

  while (tokens) {
    if (strcmp(tokens, "ma") == 0) {
      code |= 1;
    } else if (strcmp(tokens, "cl") == 0) {
      code |= 2;
    } else if (strcmp(tokens, "ha") == 0) {
      code |= 4;
    } else if (strcmp(tokens, "tr") == 0) {
      code |= 8;
    } else if (strcmp(tokens, "rd") == 0) {
      code |= 0b01 << 4;
    } else if (strcmp(tokens, "bw") == 0) {
      code |= 0b10 << 4;
    } else if (strcmp(tokens, "bk") == 0) {
      code |= 0b11 << 4;
    } else if (strcmp(tokens, "ge") == 0) {
      code |= 0b01 << 6;
    } else if (strcmp(tokens, "gy") == 0) {
      code |= 0b10 << 6;
    } else if (strcmp(tokens, "da") == 0) {
      code |= 0b11 << 6;
    }

    tokens = strtok(NULL, " \t\n");
  }

  printf("%x\n", code);

  free(line);

  return EXIT_SUCCESS;
}
