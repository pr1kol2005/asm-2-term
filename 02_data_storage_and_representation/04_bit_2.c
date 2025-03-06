#include <stdio.h>
#include <stdlib.h>

int main() {
  char *input = getenv("CODE");

  int a = 0;
  sscanf(input, "%x", &a);
  if (a & 4) {
    printf("ha\n");
  } else {
    printf("nh\n");
  }

  return EXIT_SUCCESS;
}
