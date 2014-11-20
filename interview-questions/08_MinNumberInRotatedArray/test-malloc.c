#include <stdio.h>
#include <stdlib.h>

int main() {
  int** a = malloc(sizeof(int) * 2 * 2);
  a[1][1] = 2;
  printf("%d", a[0][0]);
}
