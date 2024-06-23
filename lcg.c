#include <stdlib.h>
//#include <string.h>
#include <stdio.h>

long * lcg (long seed, int quantity) {
  long * output = malloc(sizeof(long) * quantity);
  long m, a, c;

  for (long i = 13; i = i + 2;) {
    if (seed % i > 1229) {
      m = seed % i;
      printf("Modulous successfully created: %li\n", m);
      break;
    }
  }

  for (long i = 5; i = i + 7;) {
    if (seed % i < m && seed % i > 101 && seed % i > 1 && (seed % i) % m != 0) {
      a = seed % i;
      printf("Multiplier successfully created: %li\n", a);
      break;
    }
  }

  for (long i = 3; i = i + 19;) {
    if (seed % i < m && seed % i > 101 && (seed % i) % m != 0 && (seed % i) % a != 0) {
      c = seed % i;
      printf("Increment successfully created: %li\n", c);
      break;
    }
  }

  output[0] = ((a * seed) + c) % m;

  for (int i = 1; i < quantity; i++) {
    output[i] = ((a * output[i - 1]) + c) % m;
  }

  return output;
}

int main (int argc, char* argv[]) {
  long seed = 0;
  while (seed < 1000001) {
    printf("Please input a seed greater than 1 million.\n");
    scanf("%li", &seed);
  }
  printf("Seed: %li\n", seed);

  long * output = lcg(seed, 100);

  for (int i = 0; i < 100; i++) {
    printf("Number: %i is: %li\n", i, output[i]);
  }

  free(output);
  return 0;
}