#include <stdio.h>
#include <stdlib.h>

int infect(unsigned char* infection_map, size_t index) {
  int was_infected = 0;
  was_infected = (infection_map[index / 8] >> (index % 8)) & 1;
  infection_map[index / 8] |= 1 << (index % 8);
  return (1 - was_infected);
}

int main() {
  int v = 0;
  int n = 0;
  scanf("%d %d", &v, &n);
  int infected_nanobots[100];
  for (int i = 0; i < v; i++) {
    scanf("%d", &infected_nanobots[i]);
  }

  int infected_count = 0;
  unsigned char* infection_map;
  if ((infection_map = calloc((n + 7) / 8, 1)) == NULL) {
    return EXIT_FAILURE;
  };

  for (int i = 0; i < v; ++i) {
    for (int j = infected_nanobots[i], k = 0; j < n;
         j += infected_nanobots[i] + k, ++k) {
      infected_count += infect(infection_map, j);
    }
  }

  printf("%d\n", infected_count);

  free(infection_map);

  return EXIT_SUCCESS;
}
