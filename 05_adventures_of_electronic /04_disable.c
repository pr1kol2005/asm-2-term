#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *source = fopen("source", "rb");
  FILE *cracked = fopen("cracked", "wb");

  unsigned int buffer[100000] = {};

  fseek(source, 0, SEEK_END);
  int elem_count = ftell(source) / sizeof(unsigned int);
  fseek(source, 0, SEEK_SET);

  fread(buffer, sizeof(unsigned int), elem_count, source);

  for (size_t i = 1; i < elem_count - 1; i++) {
    if (buffer[i - 1] == 0xe353000d && buffer[i] == 0x1a000001 &&
        buffer[i + 1] == 0xe3a03007) {
      buffer[i] = 0x0a000001;
      break;
    }
  }

  fwrite(buffer, sizeof(unsigned int), elem_count, cracked);

  fclose(source);
  fclose(cracked);

  return EXIT_SUCCESS;
}

