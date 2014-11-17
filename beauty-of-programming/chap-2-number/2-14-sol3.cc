#include <iostream>
#include <algorithm>

int maxSum(int* A, int n) {
  //check;
  int i, nStart, nAll;
  nStart = A[n - 1];
  nAll = A[n - 1];
  for (i = n - 2; i >= 0; i--) {
    nStart = std::max(A[i], A[i] + nStart);
    nAll = std::max(nStart, nAll);
  }
  return nAll;
}

int main() {
  //  int A[6] = {1, -2, 3, 5, -3, 2};
  int A[6] = {0, -2, 3, 5, -1 ,2};
  //  int A[6] = {-9, -2 ,-3, -5, -3, -4};
  int sum = maxSum(A, 6);
  std::cout << "sum: " << sum << std::endl;
  return 0;
}
