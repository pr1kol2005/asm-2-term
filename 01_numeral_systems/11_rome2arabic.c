#include <stdio.h>
#include <stdlib.h>

int main() {
  int roman_to_arabic[256] = {};
  roman_to_arabic['M'] = 1000;
  roman_to_arabic['D'] = 500;
  roman_to_arabic['C'] = 100;
  roman_to_arabic['L'] = 50;
  roman_to_arabic['X'] = 10;
  roman_to_arabic['V'] = 5;
  roman_to_arabic['I'] = 1;

  char input_string[100] = "";
  scanf("%s", input_string);

  int result = 0;
  int prev = roman_to_arabic[(int)input_string[0]];
  for (size_t i = 1; input_string[i]; i++) {
    if (roman_to_arabic[input_string[i]] <= prev)
      result += prev;
    else
      result -= prev;
    prev = roman_to_arabic[input_string[i]];
  }
  result += prev;

  printf("%d\n", result);

  return EXIT_SUCCESS;
}
