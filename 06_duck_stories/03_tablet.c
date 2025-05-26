#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *source = fopen("source", "rb");
  FILE *cracked = fopen("cracked", "wb");

  if (source == NULL || cracked == NULL) {
    return EXIT_FAILURE;
  }

  uint32_t buffer[100000] = {};

  fseek(source, 0, SEEK_END);

  int ptr = ftell(source) / sizeof(uint32_t);
  fseek(source, 0, SEEK_SET);

  fread(buffer, sizeof(uint32_t), ptr, source);

  for (int i = 1; i < ptr - 1; ++i) {
    if (buffer[i - 1] == 0x0b010000 && buffer[i] == 0x6b14001f) {
      buffer[i + 1] = 0xd503201f;
      break;
    }
  }

  fwrite(buffer, sizeof(uint32_t), ptr, cracked);

  fclose(source);
  fclose(cracked);

  return EXIT_SUCCESS;
}
