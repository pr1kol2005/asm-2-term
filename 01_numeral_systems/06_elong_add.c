#include <stdio.h>

#define N 100

struct _Decimal {
  char a[N];       // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
  unsigned int n;  // наибольшая степень десяти
};

typedef struct _Decimal Decimal;

Decimal add(Decimal a, Decimal b) {
  char tmp = 0;

  Decimal result = {};
  for (size_t i = 0; i < N; i++) {
    result.a[i] = 0;
  }
  result.n = 0;

  for (size_t i = 0; i < N; i++) {
    if (i > a.n) {
      a.a[i] = 0;
    }

    if (i > b.n) {
      b.a[i] = 0;
    }

    result.a[i] = (a.a[i] + b.a[i] + tmp) % 10;
    tmp = (a.a[i] + b.a[i] + tmp) / 10;
  }

  unsigned int new_n = N - 1;
  while (new_n > 0 && result.a[new_n] == 0) {
    --new_n;
  }

  result.n = new_n;
  return result;
}

int main() {
  // Decimal a = {{0, 9, 8, 7, 6, 5, 4, 3, 2, 1}, 9}; // set number 147
  // Decimal b = {{5, 2, 3}, 2};
  Decimal a, b;

  a.n = 9;
  a.a[0] = 0;
  for (int i = 1; i < 10; i++) a.a[i] = 10 - i;

  b.n = 2;
  b.a[0] = 5;
  b.a[1] = 2;
  b.a[2] = 3;

  Decimal result;

  result = add(a, b);  // result = a+b = 147+13 = 160

  printf("%d\n", result.n);
  for (size_t i = 0; i < N; i++) printf("%d ", result.a[i]);
  printf("\n\n");

  return 0;
}
