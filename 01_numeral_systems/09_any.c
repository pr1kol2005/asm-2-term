#include <stdio.h>
#include <stdlib.h>

void convert_and_print(int A, int k) {
  size_t pos = 0;
  char buffer[100];
  char all_digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  buffer[pos++] = all_digits[A % k];
  A /= k;
  while (A != 0) {
    buffer[pos++] = all_digits[A % k];
    A /= k;
  }

  while (pos != 0) {
    printf("%c", buffer[--pos]);
  }
  printf("\n");
}

int main() {
  int n = 0;
  scanf("%d", &n);

  char A_str[1000] = {};
  scanf("%s", A_str);

  int A = strtol(A_str, NULL, n);

  int k = 0;
  scanf("%d", &k);

  convert_and_print(A, k);

  return EXIT_SUCCESS;
}
