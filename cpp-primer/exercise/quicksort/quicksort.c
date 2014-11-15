#include "stdio.h"

void quicksort(int A[], int n) {
  if (A == NULL || n <= 1) {
    return;
  }
  int i, last = 1, tmp;
  for (i = 1; i < n; i++) {
    if (A[i] < A[0]) {
      tmp = A[i];
      A[i] = A[last];
      A[last++] = tmp;
    }
  }
  tmp = A[0];
  A[0] = A[last - 1];
  A[last - 1] = tmp;
  quicksort(A, last - 1);
  quicksort(A + last, n - last);
}

int main() {
  int A[] = {4, 5, 1, 7, 7, 7, 9, 22, 1, -5, -2};
  //  int A[] = {7, 9, 22, 1, -5, -2};
  int size = 11;
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", A[i]);
  }
  quicksort(A, size);
  printf("\nsorted:\n");
  for (i = 0; i < size; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
  return 0;
}
