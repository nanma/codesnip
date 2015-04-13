#include <iostream>

class Solution {
 public:
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int *C = new int[m + n];
    int i, a = 0, b = 0;
    for (i = 0; i < m + n && a < m && b < n; i++) {
      if (A[a] < B[b]) {
        C[i] = A[a++];
      } else {
        C[i] = B[b++];
      }
    }
    while (a < m) {
      C[i++] = A[a++];
    }
    while (b < n) {
      C[i++] = B[b++];
    }
    if (i % 2 == 0) {
      return ((double)C[i / 2] + (double)C[i / 2 - 1]) / 2;
    } else {
      return (double)C[i / 2];
    }
  }
};

int main() {
  Solution s;
  int A[2] = {1, 3};
  int B[3] = {2, 4, 5};
  std::cout << s.findMedianSortedArrays(A, 2, B, 3) << std::endl;
}
