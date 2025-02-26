#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *dig;  // массив для хранения числа:
              // a[0] * 100^0 + a[1] * 100^1 + .. + a[n - 1] * 100^(n-1)
  int n;      // размер числа в разрядах
  char sign;  // знак числа
} LongN;

LongN getLongN(char *s) {
  LongN result = {};
  result.dig = (char *)malloc(110 * sizeof(char));

  if (result.dig == NULL) {
    exit(EXIT_FAILURE);
  }

  result.sign = 0;
  if (s[0] == '-') {
    result.sign = 1;
  }

  int has_sign = 0;
  if (!isdigit(s[0])) {
    ++has_sign;
  }

  int length = has_sign;
  while (isdigit(s[length])) {
    ++length;
  }
  --length;

  int current = 0;
  for (; current <= length - has_sign; current++) {
    result.dig[current / 2] +=
        (s[length - current] - '0') * ((current % 2) ? 10 : 1);
  }

  --current;
  result.n = current / 2 + 1;

  int not_zero = 0;
  for (int i = 0; i < result.n; i++) {
    not_zero |= result.dig[i];
  }

  if (!not_zero) {
    result.n = 1;
    result.sign = 0;
  }

  return result;
}

int main() {
  char s[1000] = {};

  scanf("%s", s);

  LongN result = getLongN(s);

  printf("%d %d\n", result.n, result.sign);
  for (int i = 0; i < result.n; i++) {
    printf("%d ", result.dig[i]);
  }
  printf("\n");
}
