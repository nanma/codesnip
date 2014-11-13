#include <stdio.h>
struct {
  char a:7;
  char e:2;
} i;

int main() {
  int j;
  printf("size: %lu, %lu\n", sizeof(i), sizeof(j));
}
