#include <iostream>

int LIS(int* A, int n) {
  int* LIS = new int[n];
  for (int i = 0; i < n; i++) {
    LIS[i] = 1;
    for (int j = 0; j < i; j++) {
      if (A[j] < A[i] && LIS[j] + 1 > LIS[i]) {
        LIS[i] = LIS[j] + 1;
      }
    }
  }
  return LIS[n - 1];
}

int main() {
  int A[8] = {1, -1, 2, -3, 4, -5, 6, 7};
  int res = LIS(A, 8);
  std::cout << "res: " << res << std::endl;
  return 0;
}
