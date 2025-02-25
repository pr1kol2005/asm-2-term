#include <stdio.h>
#include <stdlib.h>

void reverse(char *a) {
  size_t i = 0;
  while (a[i] != '\0') {
    ++i;
  }
  --i;
  size_t j = 0;
  while (j < i) {
    char temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    --i;
    ++j;
  }
}

int main() {
  char a[1000] = {};
  char b[1000] = {};

  scanf("%s", a);
  scanf("%s", b);

  reverse(a);
  reverse(b);

  for (size_t i = 0; a[i] || b[i]; ++i) {
    if (a[i] == '\0') {
      a[i] = '0';
    } else if (b[i] == '\0') {
      b[i] = '0';
    }
  }

  char c = 0;
  size_t i = 0;

  while (a[i] != '\0') {
    char temp = (a[i] - '0' + b[i] - '0' + c) / 2;
    a[i] = (a[i] - '0' + b[i] - '0' + c) % 2 + '0';
    c = temp;
    ++i;
  }

  if (c != '\0') {
    a[i++] = c + '0';
  }

  while (i > 1 && a[i - 1] == '0') {
    --i;
  }

  while (i) {
    printf("%c", a[--i]);
  }
  printf("\n");

  return EXIT_SUCCESS;
}
