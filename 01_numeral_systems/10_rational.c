#include <stdio.h>
#include <stdlib.h>

int main() {
  char string[100] = {};
  scanf("%s", string);

  unsigned int exponent = 1;
  for (size_t i = 0; string[i] && string[i + 1]; ++i) {
    if (string[i] != '.') {
      continue;
    }
    string[i] = string[i + 1];
    string[i + 1] = '.';
    exponent <<= 1;
  }

  double result = strtoll(string, NULL, 2);
  result /= exponent;

  printf("%.12lf\n", result);

  return EXIT_SUCCESS;
}
