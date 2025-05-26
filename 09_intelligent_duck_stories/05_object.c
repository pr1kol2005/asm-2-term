#include <stdio.h>
#include <stdlib.h>

int main() {
  fseek(stdin, 0, SEEK_END);
  size_t input_size = ftell(stdin);
  fseek(stdin, 0, SEEK_SET);

  unsigned char *buffer = calloc(input_size, sizeof(unsigned char));
  if (buffer == NULL) {
    return EXIT_FAILURE;
  }

  fread(buffer, 1, input_size, stdin);

  for (size_t i = 0; i + 5 < input_size; i++) {
    if (buffer[i] == 0x08) {
      buffer[i + 2] = 0xeb;
      buffer[i + 3] = 0x90;
      buffer[i + 4] = 0xde;
      buffer[i + 5] = 0xc9;
      break;
    }
  }

  fwrite(buffer, 1, input_size, stdout);

  free(buffer);

  return EXIT_SUCCESS;
}
