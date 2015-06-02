#include <vector>
#include <iostream>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
  int m = obstacleGrid.size();
  if (m == 0) return 0;
  int n = obstacleGrid[0].size();
  if (n == 0) return 0;
  cout << "a" << endl;
  vector<vector<int> > f(m, vector<int>(n));
  if (obstacleGrid[0][0] == 0)
    f[0][0] = 1;
  for(int i = 1; i < n; i++) {
      if (obstacleGrid[0][i] == 0 && f[0][i - 1])
        f[0][i] = 1;
  }
  cout << "b" << endl;
  for(int i = 1; i < m; i++)
      if (obstacleGrid[i][0] == 0 && f[i - 1][0])
        f[i][0] = 1;
  for(int i = 1; i < m; i++)
    for(int j = 1; j < n; j++)
        if(obstacleGrid[i][j] == 0)
          f[i][j] = f[i-1][j] + f[i][j-1];
  return f[m-1][n-1];
}

int main() {
  vector<int> a(1, 0);
  vector<vector<int> > v(1, a);
  cout << uniquePathsWithObstacles(v) << endl;
}
