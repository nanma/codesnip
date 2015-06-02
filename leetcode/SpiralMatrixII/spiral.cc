#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generateMatrix(int n) {
  vector<vector<int> > matrix(n, vector<int>(n));
  int begin = 0, end = n - 1;
  int num = 1;
  while (begin < end) {
    for (int j = begin; j < end; j++) matrix[begin][j] = num++;
    for (int i = begin; i < end; i++) matrix[i][end] = num++;
    for (int j = end; j > begin; j--) matrix[end][j] = num++;
    for (int i = end; i > begin; i--) matrix[i][begin] = num++;
    begin++;
    end--;
  }
  if (begin == end) matrix[begin][end] = num;
  return matrix;
}
