#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define ecnode(num, b, c, d)                                    \
  (((uint32_t)num) | ((uint32_t)b << 8) | ((uint32_t)c << 16) | \
   ((uint32_t)d << 24))

int main() {
  uint32_t num = 0;
  scanf("%u", &num);

  num ^= ecnode('G', 'e', 'n', 'u');
  num ^= ecnode('i', 'n', 'e', 'I');
  num ^= ecnode('n', 't', 'e', 'l');
  num ^= ecnode('A', 'u', 't', 'h');
  num ^= ecnode('e', 'n', 't', 'i');
  num ^= ecnode('c', 'A', 'M', 'D');

  printf("%u\n", num);

  return EXIT_SUCCESS;
}
