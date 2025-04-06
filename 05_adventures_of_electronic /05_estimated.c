#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *source = fopen("source", "rb");
  FILE *cracked = fopen("cracked", "wb");

  unsigned char buff[100000] = {};

  fseek(source, 0, SEEK_END);
  int elem_count = ftell(source);
  fseek(source, 0, SEEK_SET);

  fread(buff, sizeof(unsigned char), elem_count, source);

  for (long i = 1; i < elem_count - 3; i++) {
    if ((i + 1) % 4 == 0 && buff[i] == 0x00 && buff[i + 1] == 0xca &&
        buff[i + 2] == 0x9a && buff[i + 3] == 0x3b) {
      buff[i + 3] = 0x77;
      break;
    }
  }

  fwrite(buff, sizeof(unsigned char), elem_count, cracked);

  fclose(source);
  fclose(cracked);

  return EXIT_SUCCESS;
}
