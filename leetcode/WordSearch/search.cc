#include <vector>
#include <iostream>
using namespace std;

bool dfs(vector<vector<char> >& board, vector<vector<bool> >& visited, string word, int m, int n, int index) {
  if (index == word.size()) return true;
  if (m < 0 || n < 0 || m >= board.size() || n >= board[0].size()) return false;
  if (visited[m][n]) return false;
  if (word[index] != board[m][n]) return false;
  visited[m][n] = true;
  bool ret = dfs(board, visited, word, m - 1, n, index + 1) ||
             dfs(board, visited, word, m + 1, n, index + 1) ||
             dfs(board, visited, word, m, n - 1, index + 1) ||
             dfs(board, visited, word, m, n + 1, index + 1);
  visited[m][n] = false;
  return ret;
}

bool exist(vector<vector<char> >& board, string word) {
  int m = board.size();
  if (m == 0) return false;
  int n = board[0].size();
  if (n == 0) return false;
  vector<vector<bool> > visited(m, vector<bool>(n, false));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (dfs(board, visited, word, i, j, 0))
        return true;
    }
  }
  return false;
}

int main() {

}
