#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int ull;

int StrToUll(const unsigned char* str, ull base, ull* result) {
  *result = 0;
  unsigned char* temp_str = (unsigned char*)str;
  int values[256] = {};

  for (size_t i = 0; i < 256; i++) {
    values[i] = -1;
  }

  for (unsigned char i = '0'; i <= '9'; i++) {
    unsigned char val = i - '0';
    values[i] = (val < base) ? val : -1;
  }

  for (unsigned char i = 'a'; i <= 'z'; i++) {
    unsigned char val = i - 'a' + 10;
    values[i] = (val < base) ? val : -1;
  }

  for (unsigned char i = 'A'; i <= 'Z'; i++) {
    unsigned char val = i - 'A' + 10;
    values[i] = (val < base) ? val : -1;
  }

  for (; *temp_str; temp_str++) {
    if (*temp_str == ' ' || *temp_str == '\n' || *temp_str == '\t') {
      continue;
    }
    if (values[*temp_str] < 0) {
      return *result = 0;
    }

    *result = *result * base + values[*temp_str];
  }

  return 1;
}

int Check(const unsigned char* X, unsigned char operator, const unsigned char* Y, const unsigned char* Z,
          ull base) {
  ull x = 0;
  ull y = 0;
  ull z = 0;

  if ((StrToUll(X, base, &x) && StrToUll(Y, base, &y) &&
       StrToUll(Z, base, &z)) == 0) {
    return 0;
  }

  if (operator== '+' && x + y != z) {
    return 0;
  }
  if (operator== '*' && x * y != z) {
    return 0;
  }

  return 1;
}

int main() {
  size_t N = 0;
  scanf("%zu\n", &N);

  unsigned char X[1000][100] = {};
  unsigned char operator[1000] = {};
  unsigned char Y[1000][100] = {};
  unsigned char Z[1000][100] = {};

  for (size_t i = 0; i < N; i++) {
    scanf(" %[0-9a-zA-Z] %c %[0-9a-zA-Z] %*c %[0-9a-zA-Z]", X[i], &operator[i],
          Y[i], Z[i]);
  }

  int answer = 0;
  for (size_t base = 1; base <= 1000; base++) {
    int flag = 1;
    for (size_t i = 0; flag && i < N; i++) {
      if (Check(X[i], operator[i], Y[i], Z[i], base) == 0) {
        flag = 0;
      }
    }

    if (flag) {
      if (answer) {
        printf("-1\n");
        return 0;
      } else {
        answer = base;
      }
    }
  }

  printf("%d\n", answer);

  return EXIT_SUCCESS;
}
