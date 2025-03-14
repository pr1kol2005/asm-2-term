#include <stdio.h>
#include <float.h>
#include <stdlib.h>

int main() {
  char first_chararacter;
  scanf("%c", &first_chararacter);
  if (first_chararacter == 'f')
    printf("%d\n", FLT_MANT_DIG - 1);
  else if (first_chararacter == 'd')
    printf("%d\n", DBL_MANT_DIG - 1);
  else if (first_chararacter == 'l')
    printf("%d\n", LDBL_MANT_DIG - 1);
  else {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
