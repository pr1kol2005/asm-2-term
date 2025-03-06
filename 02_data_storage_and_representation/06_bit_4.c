#include <stdio.h>
#include <stdlib.h>

void gender(int raw_code) {
  printf((raw_code & 1) ? "ma " : "fe ");
}

void intellegence(int raw_code) {
  printf((raw_code & 2) ? "cl " : "du ");
}

void hat(int raw_code) {
  printf((raw_code & 4) ? "ha " : "nh "); 
}

void pants(int raw_code) {
  printf((raw_code & 8) ? "tr " : "sk ");
}

void hair_color(int raw_code) {
  int b = (raw_code >> 4) & 0b11;
  if (b == 0b00) {
    printf("bn ");
  } else if (b == 0b01) {
    printf("rd ");
  } else if (b == 0b10) {
    printf("bw ");
  } else if (b == 0b11) {
    printf("bk ");
  }
}

void eye_color(int raw_code) {
  int b = (raw_code >> 6) & 0b11;
  if (b == 0b00) {
    printf("bu ");
  } else if (b == 0b01) {
    printf("ge ");
  } else if (b == 0b10) {
    printf("gy ");
  } else if (b == 0b11) {
    printf("da ");
  }
}

int main() {
  int raw_code = 0;
  scanf("%x", &raw_code);

  gender(raw_code);
  intellegence(raw_code);
  hat(raw_code);
  pants(raw_code);
  hair_color(raw_code);
  eye_color(raw_code);

  printf("\n");

  return EXIT_SUCCESS;
}
