#include <stdio.h>
#include <stdlib.h>

typedef long double ld;

ld AddUpNumbers(ld lhs, ld rhs, ld *loss) {
  ld sum = lhs + rhs;
  *loss = rhs - (sum - lhs);
  return sum;
}

int main() {
  ld sum = 0;
  ld error = 0;
  ld next_one = 0;
  ld accumulated_error = 0;

  while (scanf("%Lf", &next_one) != EOF) {
    sum = AddUpNumbers(sum, next_one, &error);
    accumulated_error += error;
  }

  printf("%.20Lf", sum + accumulated_error);

  return EXIT_SUCCESS;
}
