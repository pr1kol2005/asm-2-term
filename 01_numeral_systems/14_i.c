#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

size_t min(size_t a, size_t b) {
  return (a < b) ? a : b; 
}

int main() {
  char *input_str = 0;
  size_t n = 0;
  if (getline(&input_str, &n, stdin) == -1) {
    free(input_str);
    return EXIT_FAILURE;
  }

  size_t occurences_count[256] = {};
  for (size_t i = 0; input_str[i]; i++){
    occurences_count[toupper(input_str[i])]++;
  }

  unsigned char roman_digits[] = "MDCLXVI";
  occurences_count['M'] = min(occurences_count['M'], 3);
  occurences_count['D'] = min(occurences_count['D'], 1);
  occurences_count['C'] = min(occurences_count['C'], 3);
  occurences_count['L'] = min(occurences_count['L'], 1);
  occurences_count['X'] = min(occurences_count['X'], 3);
  occurences_count['V'] = min(occurences_count['V'], 1);
  occurences_count['I'] = min(occurences_count['I'], 3);

  for (size_t i = 0; i < 7; i++)
    while (occurences_count[roman_digits[i]]) {
      occurences_count[roman_digits[i]]--;
      printf("%c", roman_digits[i]);
    }
  printf("\n");

  free(input_str);

  return EXIT_SUCCESS;
}
