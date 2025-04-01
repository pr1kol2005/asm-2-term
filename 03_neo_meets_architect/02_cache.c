#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

uint ComputeGCD(uint a, uint b) {
  while (a) {
    uint temp = a;
    a = b % a;
    b = temp;
  }
  return b;
}

int ComputeResult(uint n, uint d) {
  uint extended_size = n + 2;
  uint total_size = extended_size * extended_size;

  uint *gcds = calloc(total_size, sizeof(uint));
  if (!gcds) {
    return EXIT_FAILURE;
  }

  for (size_t i = 0; i < extended_size; ++i) {
    for (size_t j = 0; j < extended_size; ++j) {
      gcds[i * extended_size + j] = ComputeGCD(i, j);
    }
  }

  uint *A = calloc(n * n, sizeof(uint));
  uint *B = calloc(n * n, sizeof(uint));
  if (!A || !B) {
    free(gcds);
    free(A);
    free(B);
    return EXIT_FAILURE;
  }

  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      A[i * n + j] = gcds[(i + 1) * extended_size + j + 1];
      B[i * n + j] = gcds[(n - i + 1) * extended_size + n - j + 1];
    }
  }

  int result = 0;
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      uint sum = 0;
      for (size_t k = 0; k < n; ++k) {
        sum += A[i * n + k] * B[j * n + k];
      }
      result += (sum % d == 0);
    }
  }

  free(gcds);
  free(A);
  free(B);

  return result;
}

int main() {
  uint n, d;
  if (scanf("%u %u", &n, &d) != 2) {
    return EXIT_FAILURE;
  }

  printf("%d\n", ComputeResult(n, d));
  return EXIT_SUCCESS;
}
