#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *input = fopen("source", "r");
  FILE *output = fopen("cracked", "w");

  if (input == NULL || output == NULL) {
    return EXIT_FAILURE;
  }

  int key = 0;
  while ((key = fgetc(input)) != EOF) {
    fputc(key, output);
  }

  fseek(output, 0x520, SEEK_SET);
  unsigned char magic = 0xe0;
  fwrite(&magic, 1, 1, output);

  fclose(input);
  fclose(output);

  return EXIT_SUCCESS;
}
