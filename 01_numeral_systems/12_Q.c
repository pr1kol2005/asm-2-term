#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

int main() {
  int x = 0;
  scanf("%d", &x);

  int x_cube = x * x * x;

  for (ll i = x_cube - 1; i >= x * x; --i) {
    if (i * i % x_cube == i) {
      printf("%lld\n", i);
      return EXIT_SUCCESS;
    }
  }

  printf("-1\n");
  return EXIT_SUCCESS;
}
