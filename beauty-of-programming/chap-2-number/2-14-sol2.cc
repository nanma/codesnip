#include <iostream>
#include <climits>
#include <algorithm>

int maxSum(int* A, int n) {
  if (A == NULL || n == 0) {
      return 0; //TODO: throw exception
    }
  if (n == 1) {
    return A[0];
  }
  int leftChild = maxSum(A, n / 2);
  int rightChild = maxSum(A + n / 2 , n / 2);
  int i, maxLeft = INT_MIN, maxRight = INT_MIN, sum = 0;
  for (i = n / 2 - 1; i >= 0; i--) {
    sum += A[i];
    if (sum > maxLeft) {
      maxLeft = sum;
    }
  }
  sum = 0;
  for (i = n / 2; i < n; i++) {
    sum += A[i];
    if (sum > maxRight) {
      maxRight = sum;
    }
  }
  sum = maxLeft + maxRight;
  int result = std::max(leftChild, rightChild);
  result = std::max(result, sum);
  return result;
}

int main() {
  //  int A[6] = {1, -2, 3, 5, -3, 2};
  //  int A[6] = {0, -2, 3, 5, -1 ,2};
  int A[6] = {-9, -2 ,-3, -5, -3};
  int sum = maxSum(A, 6);
  std::cout << "sum: " << sum << std::endl;
  return 0;
}
