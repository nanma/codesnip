#include <iostream>

using namespace std;

int uniquePaths(int m, int n) {
  if (m <= || n <= 1) return 1;
  int **A = new int *[m + 1];
  for (int i = 0; i < m + 1; i++) {
    A[i] = new int[n + 1];
  }
  fill(*A, *A + (m + 1) * (n + 1), 0);
  A[0][1] = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      A[i][j] = A[i - 1][j] + A[i][j - 1];
    }
  }
  return A[m][n];
}

int main() {
  cout << uniquePaths(2, 9) << endl;
}
