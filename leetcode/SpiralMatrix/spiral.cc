#include <vector>
#include <iostream>

using namespace std;

vector<int> spiralOrder(vector<vector<int> >& matrix) {
  vector<int> result;
  int rows = matrix.size();
  int cols = matrix[0].size();
  for (int i = 0; i < rows - 1 || i < cols - 1; i++) {
    for ( int a = i; a < cols - i - 1; a++)
      result.push_back(matrix[i][a]);
    for (int b = i; b < rows - 1 - i; b++)
      result.push_back(matrix[b][cols - 1 - i]);
    for (int c = cols - 1 - i; c > i; c--)
      result.push_back(matrix[rows - 1 - i][c]);
    for (int d = rows - 1 - i; d > i; d--)
      result.push_back(matrix[d][i]);
  }
  if (rows == cols && rows % 2 == 1)
    result.push_back(matrix[rows / 2][cols / 2]);
  return result;
}

int main() {
  int a[] = {1,2,3};
  int b[] = {4,5,6};
  int c[] = {7,8,9};
  vector<int> av(a, a + 3);
  vector<int> bv(b, b + 3);
  vector<int> cv(c, c + 3);

  vector<vector<int> > vv;
  vv.push_back(av);
  //  vv.push_back(bv);
  //  vv.push_back(cv);


  vector<int> res = spiralOrder(vv);
  for (int i = 0; i < res.size(); i++)
    cout << res[i] << ", ";
  cout << endl;
}
