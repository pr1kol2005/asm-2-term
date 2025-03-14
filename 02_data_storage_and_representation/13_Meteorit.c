#include <stdint.h>
#include <stdio.h>

union data {
  uint64_t u64;
  uint8_t arr[8];
  uint32_t a32[2];
};

union data convert(union data x) {
  union data result;
  for (size_t i = 0; i < 8; ++i) {
    result.arr[i] = x.arr[7 - i];
  }
  return result;
}

void prbin(unsigned char a) {
  for (size_t i = 8; i > 0; i--) {
    printf("%d", (a >> (i - 1)) & 1);
    if (i % 4 == 1) printf(" ");
  }
}

int main() {
  union data a;
  a.u64 = 123l;

  for (size_t i = 8; i > 0; i--) prbin(a.arr[i - 1]);
  printf("\n");

  a = convert(a);

  for (size_t i = 8; i > 0; i--) prbin(a.arr[i - 1]);
  printf("\n");
}
