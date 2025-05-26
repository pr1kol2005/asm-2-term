#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  long long key = 0;
  scanf("%lld", &key);
  printf("%lld\n", 7530ll - key);
  return EXIT_SUCCESS;
}