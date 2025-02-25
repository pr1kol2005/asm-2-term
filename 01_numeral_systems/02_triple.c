#include <stdio.h>
#include <stdlib.h>

int main() {
  // log_3(6 * 10^10) < 25
  char T[25] = {};
  scanf("%s", T);
  printf("%ld\n", strtol(T, NULL, 3));
  return EXIT_SUCCESS;
}
