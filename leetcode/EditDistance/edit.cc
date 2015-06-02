#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int minDistance(string word1, string word2) {
  if (word1.size() == 0) return word2.size();
  if (word2.size() == 0) return word1.size();
  const int m = word1.size();
  const int n = word2.size();
  int f[m + 1][n + 1];
  for (int i = 0; i <= m; i++)
    f[i][0] = i;
  for (int j = 0; j <= n; j++)
    f[0][j] = j;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (word1[i - 1] == word2[j - 1]) {
        f[i][j] = f[i - 1][j - 1];
      }
      else {
        int res = min(f[i - 1][j], f[i][j - 1]);
        f[i][j] = min(res, f[i - 1][j - 1]) + 1;
      }
    }
  }
  return f[m][n];
}

int main() {
  cout << minDistance("a", "b") << endl;
}
