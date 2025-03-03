#include <stdio.h>

void rwx(char c) {
  if (c == '0') {
    printf("---");
  } else if (c == '1') {
    printf("--x");
  } else if (c == '2') {
    printf("-w-");
  } else if (c == '3') {
    printf("-wx");
  } else if (c == '4') {
    printf("r--");
  } else if (c == '5') {
    printf("r-x");
  } else if (c == '6') {
    printf("rw-");
  } else if (c == '7') {
    printf("rwx");
  }
}

int main() {
  char s[10] = {};
  scanf("%s", s);

  rwx(s[0]);
  rwx(s[1]);
  rwx(s[2]);
}
