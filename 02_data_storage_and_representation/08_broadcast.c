#include <stdio.h>
#include <stdlib.h>

int main() {
  char ip_address[4] = {};
  char network_mask[4] = {};

  scanf("%hhu.%hhu.%hhu.%hhu", &ip_address[0], &ip_address[1], &ip_address[2],
        &ip_address[3]);
  scanf("%hhu.%hhu.%hhu.%hhu", &network_mask[0], &network_mask[1],
        &network_mask[2], &network_mask[3]);

  char broadcast_ip[4] = {};
  for (size_t i = 0; i < 4; ++i) {
    broadcast_ip[i] = (~network_mask[i]) | (ip_address[i] & network_mask[i]);
  }

  printf("%hhu.%hhu.%hhu.%hhu\n", broadcast_ip[0], broadcast_ip[1], broadcast_ip[2],
         broadcast_ip[3]);

  return EXIT_SUCCESS;
}
