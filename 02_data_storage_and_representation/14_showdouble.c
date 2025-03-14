#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef unsigned char byte;

typedef union {
  char data[sizeof(long double)];
  long double ldb;
  double db;
  float fl;
} u;

void print_binary_representation(byte num) {
  for (size_t i = 8; i > 0; --i) {
    printf("%d", (num >> (i - 1)) & 1);
    if (i % 4 == 1) {
      printf(" ");
    }
  }
}

int main() {
  u u;
  if (memset(u.data, 0, sizeof(long double)) == NULL) {
    return EXIT_FAILURE;
  }

  char input_string[MAX_SIZE] = {};
  scanf("%s", input_string);
  size_t binary_length = 0;
  if (input_string[0] == 'f') {
    scanf("%f", &u.fl);
    binary_length = sizeof(float);
  } else if (input_string[0] == 'd') {
    scanf("%lf", &u.db);
    binary_length = sizeof(double);
  } else if (input_string[0] == 'l') {
    scanf("%*s");
    scanf("%Lf", &u.ldb);
    binary_length = sizeof(long double);
  }

  for (size_t i = binary_length; i > 0; --i) {
    print_binary_representation(u.data[i - 1]);
  }
  printf("\n");

  return EXIT_SUCCESS;
}
