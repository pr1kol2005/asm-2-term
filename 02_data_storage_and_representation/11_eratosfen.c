#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 200000000 / 8

typedef unsigned long long ull;
typedef unsigned char byte;

byte sieve_of_eratosthenes[MAX_SIZE] = {};

int GetBit(size_t index) {
  index -= 1;
  size_t offset = index % 8;
  index /= 8;
  return sieve_of_eratosthenes[index] & (1 << offset);
}

void SetBit(size_t index, int value) {
  index -= 1;
  size_t offset = index % 8;
  index /= 8;
  sieve_of_eratosthenes[index] &= ((byte)-1 ^ (1 << offset));
  sieve_of_eratosthenes[index] |= (value << offset);
}

int main() {
  memset(sieve_of_eratosthenes, -1, MAX_SIZE);

  SetBit(1, 0);

  size_t X = 0;
  scanf("%lu", &X);

  for (size_t p = 2; p * p <= X + 10; p++) {
    if (!GetBit(p)) {
      continue;
    }

    for (size_t i = p * p; i <= X; i += p) {
      SetBit(i, 0);
    }
  }

  size_t result = 0;
  for (size_t i = 1; i <= X; i++) {
    if (GetBit(i)) {
      ++result;
    }
  }

  printf("%lu\n", result);
}
