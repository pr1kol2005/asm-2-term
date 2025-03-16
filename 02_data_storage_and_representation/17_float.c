#include <stdio.h>
#include <stdlib.h>

void parse_fractional_number(const char* input_line) {
  int whole_part = atoi(input_line);

  const char* end_of_whole_part = input_line;
  while (*end_of_whole_part && *end_of_whole_part != '.') {
    end_of_whole_part++;
  }

  int numerator = 0;
  int denominator = 1;

  if (*end_of_whole_part == '.') {
    end_of_whole_part++;
    numerator = atoi(end_of_whole_part);

    for (const char* ptr = end_of_whole_part; '0' <= *ptr && *ptr <= '9';
         ptr++) {
      denominator *= 10;
    }

    while (!(denominator % 2) && !(numerator % 2)) {
      numerator /= 2;
      denominator /= 2;
    }

    while (!(denominator % 5) && !(numerator % 5)) {
      numerator /= 5;
      denominator /= 5;
    }
  }

  printf("%d (%d/%d)\n", whole_part, numerator, denominator);
}

int main() {
  char* input_line = NULL;
  size_t input_line_size = 0;

  if (getline(&input_line, &input_line_size, stdin) == -1) {
    free(input_line);
    return EXIT_FAILURE;
  }

  parse_fractional_number(input_line);

  free(input_line);
  return EXIT_SUCCESS;
}