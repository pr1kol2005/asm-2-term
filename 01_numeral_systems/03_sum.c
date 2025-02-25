#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  double x = 0;
  scanf("%lf", &x);

  char y[100] = {};
  scanf("%s", y);

  x += strtol(y, NULL, 16);
  x += strtol(argv[1], NULL, 27);

  printf("%.3f\n", x);

  return EXIT_SUCCESS;
}
