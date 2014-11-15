#include <iostream>

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

void Test() {
  int mat[1][1] = {4};
  std::cout << FindInMatrix((int*)mat, 1, 1, 4) << std::endl;
}

void Test1() {
  int mat[1][1] = {2};
  std::cout << FindInMatrix((int*)mat, 1, 1, 4) << std::endl;
}

void Test2() {
  int mat[4][4] = {{3, 5, 7, 9}, {4, 6, 10, 12}, {8, 9, 11, 15}, {10, 11, 13, 20}};
  std::cout << FindInMatrix((int*)mat, 4, 4, 22) << std::endl;
}


void Test3() {
  int mat[2][2] = {{1, 2}, {3, 4}};
  std::cout << FindInMatrix((int*)mat, 2, 2, 9) << std::endl;
}

void Test4() {
  std::cout << FindInMatrix(NULL, 1, 1, 4) << std::endl;
}


int main() {
  Test();
  Test1();
  Test2();
  Test3();
  Test4();
  return 0;
}
