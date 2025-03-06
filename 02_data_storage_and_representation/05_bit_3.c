#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *input = fopen("bit_3.dat", "r");
  if (input == NULL) {
    return EXIT_FAILURE;
  }

  int raw_code = 0;
  fscanf(input, "%x", &raw_code);

  fclose(input);

  FILE *output = fopen("bit_3.ans", "w");
  if (output == NULL) {
    return EXIT_FAILURE;
  }

  int code = (raw_code >> 4) & 0b11;
  if (code == 0b00) {
    fprintf(output, "bn\n");
  } else if (code == 0b01) {
    fprintf(output, "rd\n");
  } else if (code == 0b10) {
    fprintf(output, "bw\n");
  } else if (code == 0b11) {
    fprintf(output, "bk\n");
  }

  if (fclose(output) != 0) {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
