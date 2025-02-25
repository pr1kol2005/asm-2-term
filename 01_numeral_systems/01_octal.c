#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *input = fopen("input.txt", "r");
  if (input == NULL) {
    return EXIT_FAILURE;
  }

  long long int x = 0;
  fscanf(input, "%lld", &x);

  fclose(input);

  int octal[100] = {};
  size_t i = 0;

  while (x) {
    octal[i++] = x % 8;
    x /= 8;
  }

  FILE *output = fopen("output.txt", "w");
  if (output == NULL) {
    return 3;
  }

  while (i) {
    fprintf(output, "%d", octal[--i]);
  }
  fprintf(output, "\n");

  fclose(output);

  return EXIT_SUCCESS;
}
