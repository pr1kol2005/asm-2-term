#include <stdio.h>
#include <stdlib.h>

#ifndef REGISTERS_COUNT
#define REGISTERS_COUNT 4
#endif

typedef unsigned char byte;

int add(byte *registers, byte instruction_code, int *flag) {
  int r1 = 0;
  int r2 = 0;
  scanf("%d %d", &r1, &r2);
  r1 -= 5;
  r2 -= 5;

  if ((instruction_code >> 7) && !*flag) {
    return EXIT_SUCCESS;
  }

  if (r1 >= REGISTERS_COUNT || r2 >= REGISTERS_COUNT) {
    return EXIT_FAILURE;
  }

  registers[r1] += registers[r2];
  *flag = !registers[r1];

  return EXIT_SUCCESS;
}

int sub(byte *registers, byte instruction_code, int *flag) {
  int r1 = 0;
  int r2 = 0;
  scanf("%d %d", &r1, &r2);
  r1 -= 5;
  r2 -= 5;

  if ((instruction_code >> 7) && !*flag) {
    return EXIT_SUCCESS;
  }

  if (r1 >= REGISTERS_COUNT || r2 >= REGISTERS_COUNT) {
    return EXIT_FAILURE;
  }

  registers[r1] -= registers[r2];
  *flag = !registers[r1];

  return EXIT_SUCCESS;
}

int mov(byte *registers, byte instruction_code, int *flag) {
  int r1 = 0;
  int n = 0;
  scanf("%d %d", &r1, &n);
  r1 -= 5;

  if ((instruction_code >> 7) && !*flag) {
    return EXIT_SUCCESS;
  }

  if (r1 >= REGISTERS_COUNT) {
    return EXIT_FAILURE;
  }

  registers[r1] = n;
  *flag = !registers[r1];

  return EXIT_SUCCESS;
}

int ir(byte *registers, byte instruction_code, int *flag) {
  if ((instruction_code >> 7) && !*flag) {
    return EXIT_SUCCESS;
  }

  for (int i = 0; i < REGISTERS_COUNT; i++) {
    printf("%d ", registers[i]);
  }
  printf("\n");

  *flag = *flag;

  return EXIT_SUCCESS;
}

int main() {
  byte registers[REGISTERS_COUNT] = {};

  byte instruction_code = 0;
  int exit_code = EXIT_SUCCESS;
  int flag = 0;

  while (1) {
    scanf("%hhu", &instruction_code);
    instruction_code &= 0x7f;
    if (instruction_code == 0 || exit_code == EXIT_FAILURE) {
      break;
    }

    if (instruction_code == 1) {
      exit_code = add(registers, instruction_code, &flag);
    } else if (instruction_code == 2) {
      exit_code = sub(registers, instruction_code, &flag);
    } else if (instruction_code == 3) {
      exit_code = mov(registers, instruction_code, &flag);
    } else if (instruction_code == 4) {
      exit_code = ir(registers, instruction_code, &flag);
    } else {
      break;
    }
  }

  if (exit_code == EXIT_FAILURE) {
    printf("-1\n");
  }
}
