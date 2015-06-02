#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void dfs(int n, vector<int> cur, vector<vector<string> >& result) {
  int size = cur.size();
  if (size == n) {
    string line(n, '.');
    vector<string> board(n, line);
    for (int i = 0; i < n; i++) board[i][cur[i]] = 'Q';
    result.push_back(board);
    return;
  }
  for (int i = 0; i < n; i++) {
    if (find(cur.begin(), cur.end(), i) != cur.end()) //col not conflict
      continue;
    bool conflict = false;
    //    cout << "a";
    for (int j = 0; j < cur.size(); j++)
      if ((j - cur[j] == size - i) || (j + cur[j] == size + i)) {
        conflict = true;
        break; //diagonal conflict
      }
    if (!conflict) {
      cur.push_back(i);
      dfs(n, cur, result);
      cur.pop_back();
    }
  }
}

vector<vector<string> > solveNQueens(int n) {
  vector<vector<string> >result;
  vector<int> cur;
  dfs(n, cur, result);
  //  cout << result.size();
  return result;
}

int main() {
  vector<vector<string> > result = solveNQueens(5);
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++)
      cout << result[i][j] << endl;
    cout << endl;
  }
}
