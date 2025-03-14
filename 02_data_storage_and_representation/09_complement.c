#include <stdio.h>
#include <stdlib.h>

int main() {
  char A = 0;
  scanf("%hhd", &A);

  unsigned char unsigned_A = (unsigned char)A;

  char binary_str[8] = {};
  for (size_t i = 0; i < 8; ++i) {
    binary_str[i] = unsigned_A % 2 + '0';
    unsigned_A /= 2;
  }

  for (size_t i = 8; i > 0; --i) {
    printf("%c", binary_str[i - 1]);
  }
  printf("\n");

  return EXIT_SUCCESS;
}
