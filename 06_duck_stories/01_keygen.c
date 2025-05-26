#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  uint32_t key = 0;
  scanf("%u", &key);
  printf("%u", key - 100501);

  return EXIT_SUCCESS;
}
