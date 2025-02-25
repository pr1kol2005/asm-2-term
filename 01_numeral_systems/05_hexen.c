#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 0xffff

void print_result(const char *data, int last_digit) {
  static char buffer[MAX_SIZE] = {};
  static size_t i = 0;
  static int leading_zero = 1;

  if (last_digit != 0) {
    if (leading_zero != 0) {
      putchar('0');
    }
    fwrite(buffer, sizeof(char), i, stdout);
    return;
  }

  while (*data) {
    if (*data == '0' && leading_zero) {
      ++data;
      continue;
    }
    leading_zero = 0;

    if (i == MAX_SIZE) {
      fwrite(buffer, sizeof(char), i, stdout);
      i = 0;
    }

    buffer[i++] = *data++;
  }
}

void translate_and_print(char hex_digit) {
  static const char *binary_lookup[16] = {
      "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
      "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};

  if ('0' <= hex_digit && hex_digit <= '9') {
    print_result(binary_lookup[hex_digit - '0'], 0);
  } else if ('A' <= hex_digit && hex_digit <= 'F') {
    print_result(binary_lookup[hex_digit - 'A' + 10], 0);
  }
}

int main() {
  char *input = NULL;
  size_t input_size = 0;

  if (getline(&input, &input_size, stdin) == -1) {
    return EXIT_FAILURE;
  }

  for (size_t i = 0; input[i]; i++) {
    translate_and_print(input[i]);
  }

  print_result(NULL, 1);
  putchar('\n');

  free(input);
  return EXIT_SUCCESS;
}
