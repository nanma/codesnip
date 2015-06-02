#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void dfs(int n, vector<int> cur, int& cnt) {
  int size = cur.size();
  if (size == n) {
    cnt++;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (find(cur.begin(), cur.end(), i) != cur.end()) //col not conflict
      continue;
    bool conflict = false;
    for (int j = 0; j < cur.size(); j++)
      if ((j - cur[j] == size - i) || (j + cur[j] == size + i)) {
        conflict = true;
        break; //diagonal conflict
      }
    if (!conflict) {
      cur.push_back(i);
      dfs(n, cur, cnt);
      cur.pop_back();
    }
  }
}

int totalNQueens(int n) {
  vector<int> cur;
  int cnt = 0;
  dfs(n, cur, cnt);
  //  cout << result.size();
  return cnt;
}

int main() {
  int cnt = totalNQueens(4);
  cout << cnt << endl;
}
