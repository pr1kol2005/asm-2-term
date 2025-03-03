#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int a = strtol(argv[1], NULL, 16);

  if (a & 1) {
    printf("ma\n");
  } else {
    printf("fe\n");
  }

  return EXIT_SUCCESS;
}
