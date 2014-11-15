#include <iostream>
#include <cstdio>

using namespace std;

bool FindInMatrix(int* mat, int rows, int cols, int num) {
  if (mat == NULL || rows < 0 || cols < 0) {
    return false;
  }
  int i = 0, j = cols - 1;
  while (i < rows && j >= 0) {
    if (*(mat + i * cols + j) == num) {
      return true;
    } else if (*(mat + i * cols + j) > num) {
      j--;
    } else {
      i++;
    }
  }
  return false;
}

int main() {
  int row = 0, col = 0;
  int num = 0;
  //  while (cin >> row >> col >> num) {
  while(scanf("%d%d%d", &row, &col, &num)!=EOF) {
    int size = row * col;
    int* matrix = new int[size];
    for (int i = 0; i < size; ++i) {
      //cin >> matrix[i];
      scanf("%d", &matrix[i]);
    }
    bool isFind = FindInMatrix(matrix, row, col, num);
    if (isFind) {
      printf("Yes\n");
      //cout << "Yes" << endl;
    } else {
      printf("No\n");
      //cout << "No" << endl;
    }
    delete [] matrix;
  }
  return 0;
}
