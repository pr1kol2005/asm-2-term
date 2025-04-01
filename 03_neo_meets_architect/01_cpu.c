#include <stdio.h>
#include <stdlib.h>

#ifndef REGISTERS_COUNT
#define REGISTERS_COUNT 4
#endif

typedef unsigned char byte;

int add(byte *registers) {
  int r1 = 0;
  int r2 = 0;
  scanf("%d %d", &r1, &r2);
  r1 -= 5;
  r2 -= 5;

  if (r1 >= REGISTERS_COUNT || r2 >= REGISTERS_COUNT) {
    return EXIT_FAILURE;
  }

  registers[r1] += registers[r2];
  return EXIT_SUCCESS;
}

int sub(byte *registers) {
  int r1 = 0;
  int r2 = 0;
  scanf("%d %d", &r1, &r2);
  r1 -= 5;
  r2 -= 5;

  if (r1 >= REGISTERS_COUNT || r2 >= REGISTERS_COUNT) {
    return EXIT_FAILURE;
  }

  registers[r1] -= registers[r2];
  return EXIT_SUCCESS;
}

int mov(byte *registers) {
  int r1 = 0, n = 0;
  scanf("%d %d", &r1, &n);
  r1 -= 5;

  if (r1 >= REGISTERS_COUNT)
    return EXIT_FAILURE;

  registers[r1] = n;
  return EXIT_SUCCESS;
}

int ir(byte *registers) {
  for (int i = 0; i < REGISTERS_COUNT; ++i) {
    printf("%d ", registers[i]);
  }
  printf("\n");
  return EXIT_SUCCESS;
}

int main() {
  byte registers[REGISTERS_COUNT] = {};

  int instruction_code = 0;
  int exit_code = EXIT_SUCCESS;

  while (1) {
    scanf("%d", &instruction_code);
    if (instruction_code == 0 || exit_code == EXIT_FAILURE) {
      break;
    }

    if (instruction_code == 1) {
      exit_code = add(registers);
    } else if (instruction_code == 2) {
      exit_code = sub(registers);
    } else if (instruction_code == 3) {
      exit_code = mov(registers);
    } else if (instruction_code == 4) {
      exit_code = ir(registers);
    }
  }

  if (exit_code == EXIT_FAILURE) {
    printf("-1\n");
  }

  return EXIT_SUCCESS;
}