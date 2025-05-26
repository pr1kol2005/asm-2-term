#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *input = fopen("antideb", "rb");
  FILE *output = fopen("antideb_patched", "wb");

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

  for (size_t i = 0; i + 1 < input_size; ++i) {
    if (buffer[i] == 0x75 && buffer[i + 1] == 0x14) {
      buffer[i] = 0x74;
      break;
    }
  }

  fwrite(buffer, 1, input_size, output);

  free(buffer);

  fclose(input);
  fclose(output);

  return EXIT_SUCCESS;
}
