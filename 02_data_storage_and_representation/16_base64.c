#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

#define MAX_SIZE 100000

int main() {
  FILE* input_file = fopen("data", "rb");
  if (input_file == NULL) {
    return EXIT_FAILURE;
  }

  FILE* output_file = fopen("base64", "w");
  if (output_file == NULL) {
    fclose(input_file);
    return EXIT_FAILURE;
  }

  byte input_buffer[MAX_SIZE * 3] = {};
  size_t output_buffer[MAX_SIZE] = {};
  byte digits[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

  size_t read_count = 0;
  while ((read_count = fread(input_buffer, 3, MAX_SIZE, input_file))) {
    for (size_t i = 0; i < read_count; ++i) {
      size_t combined = (input_buffer[i * 3] << 16) | (input_buffer[i * 3 + 1] << 8) | input_buffer[i * 3 + 2];

      output_buffer[i] = digits[(combined >> 18) & 63];
      output_buffer[i] |= digits[(combined >> 12) & 63] << 8;
      output_buffer[i] |= digits[(combined >> 6) & 63] << 16;
      output_buffer[i] |= digits[combined & 63] << 24;
    }
    fwrite(output_buffer, 4, read_count, output_file);
  }

  fclose(input_file);
  fclose(output_file);

  return EXIT_SUCCESS;
}
