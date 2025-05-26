#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *input = fopen("source", "rb");
  FILE *output = fopen("cracked", "wb");

  if (input == NULL || output == NULL) {
    return EXIT_FAILURE;
  }

  fseek(input, 0, SEEK_END);
  size_t input_size = ftell(input);
  fseek(input, 0, SEEK_SET);

  unsigned char *buffer = calloc(input_size, sizeof(unsigned char));
  if (buffer == NULL) {
    return EXIT_FAILURE;
  }

  fread(buffer, 1, input_size, input);

  for (size_t i = 0; i + 2 < input_size; ++i) {
    if (buffer[i] == 0x00 && buffer[i + 1] == 0x75 && buffer[i + 2] == 0x11) {
      buffer[i + 1] = 0x90;
      buffer[i + 2] = 0x90;
      break;
    }
  }

  fwrite(buffer, 1, input_size, output);

  free(buffer);

  fclose(input);
  fclose(output);

  return EXIT_SUCCESS;
}
