#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main() {
  int64_t key = 0;
  scanf("%lld", &key);
  printf("%lld", key - 100501);

  return EXIT_SUCCESS;
}
