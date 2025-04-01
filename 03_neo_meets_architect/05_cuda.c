#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) { return (a < b) ? a : b; }

int main() {
  freopen("cuda.in", "r", stdin);
  freopen("cuda.out", "w", stdout);

  int tpb = 0;
  int rpt = 0;
  int mpb = 0;
  scanf("%d %d %d", &tpb, &rpt, &mpb);

  int utpb = tpb;
  tpb = (tpb + 31) / 32 * 32;
  rpt = (rpt + 1) / 2 * 2;
  mpb = (mpb + 127) / 128 * 128;

  int blocks = min(8, 1536 / tpb);
  blocks = min(blocks, 32768 / (tpb * rpt));
  if (mpb) blocks = min(blocks, 49152 / mpb);

  printf("%d\n", (blocks * utpb * 100 + 1536 / 2) / 1536);

  return EXIT_SUCCESS;
}
