#include <stdio.h>

int triple_to_decimal(char a) {
  if (a == '1') {
    return 1;
  }
  if (a == '$') {
    return -1;
  }
  return 0;
}

char calculate_sum(unsigned char a, unsigned char b, char *carry) {
  int result =
      triple_to_decimal(a) + triple_to_decimal(b) + triple_to_decimal(*carry);

  if (result == -3) {
    *carry = '$';
    return '0';
  }
  if (result == -2) {
    *carry = '$';
    return '1';
  }
  if (result == -1) {
    *carry = '0';
    return '$';
  }
  if (result == 0) {
    *carry = '0';
    return '0';
  }
  if (result == 1) {
    *carry = '0';
    return '1';
  }
  if (result == 2) {
    *carry = '1';
    return '$';
  }
  if (result == 3) {
    *carry = '1';
    return '0';
  }
  return 0;
}

void reverse(char *a) {
  size_t i = 0;
  while (a[i] != '\0') {
    ++i;
  }
  --i;
  for (size_t j = 0; j < i; ++j, --i) {
    char temp = a[i];
    a[i] = a[j];
    a[j] = temp;
  }
}

int main() {
  char a[1000] = {};
  char b[1000] = {};
  char result[1000] = {};

  scanf("%s %s", a, b);

  reverse(a);
  reverse(b);

  char carry = '0';
  size_t i = 0;
  
  while (a[i] != '\0' || b[i] != '\0') {
    result[i] = calculate_sum(a[i], b[i], &carry);
    ++i;
  }
  result[i] = carry;

  while (i > 0 && result[i] == '0') {
    result[i] = '\0';
    --i;
  }

  reverse(result);

  printf("%s\n", result);
}