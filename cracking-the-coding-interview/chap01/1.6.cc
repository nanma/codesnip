#include <iostream>
#include <cstdlib>

void rotate(int **array, int n) {
  if (array == NULL || n <= 1) {
    return;
  }

  for ( int curSize = n; curSize > 1; curSize -= 2) {
    for (int ind = 0; ind < curSize - 1; ind++) {
      int curCircle = (n - curSize) / 2;
      int tmp = array[curCircle][ind + curCircle];  //top
      array[curCircle][ind + curCircle] =
          array[n - 1 - curCircle + ind][curCircle]; //left
      array[n - 1 - curCircle + ind][curCircle] =
          array[n - 1 - curCircle][n - 1 - curCircle - ind]; //bottom;
      array[n - 1 - curCircle][n - 1 - curCircle - ind] =
          array[curCircle + ind][n - 1 -curCircle];  //right
      array[curCircle + ind][n - 1 -curCircle] = tmp;
    }
  }
}

void prtMat(int **mat, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << mat[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int main() {
  int ab[2][2] = {{1, 2}, {4, 3}};
  int **c = (int **)ab;
  std::cout << &ab[0][0] << ", " << ab[0] << std::endl;
  std::cout << c[0] << std::endl;

  int **a = (int **) malloc(sizeof(int *) * 2);
  int **tmp = a;
  *tmp++ = (int *) malloc(sizeof(int) * 2);
  *tmp = (int *) malloc(sizeof(int) * 2);
  a[0][0] = 1;
  a[0][1] = 2;
  a[1][0] = 4;
  a[1][1] = 3;
//   prtMat((int **)ab, 2);
//   rotate((int**)ab, 2);
//   prtMat((int **)ab, 2);
}
